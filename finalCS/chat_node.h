#ifndef CHAT_NODE_H
#define CHAT_NODE_H

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_NAME_LEN 24

typedef struct ChatNodeType
{
    int port;
    char[] IP;
    char[MAX_NAME_LEN] Name;

    struct ChatNodeType *nextNode; // pointer to next node as needed
} ChatNodeType;

ChatNodeType *addChatNode( ChatNodeType *localPtr, ChatNodeType *newNode );

#endif CHAT_NODE_H
