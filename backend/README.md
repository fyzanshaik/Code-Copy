# Backend Golang Application

## Overview

This project is a backend server implemented in Go using the Gin framework. It provides several endpoints for managing and accessing code files, retrieving metadata, handling cache, and collecting metrics. It integrates with Redis for caching purposes.

## Installation

### Prerequisites

- Go (1.18+)
- Redis server (installed and running on `localhost:6379`)

### Setup

1. **Clone the repository:**

    ```sh
    git clone <repository-url>
    cd <repository-directory>
    ```

2. **Install dependencies:**

    ```sh
    go mod tidy
    ```

3. **Run Redis:**

   Ensure Redis is running on `localhost:6379`. You can download and start Redis from the [official Redis website](https://redis.io/download).

4. **Run the server:**

    ```sh
    go run main.go
    ```

## API Endpoints

### 1. Retrieve a Code File

- **Endpoint:** `GET /api/v1/program/:year/:semester/:class/:course/:filename`
- **Description:** Retrieve a code file from the file system or cache.
  
### 2. Download a Code File

- **Endpoint:** `GET /api/v1/download/:year/:semester/:class/:course/:filename`
- **Description:** Download a code file.

### 3. Handle Directory Structure

- **Endpoint:** `GET /api/v1/structure`
- **Description:** Retrieve the directory structure.

### 4. Retrieve List of Years

- **Endpoint:** `GET /api/v1/years`
- **Description:** Retrieve a list of years.

### 5. Retrieve List of Semesters

- **Endpoint:** `GET /api/v1/years/semesters`
- **Description:** Retrieve a list of semesters.

### 6. Handle Metadata

- **Endpoint:** `GET /api/v1/:year/:semester/:class/:course/:filename`
- **Description:** Retrieve metadata for a given code file.

### 7. Retrieve Courses

- **Endpoint:** `GET /api/v1/course/:year/:semester/:class`
- **Description:** Retrieve a list of courses.

### 8. Retrieve Programs

- **Endpoint:** `GET /api/v1/programs/:year/:semester/:class/:course`
- **Description:** Retrieve a list of programs.

### 9. Retrieve Metadata (Alternative)

- **Endpoint:** `GET /api/v1/metadata/:year/:semester/:class/:course/:filename`
- **Description:** Retrieve metadata for a given code file.

### 10. Retrieve Cache Status

- **Endpoint:** `GET /api/v1/cache-status`
- **Description:** Retrieve the status of the cache.

### 11. Clear Cache

- **Endpoint:** `POST /api/v1/clear-cache`
- **Description:** Clear the cache.

### 12. Health Check

- **Endpoint:** `GET /health`
- **Description:** Check the health of the server.

### 13. Metrics

- **Endpoint:** `GET /metrics`
- **Description:** Retrieve server metrics.

### 14. Version Information

- **Endpoint:** `GET /api/v1/version`
- **Description:** Retrieve version information of the server.

## Build Commands

### Build for Windows

```sh
GOOS=windows GOARCH=amd64 go build -o server.exe main.go
```

### Build for Linux

```sh
GOOS=linux GOARCH=amd64 go build -o server main.go
```

### Build for macOS

```sh
GOOS=darwin GOARCH=amd64 go build -o server main.go
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

