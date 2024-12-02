// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>

	
#define PORT	 8080
#define MAXLINE 1024
	
// Driver code
int main() {
	int sockfd;
	int cpid;
	char buffer[MAXLINE];
	char *hello = "ACK";
	struct sockaddr_in servaddr, cliaddr;
		
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // INADDR_ANY; => loop back address
	servaddr.sin_port = htons(PORT);
		
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
		
	int len, n;
	
	len = sizeof(cliaddr); //len is value/result
	
	 while(1)
	 {
		cpid = fork();
		memset(buffer,'\0',MAXLINE);
		if(cpid < 0)
		{
			perror("fork() ");
			exit(EXIT_FAILURE);
		}
		if(cpid == 0){
			n = recvfrom(sockfd, (char *)buffer, MAXLINE,
						0, ( struct sockaddr *) &cliaddr,
						&len);
			buffer[n] = '\0';
			printf("Client : %s\n", buffer);
			sendto(sockfd, (const char *)hello, strlen(hello),
				0, (const struct sockaddr *) &cliaddr,
					len);
			printf("Hello message sent.\n");
		}
		else
		{
			close(sockfd);
			wait(0);
			printf("Server Ended up\n");
		}
		

	}
		
	return 0;
}
