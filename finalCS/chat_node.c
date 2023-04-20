#include "chat_node.h"


//work in progress
void createChatNode(  )
{
    // initialize function/variables
    //ChatNodeType *newNodePtr;
    //ChatNodeType *localNodePtr = NULL;
    //int port = 0;
    //char[] IP = "";
    //char[] Name = "";
}

//work in progress
ChatNodeType *addChatNode( ChatNodeType *localPtr, ChatNodeType *newNode )
{
    // check for local pointer assigned to null
    if( localPtr == NULL )
    {
        // access memory for new link/node
            // function: malloc
        localPtr = (ChatNodeType *) malloc ( sizeof( PCBlockType ) );

        // assign all values to newly created node
        // assign next pointer to null
        localPtr->port = newNode->port;
        localPtr->IP = newNode->IP;
        localPtr->Name = newNode->Name;

        localPtr->nextNode = NULL;

        // return current local pointer
        return localPtr;
    }

    // assume end of list not found yet
    // assign recursive function to current's next link
        // function: addPCBNode
    localPtr->nextNode = addChatNode( localPtr->nextNode, newNode );

    // return current local pointer
    return localPtr;
}