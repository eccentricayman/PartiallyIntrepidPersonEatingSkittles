#include "pipe_networking.h"

#define WKP "MEME_SERVER.EXE"
#define pp "MEME.JPG"

int client_handshake(int * toServer) {
    mkfifo(pp, 0666);

	printf("[CLIENT] CREATING A SUPER SECRET PIPE. BEEP BOOP.\n");

	*toServer = open(WKP, O_WRONLY);

	printf("[CLIENT] CONNECTED TO SERVER. IT BEEPS ALOT\n");
	
	write(*toServer, pp, strlen(pp) + 1);

	printf("[CLIENT] SENDING PRIVATE PIPE NAME: %s BEEP.\n", pp);

	int fromServer = open(pp, O_RDONLY);
	
	printf("[CLIENT] GOT PRIVATE CONNECTION. BOOP.\n");

	char message[MESSAGE_BUFFER_SIZE];
	read(fromServer, message, MESSAGE_BUFFER_SIZE);

	printf("[CLIENT] RECIEVED SERVER MESSAGE: %s BEEP.\n", message);

	unlink(pp);

	return fromServer;
}

int server_handshake(int * fromClient) {
    printf("[SERVER] BEEP BOOP. CONNECTING TO CLIENT.\n");

    mkfifo(WKP, 0644);
    * fromClient = open(WKP, O_RDONLY);

    printf("[SERVER] WKP CONNECTED. BEEP BOOP.\n");

    char message[MESSAGE_BUFFER_SIZE];
	read(*fromClient, message, MESSAGE_BUFFER_SIZE);

    printf("[SERVER] CLIENT HAS GIVEN MESSAGE: %s\nBEEP BOOP.\n", message);

    unlink(WKP);

    int toClient = open(message, O_WRONLY);
    printf("[SERVER] CONNECTED TO CLIENT: %s\nBEEP BOOP.", message);
    strcpy(message, "SOMETHING ABOUT A GORILLA.\n");
    printf("[SERVER] MESSAGE SENDING. BEEP BOOP\n");
    write(toClient, message, strlen(message));
    
    return toClient;
}
