#define MESSAGE_BUFFER_SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int client_handshake(int * toServer);

int server_handshake(int * fromClient);
