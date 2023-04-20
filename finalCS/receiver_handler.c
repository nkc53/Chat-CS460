#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "receiver_handler.h"

#define MAX_MSG_LEN 1024

// Function to handle incoming messages from clients
static bool handle_message(int client_socket, char *message, size_t message_len) {
    // Parse the message type and handle accordingly
    switch (message[0]) {
        case 'JOIN':
            // Handle JOIN message
            // ...
            break;
        case 'LLEAVE':
            // Handle LEAVE message
            // ...
            break;
        case 'NOTE':
            // Handle NOTE message
            // ...
            break;
        case 'SHUTDOWN':
            // Handle NOTE message
            // ...
            break;            
        case 'SHUTDOWNALL':
            if (message_len >= 11 && strncmp(message, "SHUTDOWNALL", 11) == 0) {
                // Handle SHUTDOWN ALL message
                // ...
                return false; // Return false to terminate server loop
            }
            break;
        default:
            // Handle unknown message type
            // ...
            break;
    }

    return true; // Return true to continue server loop
}

// Function to handle a connected client
bool handle_client(int client_socket) {
    char message[MAX_MSG_LEN];
    ssize_t bytes_read;

    // Loop to receive and handle messages from client
    while ((bytes_read = recv(client_socket, message, MAX_MSG_LEN, 0)) > 0) {
        if (!handle_message(client_socket, message, bytes_read)) {
            // Return false to indicate that the server loop should terminate
            return false;
        }
    }

    // Client has disconnected
    // ...

    return true;
}

// Server loop function
void *server_loop(void *arg) {
    int server_socket = *(int *)arg;
    int client_socket;
    pthread_t client_thread;

    // Loop to accept incoming client connections
    while ((client_socket = accept(server_socket, NULL, NULL)) != -1) {
        // Create a new thread to handle the client connection
        if (pthread_create(&client_thread, NULL, (void *(*)(void *))handle_client, &client_socket) != 0) {
            fprintf(stderr, "Error creating client thread: %s\n", strerror(errno));
            close(client_socket);
        }
    }

    // Error accepting client connection
    fprintf(stderr, "Error accepting client connection: %s\n", strerror(errno));

    return NULL;
}
