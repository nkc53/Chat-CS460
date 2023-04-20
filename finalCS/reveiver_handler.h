#ifndef RECEIVER_HANDLER_H
#define RECEIVER_HANDLER_H

#include <stdbool.h>

bool handle_client(int client_socket);
void *server_loop(void *arg);

#endif /* RECEIVER_HANDLER_H */
