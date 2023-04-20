#include "client_main.h"
#include "receiver_handler.c"
#include "sender_handler.c"

int runClient(int FLAG) {
    int server_socket;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int32_t num;
    int32_t count;

    // get the server host information
    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        syslog(LOG_ERR, "ERROR no host");
        printf("Error\n");
    }
    
    // create a socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        syslog(LOG_ERR, "Error creating socket");
        printf("Error\n");
    }
    
    // name the socket (making sure the correct network byte ordering is observed)
    serv_addr.sin_family = AF_INET;                                 // accept IP addresses
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);      // accept clients on any interface
    serv_addr.sin_port = htons(SERVER_PORT);                        // port to listen on
    
    // connect to the server
    if (connect(server_socket, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        syslog(LOG_ERR, "ERROR connecting");
        printf("Error\n");
    }

    //check flag to see whether we are doing sending / recieving actions
    if(FLAG == 0)
    {   
        server_loop(server_socket);
    }
    else if(FLAG == 1)
    {
        sender_handler(server_socket);
    }

    // close the socket
    close(server_socket);
    return 0;
}

int main(int argc, char** argv) {
    int threadNum = 2;
    int taskCounter = 0;
    for(int i = 1; i < threadNum; i++)
    {
        pthread_t thread_id = taskCounter;
        if(thread_id == threadNum)
        {
            pthread_create(&thread_id, NULL, (void *)runClient(0), NULL);
        }
        else
        {
            pthread_create(&thread_id, NULL, (void *)runClient(1), NULL);
        }
        taskCounter++;
    }
}
