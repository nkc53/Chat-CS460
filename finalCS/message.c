#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include "message.h"
#include "chat_node.c"
#include "chat_node.h"

// Function to send a message
void send_message(message msg, int sockfd) {
    // Convert the message structure to a byte stream
    
        /*
        char buf[sizeof(msg)];
        memcpy(buf, &msg, sizeof(msg));
        */

    // Send the message stream to the socket
    
        /*
        int n = write(sockfd, buf, sizeof(msg));
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }
        */
    return NULL;
}

// Function to receive a message
message recv_message(int sockfd) {
    // Read the message byte stream from the socket
    
        /*
        char buf[sizeof(message)];
        int n = read(sockfd, buf, sizeof(message));
        if (n < 0) {
            perror("Error reading from socket");
            exit(1);
        }
        */

    // Convert the byte stream to a message structure
    
        /*
        message msg;
        memcpy(&msg, buf, sizeof(message));

        return msg;
        */
}

