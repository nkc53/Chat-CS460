#ifndef SENDER_HANDLER_H
#define SENDER_HANDLER_H

#include <pthread.h>
#include "chat_node.h"

// main function for the sender thread
void *sender_handler(void *arg);

// sends a JOIN request to the server 
int send_join_request(ChatNode *server);

// sends a LEAVE request to the server 
int send_leave_request(ChatNode *server);

// sends a message (note) to all other chat clients 
int send_message(ChatNode *server, char *message);

// shuts down the client 
int shutdown_client(ChatNode *server);

// shuts down all clients and the server 
int shutdown_all(ChatNode *server);

#endif /* SENDER_HANDLER_H */
