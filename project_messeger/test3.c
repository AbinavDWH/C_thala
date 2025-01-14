#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

// Function to broadcast messages to all clients
void broadcast_message(const char *message, int sender_socket) {
    pthread_mutex_lock(&lock);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] != 0 && client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&lock);
}

// Function to handle communication with a client
void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];
    int bytes_received;

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            printf("Client disconnected.\n");
            close(client_socket);

            // Remove client from the list
            pthread_mutex_lock(&lock);
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == client_socket) {
                    client_sockets[i] = 0;
                    break;
                }
            }
            pthread_mutex_unlock(&lock);

            pthread_exit(NULL);
        }

        printf("Received message: %s\n", buffer);
        broadcast_message(buffer, client_socket);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    pthread_t thread_id;

    // Initialize client sockets
    memset(client_sockets, 0, sizeof(client_sockets));

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is bound to port %d\n", PORT);

    // Start listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Add the new client socket to the list
        pthread_mutex_lock(&lock);
        int added = 0;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                added = 1;
                break;
            }
        }
        pthread_mutex_unlock(&lock);

        if (!added) {
            printf("Max clients reached. Connection rejected.\n");
            close(client_socket);
            continue;
        }

        // Create a new thread for the client
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}
