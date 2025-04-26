#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_LEN 1024

int main (){
    int server_fd, client_fd;
    struct sockaddr_in address, client_addr;
    int addrlen = sizeof(address);
    char buffer[BUFFER_LEN] = {0};
    const char* html_body = "<html><head><title>Webserver C</title></head>"
        "<body><h1>Hello, World!</h1><p>This is a page created with C</p></body></html>";
    
    char html_response[BUFFER_LEN];
    snprintf(html_response, sizeof(html_response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %zu\r\n"
        "\r\n"
        "%s", strlen(html_body), html_body);

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Any address
    address.sin_port = htons(PORT); // Port

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Webserver started. Listening on port %d...\n", PORT);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        printf("Connection accepted\n");

        int byteCount = read(client_fd, buffer, sizeof(buffer));
        
        if (byteCount > 0) {
            printf("Received message: %s\n", buffer);
        }

        write(client_fd, html_response, strlen(html_response));
        close(client_fd);
    }
    close(server_fd);
    printf("Server closed\n");
    // Free resources and close sockets
    // Note: In a real-world application, you would also want to handle errors and clean up resources properly.
    // For example, you might want to use a loop to accept multiple connections
    // and handle each connection in a separate thread or process.
    // This is a simple example and does not include error handling for brevity.
    // In a production server, you would also want to handle signals to gracefully shut down the server.
    // Additionally, you might want to implement proper logging and security measures.
    // This example is for educational purposes only and should not be used in a production environment.
    // Always remember to check for errors when using system calls and handle them appropriately.
    // For example, you might want to check the return value of bind(), listen(), accept(), read(), and write()
    // to ensure that they succeed. If any of these calls fail, you should handle the error gracefully
    // and clean up any resources that were allocated.
    return 0;
}