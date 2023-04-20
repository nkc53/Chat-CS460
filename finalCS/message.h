#ifndef MESSAGE_H
#define MESSAGE_H

#define MAX_MESSAGE_LENGTH 1024

// Symbolic constants for message types
#define NOTE 1
#define JOIN 2
#define LEAVE 3
#define SHUTDOWN 4
#define SHUTDOWN ALL 5


// Structure representing a message
typedef struct message {
    int type;       // for NOTE, JOIN... 
    // chat_node sender;
    // ^^^ should be a linked list structure??
    char note[MAX_MESSAGE_LENGTH];  // might need to change MAX_MESSAGE_LENGTH after testing
} message;

// Function to send a message
void send_message(message msg, int sockfd);

// Function to receive a message
message recv_message(int sockfd);

#endif
