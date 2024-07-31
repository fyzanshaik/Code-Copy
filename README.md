# Project README 🚀

## Overview 🌟

This project consists of two main components:

1. **Backend**: A Go-based server that provides API endpoints for accessing program files, metadata, and cache management. 🏗️
2. **Frontend**: A React and TypeScript application that displays a hierarchical sidebar for navigating classes, semesters, years, courses, and program files. The frontend also features a code editor
   for viewing and editing file contents with syntax highlighting. 🖥️✍️

## Backend 🏗️

### Description

The backend is implemented using Go with the Gin web framework and Redis for caching. It provides various API endpoints for retrieving and managing code files, metadata, and cache status.

### API Endpoints 📡

-  `GET /api/v1/program/:year/:semester/:class/:course/:filename`: Retrieve a code file.
-  `GET /api/v1/download/:year/:semester/:class/:course/:filename`: Download a code file.
-  `GET /api/v1/structure`: Retrieve directory structure.
-  `GET /api/v1/years`: Retrieve list of years.
-  `GET /api/v1/years/semesters`: Retrieve list of semesters.
-  `GET /api/v1/:year/:semester/:class/:course/:filename`: Handle metadata.
-  `GET /api/v1/course/:year/:semester/:class`: Retrieve courses.
-  `GET /api/v1/programs/:year/:semester/:class/:course`: Retrieve programs.
-  `GET /api/v1/metadata/:year/:semester/:class/:course/:filename`: Retrieve metadata.
-  `GET /api/v1/cache-status`: Retrieve cache status.
-  `POST /api/v1/clear-cache`: Clear the cache.
-  `GET /health`: Health check.
-  `GET /metrics`: Retrieve metrics.
-  `GET /api/v1/version`: Retrieve version information.

### Installation and Setup 🛠️

1. **Clone the repository:**

   ```sh
   git clone <repository-url>
   cd <repository-directory>
   ```

2. **Install Go and Redis:**

   -  [Install Go](https://golang.org/doc/install)
   -  [Install Redis](https://redis.io/download)

3. **Install Go dependencies:**

   ```sh
   cd backend
   go mod tidy
   ```

4. **Run the server:**

   ```sh
   go run main.go
   ```

5. **Ensure Redis is running:**
   ```sh
   redis-server
   ```

### Build Commands ⚙️

To build the backend for different operating systems:

-  **Windows:**

   ```sh
   GOOS=windows GOARCH=amd64 go build -o backend.exe
   ```

-  **Linux:**

   ```sh
   GOOS=linux GOARCH=amd64 go build -o backend
   ```

-  **MacOS:**
   ```sh
   GOOS=darwin GOARCH=amd64 go build -o backend
   ```

## Frontend 🖥️

### Description

The frontend is implemented using React with TypeScript, Vite, and Tailwind CSS. It includes a sidebar for navigating the hierarchical structure and a code editor for viewing and editing code files.

### Setup 🛠️

1. **Navigate to the frontend directory:**

   ```sh
   cd frontend
   ```

2. **Install Node.js dependencies:**

   ```sh
   npm install
   ```

3. **Start the development server:**
   ```sh
   npm run dev
   ```

### Project Structure 📁

-  **`src/components/Sidebar.tsx`**: Contains the sidebar component for displaying the hierarchy.
-  **`src/components/CodeEditor.tsx`**: Contains the code editor component with syntax highlighting.
-  **`src/api/requests.ts`**: Contains functions for making API requests to the backend.

### Development 🔨

-  Use [Vite](https://vitejs.dev/) for development and build tasks.
-  [Tailwind CSS](https://tailwindcss.com/) is used for styling.
-  [React Router](https://reactrouter.com/) is used for routing.
-  [Axios](https://axios-http.com/) is used for making HTTP requests.

---
