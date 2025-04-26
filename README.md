# Simple Webserver in C

This is a simple webserver implemented in C. It listens on port 8080 and serves a basic HTML page with a "Hello, World!" message.

## Features

- Serves a static HTML page.
- Handles HTTP GET requests.
- Demonstrates basic socket programming in C.

## Project Structure

. ├── webserver.c # Source code for the webserver

## How It Works

1. The server creates a socket and binds it to port 8080.
2. It listens for incoming connections.
3. When a client connects, the server reads the HTTP request and responds with a static HTML page.
4. The connection is then closed.

## Prerequisites

- GCC (GNU Compiler Collection) or any C compiler.
- A Linux-based operating system (or WSL on Windows) for socket programming.

## How to Build and Run

1. Compile the program using GCC:
   ```bash
   gcc -o webserver webserver.c

2. Run the compiled program:
    ```bash
    ./webserver

3. Open a web browser and navigate to http://localhost:8080.

# Example Output
When the server is running, you will see:

Webserver started. Listening on port 8080...
Connection accepted
Received message: GET / HTTP/1.1

In the browser, you will see a simple HTML page with the following content:

```html 
<html>
<head><title>Webserver C</title></head>
<body>
    <h1>Hello, World!</h1>
    <p>This is a page created with C</p>
</body>
</html>
``` 

# Notes

This is a basic example for educational purposes and is not suitable for production use.
It does not handle multiple connections concurrently.
Error handling is minimal.

# License

This project is licensed under the MIT License. Feel free to use and modify it as needed.
