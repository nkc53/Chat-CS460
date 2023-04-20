#ifndef CHAT_NODE_H
#define CHAT_NODE_H

// header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>

typedef struct ChatNodeType
{
    int port;
    char[] IP;
    char[] Name;

    struct ChatNodeType *nextNode; // pointer to next node as needed
} ChatNodeType;

ChatNodeType *addChatNode( ChatNodeType *localPtr, ChatNodeType *newNode );

#endif CHAT_NODE_H
