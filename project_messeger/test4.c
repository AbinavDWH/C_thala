#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
char client_names[MAX_CLIENTS][50];
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
    int client_index = *(int *)arg;
    int client_socket = client_sockets[client_index];
    char buffer[1024];
    char welcome_message[1024];
    int bytes_received;

    // Send a welcome message to the client
    snprintf(welcome_message, sizeof(welcome_message), "Welcome %s!\n", client_names[client_index]);
    send(client_socket, welcome_message, strlen(welcome_message), 0);

    // Notify all other clients about the new connection
    snprintf(buffer, sizeof(buffer), "%shas joined the chat.\n", client_names[client_index]);
    broadcast_message(buffer, client_socket);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            printf("Client %s disconnected.\n", client_names[client_index]);
            close(client_socket);

            // Notify others about the disconnection
            snprintf(buffer, sizeof(buffer), "%s has left the chat.\n", client_names[client_index]);
            broadcast_message(buffer, client_socket);

            // Remove client from the list
            pthread_mutex_lock(&lock);
            client_sockets[client_index] = 0;
            client_names[client_index][0] = '\0';
            pthread_mutex_unlock(&lock);

            pthread_exit(NULL);
        }

        printf("%s:%s\n", client_names[client_index], buffer);

        char message_with_name[1024];
        snprintf(message_with_name, sizeof(message_with_name), "%s:%s", client_names[client_index], buffer);
        broadcast_message(message_with_name, client_socket);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len;
    pthread_t thread_id;

    // Initialize client sockets and names
    memset(client_sockets, 0, sizeof(client_sockets));
    memset(client_names, 0, sizeof(client_names));

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
        int client_index = -1;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = client_socket;
                client_index = i;
                break;
            }
        }
        pthread_mutex_unlock(&lock);

        if (client_index == -1) {
            printf("Max clients reached. Connection rejected.\n");
            close(client_socket);
            continue;
        }

        // Receive the client's name
        char name_buffer[50];
        recv(client_socket, name_buffer, sizeof(name_buffer), 0);
        pthread_mutex_lock(&lock);
        strncpy(client_names[client_index], name_buffer, sizeof(client_names[client_index]) - 1);
        pthread_mutex_unlock(&lock);

        // Create a new thread for the client
        pthread_create(&thread_id, NULL, handle_client, &client_index);
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}
