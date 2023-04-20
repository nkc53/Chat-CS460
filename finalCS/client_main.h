#ifndef CLIENT_MAIN_H
#define CLIENT_MAIN_H

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>  // for gethostbyname
#include <unistd.h>
#include <syslog.h>

#define SERVER_ADDRESS "142.11.213.192"
#define SERVER_PORT 23650

int runClient(int FLAG);

int main(int argc, char** argv)

#endif CLIENT_MAIN_H
