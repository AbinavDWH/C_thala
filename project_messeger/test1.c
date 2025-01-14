#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "192.168.107.166", &server_addr.sin_addr);  // Replace with server's IP

    connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to server. Type messages below:\n");

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, strlen(buffer), 0);

        memset(buffer, 0, sizeof(buffer));
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("Server: %s\n", buffer);
    }

    close(client_socket);
    return 0;
}
