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
    ChatNodeType *server = (ChatNodeType *) arg;
    message *message = (ChatNodeType *) arg;
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
int send_join_request(ChatNode *server, message *msg) {
    // This function should send a message to the
    // server that includes the client's IP address, port number,
    // and logical name.

    // create request msg to send to server
    message msg;

    // set msg type to join
    msg.type = JOIN;
    
    // set note attribs
    sprintf(msg.note, "%s:%d:%s", server->IP, server->port, server->Name);

    // send mssg
    send_message(msg, server->sockfd )

    return 0
}

// Sends a LEAVE request to the server
int send_leave_request(ChatNode *server, message *msg) {
    // This function should send a message to the
    // server that includes the client's logical name.

    // create mssg n set to type Leave
    message msg;
    msg.type = LEAVE;

    // set sender field to current client name
    strncpy(msg.sender, server->name, MAX_NAME_LEN);

    // convert msg struct to a byte stream
    buffer[sizeof(msg)];
    memcpy(buffer, &msg, sizeof(msg));

    // send message stream to socket
    int n = write(server->sockfd, buffer, sizeof(msg));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // close socket and exit thread?
    close(server->sockfd);
    pthread_exit(NULL);
}

// Sends a message to the server
int send_message(ChatNode *server, message *msg, char *message) {
    // This function should send a
    // message to the server that includes the client's logical
    // name and the message to be sent.

    // set msg type to NOTE
    msg.type = NOTE;

    //  copy msg to message char
    strncpy(msg.note, message, MAX_MSG_LEN);

    // send mssg to server
    send(server->sockfd, &msg, sizeof(message), 0);

    return 0; 
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
