#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include "sender_handler.h"
#include "chat_node.h"

// Handles how messages are sent to the chat
void *sender_handler(void *arg) {
    // Cast the argument to the ChatNode linked list struct

    // main loop for the sender thread,
    // which waits for user input and calls the appropriate
    // functions to handle the user's requests.
    char buffer[MAX_MSG_LEN];
    while (1) {
        fgets(buffer, MAX_MESSAGE_SIZE, stdin);
        if (strcmp(buffer, "JOIN\n") == 0) {
            send_join_request(server);
        } else if (strcmp(buffer, "LEAVE\n") == 0) {
            send_leave_request(server);
        } else if (strcmp(buffer, "SHUTDOWN\n") == 0) {
            shutdown_client(server);
            break;
        } else if (strcmp(buffer, "SHUTDOWN ALL\n") == 0) {
            shutdown_all(server);
            break;
        } else {
            send_message(server, buffer);
        }
    }

    return NULL;
}

// Sends a JOIN request to the server
int send_join_request(ChatNode *server) {
    // This function should send a message to the
    // server that includes the client's IP address, port number,
    // and logical name.
}

// Sends a LEAVE request to the server
int send_leave_request(ChatNode *server) {
    // This function should send a message to the
    // server that includes the client's logical name.
}

// Sends a message to the server
int send_message(ChatNode *server, char *message) {
    // This function should send a
    // message to the server that includes the client's logical
    // name and the message to be sent.
}

// Sends a LEAVE request to the server if the client has joined
// the chat before, and then closes the socket and terminates the thread
int shutdown_client(ChatNode *server) {
    // This function should send a LEAVE request to the server
    // if the client has joined the chat before, and then close
    // the socket and terminate the thread.
}

// Sends a SHUTDOWN request to the server, and then
// closes the socket and terminates the thread
int shutdown_all(ChatNode *server) {
    // This function should send a SHUTDOWN
    // request to the server, and then close the socket and
    // terminate the thread.
}
