#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080  // The incoming port to listen on

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    char buffer[1024] = {0};

    // 1. Create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // 2. Bind the socket to an IP and Port
    server_addr.sin_family = AF_INET;           // IPv4
    server_addr.sin_addr.s_addr = INADDR_ANY;   // Listen on all network interfaces
    server_addr.sin_port = htons(PORT);         // Convert port number to network byte order

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is bound to port %d\n", PORT);

    // 3. Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    addr_len = sizeof(client_addr);

    // 4. Accept an incoming connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
    if (client_socket < 0) {
        perror("Connection acceptance failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted from %s:%d\n",
           inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // 5. Communicate with the client
    while(1){
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("Client sent: %s\n", buffer);

    char *response = "Hello, Client!";
    send(client_socket, response, strlen(response), 0);
    }
    // 6. Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
