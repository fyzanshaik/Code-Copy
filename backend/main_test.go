package main

import (
	"context"
	"encoding/json"
	"fmt"
	"net/http"
	"net/http/httptest"
	"os"
	"sync"
	"testing"
	"time"

	"github.com/gin-gonic/gin"
	"github.com/go-redis/redis/v8"
	"github.com/stretchr/testify/assert"
)

var testRouter *gin.Engine
var testRedisClient *redis.Client

func setupRouter() *gin.Engine {
	router := gin.Default()
	initRedis()
	router.Use(rateLimiter())
	router.Use(metricsMiddleware())
	router.GET("/api/v1/program/:year/:semester/:class/:course/:filename", getCodeFile)
	router.GET("/api/v1/download/:year/:semester/:class/:course/:filename", downloadCodeFile)
	router.GET("/api/v1/structure", handleDirectoryStructure)
	router.GET("/api/v1/years", handleYears)
	router.GET("/api/v1/years/semesters", handleSems)
	router.GET("/api/v1/course/:year/:semester/:class", handleCourses)
	router.GET("/api/v1/programs/:year/:semester/:class/:course", handlePrograms)
	router.GET("/api/v1metadata/:year/:semester/:class/:course/:filename", handleMetaData)
	router.GET("/api/v1/cache-status", getCacheStatus)
	router.POST("/api/v1/clear-cache", clearCache)
	router.GET("/health", getHealth)
	router.GET("/metrics", getMetrics)
	router.GET("/api/v1/version", getVersion)
	return router
}

func init() {
	gin.SetMode(gin.TestMode)
	testRouter = setupRouter()
	testRedisClient = redis.NewClient(&redis.Options{
		Addr: "localhost:6379",
	})
}

func TestGetCodeFile(t *testing.T) {
	w := performRequest(testRouter, "GET", "/api/v1/program/1/2/CSM/DSS/linearsearch.c")
	assert.Equal(t, http.StatusOK, w.Code)

	var response map[string]interface{}
	err := json.Unmarshal(w.Body.Bytes(), &response)
	assert.NoError(t, err)
	assert.Equal(t, "From File System", response["Intro"])

	w = performRequest(testRouter, "GET", "/api/v1/program/1/2/CSM/DSS/linearsearch.c")
	assert.Equal(t, http.StatusOK, w.Code)

	err = json.Unmarshal(w.Body.Bytes(), &response)
	assert.NoError(t, err)
	assert.Equal(t, "From Cache", response["Intro"])
}

func TestConcurrentRequests(t *testing.T) {
	var wg sync.WaitGroup
	requestCount := 10

	for i := 0; i < requestCount; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			w := performRequest(testRouter, "GET", "/api/v1/program/1/2/CSM/DSS/linearsearch.c")
			assert.Equal(t, http.StatusOK, w.Code)
		}()
	}

	wg.Wait()

	ctx := context.Background()
	keyName := "code:1:1:CS:ProgrammingFundamentals:hello.py"
	accessCount, err := testRedisClient.Get(ctx, keyName+":access_count").Int()
	assert.NoError(t, err)
	assert.Equal(t, requestCount, accessCount)
}

func TestRateLimiting(t *testing.T) {
	for i := 0; i < 11; i++ {
		w := performRequest(testRouter, "GET", "/api/v1/version")
		if i < 10 {
			assert.Equal(t, http.StatusOK, w.Code)
		} else {
			assert.Equal(t, http.StatusTooManyRequests, w.Code)
		}
	}
}

func TestAllEndpoints(t *testing.T) {
	endpoints := []struct {
		method string
		path   string
	}{
		{"GET", "/api/v1/structure"},
		{"GET", "/api/v1/years"},
		{"GET", "/api/v1/years/semesters"},
		{"GET", "/api/v1/course/1/1/CS"},
		{"GET", "/api/v1/program/1/2/CSM/DSS/"},
		{"GET", "/api/v1/program/1/2/CSM/DSS/linearsearch.c"},
		{"GET", "/api/v1/cache-status"},
		{"GET", "/health"},
		{"GET", "/metrics"},
		{"GET", "/api/v1/version"},
	}

	for _, endpoint := range endpoints {
		t.Run(endpoint.path, func(t *testing.T) {
			w := performRequest(testRouter, endpoint.method, endpoint.path)
			assert.Equal(t, http.StatusOK, w.Code)
		})
	}
}

func TestPerformance(t *testing.T) {
	endpoints := []string{
		"/api/v1/program/1/2/CSM/DSS/linearsearch.c",
		"/api/v1/structure",
		"/api/v1/version",
	}

	for _, endpoint := range endpoints {
		t.Run(endpoint, func(t *testing.T) {
			start := time.Now()
			w := performRequest(testRouter, "GET", endpoint)
			duration := time.Since(start)

			assert.Equal(t, http.StatusOK, w.Code)
			t.Logf("Response time for %s: %v", endpoint, duration)
		})
	}
}

func performRequest(r http.Handler, method, path string) *httptest.ResponseRecorder {
	req, _ := http.NewRequest(method, path, nil)
	w := httptest.NewRecorder()
	r.ServeHTTP(w, req)
	return w
}

func resetRedis(t *testing.T) {
	if t == nil {
		t = &testing.T{} // or handle the nil case appropriately
	}
	err := testRedisClient.FlushAll(context.Background()).Err()
	assert.NoError(t, err)
}

func TestMain(m *testing.M) {
	fmt.Println("Setting up tests...")
	resetRedis(&testing.T{}) // pass a valid *testing.T

	exitCode := m.Run()

	fmt.Println("Cleaning up after tests...")
	testRedisClient.Close()

	os.Exit(exitCode)
}
