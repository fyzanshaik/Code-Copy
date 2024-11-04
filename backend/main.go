package main

import (
	"log"
	"net/http"
	"os"
	"sync"
	"time"

	"github.com/gin-gonic/gin"
	"github.com/go-redis/redis/v8"
	"github.com/joho/godotenv"
	"golang.org/x/time/rate"
)

var redisClient *redis.Client

func initRedis() {
	err := godotenv.Load()
	if err != nil {
		log.Fatal("Error loading Env file")
	}

	redisUrlAddress := os.Getenv("REDIS_URL")

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
	if err := godotenv.Load(); err != nil {
		log.Println("Warning: .env file not found, proceeding without it.")
	}

	if os.Getenv("GIN_MODE") == "" {
		gin.SetMode(gin.ReleaseMode)
	}

	PORT := os.Getenv("PORT")
	if PORT == "" {
		PORT = "8080"
	}

	router := gin.Default()
	initRedis()
	router.Use(rateLimiter())
	router.Use(metricsMiddleware())
	router.GET("/api/v1/program/:year/:semester/:class/:course/:filename", getCodeFile)
	router.GET("/api/v1/download/:year/:semester/:class/:course/:filename", downloadCodeFile)
	router.GET("/api/v1/structure", handleDirectoryStructure)
	router.GET("/api/v1/years", handleYears)
	router.GET("/api/v1/years/semesters", handleSems)
	router.GET("/api/v1/:year/:semester/:class/:course/:filename", handleMetaData)
	router.GET("/api/v1/course/:year/:semester/:class", handleCourses)
	router.GET("/api/v1/programs/:year/:semester/:class/:course", handlePrograms)
	router.GET("/api/v1/metadata/:year/:semester/:class/:course/:filename", handleMetaData)
	router.GET("/api/v1/cache-status", getCacheStatus)
	router.POST("/api/v1/clear-cache", clearCache)
	router.GET("/health", getHealth)
	router.GET("/metrics", getMetrics)
	router.GET("/api/v1/version", getVersion)

	log.Println("Server started running on :" + PORT)

	router.SetTrustedProxies(nil)
	router.Run(":" + PORT)
}
