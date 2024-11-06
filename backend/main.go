package main

import (
	"log"
	"net/http"
	"os"
	"sync"
	"time"

	"github.com/gin-gonic/gin"
	"github.com/go-redis/redis/v8"
	"golang.org/x/time/rate"
)

var redisClient *redis.Client

func initRedis() {

	redisUrlAddress := "localhost:6173"

	redisClient = redis.NewClient(&redis.Options{
		Addr: redisUrlAddress,
	})
}

func rateLimiter() gin.HandlerFunc {
	limiter := rate.NewLimiter(rate.Every(time.Second), 1000)
	return func(ctx *gin.Context) {
		if !limiter.Allow() {
			ctx.JSON(http.StatusTooManyRequests, gin.H{"error": "Rate limit exceeded"})
			ctx.Abort()
			return
		}
		ctx.Next()
	}
}

var metrics = struct {
	sync.RWMutex
	requestCount      int64
	errorCount        int64
	lastResetTime     time.Time
	avgResponseTime   time.Duration
	totalResponseTime time.Duration
}{lastResetTime: time.Now()}

func incrementRequestCount() {
	metrics.Lock()
	defer metrics.Unlock()
	metrics.requestCount++
}

func incrementErrorCount() {
	metrics.Lock()
	defer metrics.Unlock()
	metrics.errorCount++
}

func recordResponseTime(duration time.Duration) {
	metrics.Lock()
	defer metrics.Unlock()
	metrics.totalResponseTime += duration
	metrics.avgResponseTime = time.Duration(int64(metrics.totalResponseTime) / metrics.requestCount)
}
func metricsMiddleware() gin.HandlerFunc {
	return func(c *gin.Context) {
		start := time.Now()

		c.Next()

		duration := time.Since(start)
		incrementRequestCount()
		recordResponseTime(duration)

		if c.Writer.Status() >= 400 {
			incrementErrorCount()
		}
	}
}
func main() {
	gin.SetMode(gin.ReleaseMode)
	router := gin.Default()
	initRedis()
	router.Use(rateLimiter())
	router.Use(metricsMiddleware())
	router.GET("/program/:year/:semester/:class/:course/:filename", getCodeFile)
	router.GET("/download/:year/:semester/:class/:course/:filename", downloadCodeFile)
	router.GET("/structure", handleDirectoryStructure)
	router.GET("/years", handleYears)
	router.GET("/years/semesters", handleSems)
	router.GET("/:year/:semester/:class/:course/:filename", handleMetaData)
	router.GET("/course/:year/:semester/:class", handleCourses)
	router.GET("/programs/:year/:semester/:class/:course", handlePrograms)
	router.GET("/metadata/:year/:semester/:class/:course/:filename", handleMetaData)
	router.GET("/cache-status", getCacheStatus)
	router.POST("/clear-cache", clearCache)
	router.GET("/health", getHealth)
	router.GET("/metrics", getMetrics)
	router.GET("/version", getVersion)

	port := os.Getenv("PORT")
	if port == "" {
		port = "8080"
	}
	if err := router.Run(":" + port); err != nil {
		log.Panicf("error: %s", err)
	}

	log.Println("Server started running on :" + port)

	router.SetTrustedProxies(nil)
	if err := router.Run(":" + port); err != nil {
		log.Panicf("error: %s", err)
	}
}
