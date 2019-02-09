//---------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <winsock2.h>
#include <windows.h> 

#define IPLENGTH 16
#define PORTLENGTH 5

//---------------------------------------------------------------------------
void checkArgs(int argc) {	//Num of args
	if (argc < 2) {
		printf("Enter argument: 0 for client (Second player), 1 for server (First player)");
		exit(-1);
	}
}
//---------------------------------------------------------------------------
void initClient() {
	char serverIP[IPLENGTH], serverPort[PORTLENGTH];
	printf("Enter server's IP (example: 127.0.0.1): ");
	scanf("%s", &serverIP);
	printf("Enter server's port (example: 12345): ");
	scanf("%s", &serverPort);
	
	//Init Winsock
	struct WSAData WS;
	if (FAILED(WSAStartup(0x202, (WSADATA *)&WS))){
		//Error
		printf("Client can NOT initialize WSAStartup, error: %d\n", WSAGetLastError());
		exit(-3);
	}
}
//---------------------------------------------------------------------------
void initServer() {
	
}
//---------------------------------------------------------------------------
int main (int argc, char *argv[]) { //Server: 1 serverPort; Client: 0 serverIP serverPort
	checkArgs(argc);
	
	if (atoi(argv[1]) == 0) {
		//Client code
		initClient();
	}
	else if (atoi(argv[1]) == 1) {
		//Server code
		initServer();
	}
	else {
		//WTF code
		printf("Enter argument: 0 for client (Second player), 1 for server (First player)");
		return -2;
	}
	return 0;
}