package main

import (
	"context"
	"fmt"
	"net/http"
	"os"
	"strings"
	"time"

	"github.com/gin-gonic/gin"
)

func getCodeFile(c *gin.Context) {
	cacheKey := fmt.Sprintf("code:%s:%s:%s:%s:%s", c.Param("year"), c.Param("semester"), c.Param("class"), c.Param("course"), c.Param("filename"))
	// fmt.Println("", cacheKey)
	
	cachedData, err := redisClient.Get(context.Background(), cacheKey).Result()
	fmt.Println("Redis error : ", err)
	// fmt.Println("", cachedData)
	if err == nil {
		// fmt.Println("Cached Key: ", cacheKey)
		// fmt.Println("Cached data: ", cachedData)
		c.JSON(http.StatusOK, gin.H{"Data access information": "From Cache", "Data": cachedData})
		return
	}

	filePath := filePathHelper(c)
	// fmt.Println("", filePath)
	data, err := os.ReadFile(filePath)
	if err != nil {
		c.JSON(http.StatusNotFound, gin.H{"error": "File not found"})
		return
	}

	redisClient.Set(context.Background(), cacheKey, string(data), time.Hour)

	c.JSON(http.StatusOK, gin.H{"Intro": "From File System", "Data": string(data)})
}

func downloadCodeFile(c *gin.Context) {
	var filePath string = filePathHelper(c)
	c.File(filePath)
}

type Entry struct {
	Name     string   `json:"name"`
	Type     string   `json:"type"`
	Size     int64    `json:"size"`
	Children []*Entry `json:"children,omitempty"`
}

func handleDirectoryStructure(c *gin.Context) {
	directory := "./files"
	entries, err := getDirectoryStructure(directory)
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"error": err.Error()})
		return
	}

	c.JSON(http.StatusOK, entries)
}

func handleYears(c *gin.Context) {
	c.JSON(http.StatusOK, gin.H{"Years": "4"})
}

func handleSems(c *gin.Context) {
	c.JSON(http.StatusOK, gin.H{"Semesters ": "2"})
}

func handleCourses(c *gin.Context) {

	course, err := getCourses(c)
	errorHandler(err)
	c.JSON(http.StatusOK, gin.H{"Course": course})

}

func handlePrograms(c *gin.Context) {
	programNames, err := getProgramNames(c)
	errorHandler(err)
	c.JSON(http.StatusAccepted, gin.H{"allPrograms": programNames})

}

func handleMetaData(c *gin.Context) {
	information, err := getMetaData(c)
	errorHandler(err)
	c.JSON(http.StatusOK, gin.H{"information": information})
}

func getCacheStatus(c *gin.Context) {
	ctx := context.Background()
	info, err := redisClient.Info(ctx, "memory", "stats").Result()
	if err != nil {
		c.JSON(http.StatusInternalServerError, gin.H{"error": "Failed to get cache status"})
		return
	}

	infoMap := make(map[string]string)
	for _, line := range strings.Split(info, "\r\n") {
		if strings.Contains(line, ":") {
			parts := strings.Split(line, ":")
			infoMap[parts[0]] = parts[1]
		}
	}

	c.JSON(http.StatusOK, gin.H{
		"used_memory":                infoMap["used_memory"],
		"used_memory_human":          infoMap["used_memory_human"],
		"used_memory_peak":           infoMap["used_memory_peak"],
		"used_memory_peak_human":     infoMap["used_memory_peak_human"],
		"total_connections_received": infoMap["total_connections_received"],
		"total_commands_processed":   infoMap["total_commands_processed"],
		"keyspace_hits":              infoMap["keyspace_hits"],
		"keyspace_misses":            infoMap["keyspace_misses"],
	})
}

func getMetrics(c *gin.Context) {
	metrics.RLock()
	defer metrics.RUnlock()

	c.JSON(http.StatusOK, gin.H{
		"total_requests":       metrics.requestCount,
		"error_count":          metrics.errorCount,
		"avg_response_time_ms": metrics.avgResponseTime.Milliseconds(),
		"uptime_seconds":       time.Since(metrics.lastResetTime).Seconds(),
	})
}

func getHealth(c *gin.Context) {
	ctx, cancel := context.WithTimeout(context.Background(), 5*time.Second)
	defer cancel()

	health := gin.H{
		"status": "healthy",
		"components": gin.H{
			"redis":       "up",
			"file_system": "up",
		},
	}

	_, err := redisClient.Ping(ctx).Result()
	if err != nil {
		health["components"].(gin.H)["redis"] = "down"
		health["status"] = "unhealthy"
	}

	_, err = os.Stat("./files")
	if err != nil {
		health["components"].(gin.H)["file_system"] = "down"
		health["status"] = "unhealthy"
	}

	c.JSON(http.StatusOK, health)
}

func clearCache(c *gin.Context) {
	redisClient.FlushAll(context.Background())
	c.JSON(http.StatusOK, gin.H{"message": "Cache cleared"})
}
func getVersion(c *gin.Context) {
	c.JSON(http.StatusOK, gin.H{"version": "1.0.0"})
}
