// Client side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
	
#define PORT	 8080
#define MAXLINE 1024
	
// Driver code
int main() {
	int sockfd;
	char buffer[MAXLINE];
	char Ack[20] = {0,};
	struct sockaddr_in	 servaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // INADDR_ANY;
		
	int n, len;
	while(1){	
		printf("Client: ");
		memset(buffer,'\0',MAXLINE);
		memset(Ack,'\0',sizeof(Ack));
		fgets(buffer,MAXLINE,stdin);
		// scanf("%[^\n]s",buffer);
		// strcpy(buffer,"Client Msg");
		sendto(sockfd, (const char *)buffer, strlen(buffer),
			0, (const struct sockaddr *) &servaddr,
				sizeof(servaddr));
				
		n = recvfrom(sockfd, (char *)Ack, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
		buffer[n] = '\0';
		printf("Server : %s\n", Ack);
	}
	
	close(sockfd);
	return 0;
}
