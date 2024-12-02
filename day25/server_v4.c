/*
Program for tcp server
socket()
bind()
listen()
accept()
send/recv/read/write/sento/recvfrom
close()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXBUFF 1024
#define PORTNO 4003


int main()
{
	int sfd = 0, retValue=0, csfd=0;
	int clientAddlen = 0;
	int client_port;
	struct sockaddr_in serv_address, client_address;

	char msg[MAXBUFF] = {0,};
	char client_ip[255] = {'\0',};

	sfd = socket(AF_INET,SOCK_STREAM,0);

	if(sfd < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}
	printf("\n[+]Server: Socket Created\n");



	//reset/set address of server 

	memset(&serv_address,'\0',sizeof(serv_address));

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1");

	retValue = bind(sfd, (struct sockaddr *)&serv_address,sizeof(serv_address));
	if(retValue < 0)
	{
		perror("bind()");
		exit(EXIT_FAILURE);
	}

	printf("\n[+]Server: Bind Done!\n");
	
	retValue = listen(sfd, 5);
	if(retValue < 0)
	{
		printf("\n[-]Server: Error in listening....\n");
		perror("listen() ");
		exit(EXIT_FAILURE);
	}
	printf("\n[+]Server: Listening....\n");

	while(1){
		csfd = accept(sfd,(struct sockaddr *)&client_address,&clientAddlen);
		if(csfd<0)
		{
			printf("\n[+]Server: Accepted the new Client\n");
			perror("accept ");
			exit(EXIT_FAILURE);
		}
		 // Convert the client's IP address from binary to text
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);
        client_port = ntohs(client_address.sin_port);  // Convert port to host byte order

        // Print the client's IP address and port
      	printf("\n[+]Server: Accepted client IP: %s\tPortNo: %d\n",client_ip,client_port);
		if(fork()==0){
			while(1){
				read(csfd,msg,MAXBUFF);

				printf("\n[%d] sent Msg: %s\n\n",client_port,msg);
				if(strcmp(msg,"bye\n")==0)
				{
					close(csfd);
					break;
				}

				memset(msg,'\0',MAXBUFF);
			}
		}//end of fork
	}


	
	close(sfd);
	
	return 0;
}