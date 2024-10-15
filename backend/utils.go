package main

import (
	"fmt"
	"log"
	"os"
	"path/filepath"
	"time"

	"github.com/gin-gonic/gin"
)

func filePathHelper(c *gin.Context) (path string) {
	year := c.Param("year")
	semester := c.Param("semester")
	branch := c.Param("class")
	courseName := c.Param("course")
	fileName := c.Param("filename")
	// fmt.Println("Branch: ", branch)
	// fmt.Println(year, semester, branch, courseName, fileName)

	path = fmt.Sprintf("./files/%s/%s/%s/%s/%s", year, semester, branch, courseName, fileName)

	return path
}

func errorHandler(err error) {
	if err != nil {
		log.Fatalf("Error reading file: %v", err)
	}
}

func getDirectoryStructure(directory string) ([]*Entry, error) {
	var entries []*Entry

	files, err := os.ReadDir(directory)
	if err != nil {
		return nil, err
	}

	for _, file := range files {
		entry := &Entry{
			Name: file.Name(),
		}

		fileInfo, err := file.Info()
		if err != nil {
			return nil, err
		}

		entry.Size = fileInfo.Size()

		if file.IsDir() {
			entry.Type = "directory"
			subEntries, err := getDirectoryStructure(filepath.Join(directory, file.Name()))
			if err != nil {
				return nil, err
			}
			entry.Children = subEntries
		} else {
			entry.Type = "file"
		}

		entries = append(entries, entry)
	}

	return entries, nil
}

func getCourses(c *gin.Context) ([]string, error) {
	var entries []string
	year := c.Param("year")
	semester := c.Param("semester")
	class := c.Param("class")
	directoryPath := fmt.Sprintf("files/%s/%s/%s", year, semester, class)
	files, err := os.ReadDir(directoryPath)
	if err != nil {
		return nil, err
	}
	for _, file := range files {
		folderName := file.Name()
		entries = append(entries, folderName)
	}

	return entries, nil
}

func getProgramNames(c *gin.Context) ([]string, error) {
	var entries []string
	year := c.Param("year")
	semester := c.Param("semester")
	class := c.Param("class")
	courseName := c.Param("course")
	directoryPath := fmt.Sprintf("files/%s/%s/%s/%s", year, semester, class, courseName)
	files, err := os.ReadDir(directoryPath)
	if err != nil {
		return nil, err
	}
	for _, file := range files {
		folderName := file.Name()
		entries = append(entries, folderName)
	}
	return entries, nil
}

type MetaData struct {
	Name         string
	Size         float64
	ModifiedDate time.Time
}

func getMetaData(c *gin.Context) (MetaData, error) {
	year := c.Param("year")
	semester := c.Param("semester")
	class := c.Param("class")
	courseName := c.Param("course")
	fileName := c.Param("filename")
	directoryPath := fmt.Sprintf("files/%s/%s/%s/%s/%s", year, semester, class, courseName, fileName)
	fmt.Println(directoryPath)
	file, err := os.Stat(directoryPath)
	if err != nil {
		return MetaData{}, err
	}

	fileData := MetaData{
		Name:         file.Name(),
		Size:         float64(file.Size()) * 0.001,
		ModifiedDate: file.ModTime(),
	}

	return fileData, nil
}
