#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/wait.h>

#define PORTNO	 8080
#define MAXBUFF 1024
	
// Driver code
int main() {

	int master_sock, addr_len,newSfd,client_sock[100];

	int max_clients = 30;
	int max_sd,sd;
	int opt, opt_len;


	int readVal = 0;
	char buff[MAXBUFF] = {0,};
	char w_msg[] = "\n============Welcome to the server Programming============\n";
	struct sockaddr_in serv_address, client_address;

	fd_set readfds;

	for(int i=0;i<100;i++)
		client_sock[i] = 0;


	master_sock = socket(AF_INET, SOCK_STREAM,0);
	if(master_sock < 0)
	{
		perror("socket() ");
		exit(EXIT_FAILURE);
	}

	if(setsockopt(master_sock,SOL_SOCKET,SO_REUSEADDR,(char *)&opt,sizeof(opt))<0)
	{
		perror("setsockopt() ");
		exit(EXIT_FAILURE);
	}

	memset(&serv_address,'\0',sizeof(serv_address));

	serv_address.sin_family = AF_INET;
	serv_address.sin_port = htons(PORTNO);
	serv_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	printf("\nServer: Socket created\n");

	int ret = bind(master_sock,(struct sockaddr *)&serv_address, sizeof(serv_address));

	if(ret <0)
	{
		perror("bind() ");
		exit(EXIT_FAILURE);
	}

	ret=0;

	printf("\nServer: Bind");

	listen(master_sock,5);
	printf("\nServer: listening");

	addr_len = sizeof(serv_address);

	printf("\nWaiting for new connections\n");

	while(1)
	{
		FD_ZERO(&readfds);

		FD_SET(master_sock,&readfds);

		max_sd = master_sock;

		for(int i=0;i<max_clients;i++)
		{
			sd = client_sock[i];

			if(sd > 0)
			{
				FD_SET(sd, &readfds);

			}
			if(sd > max_sd)
				max_sd = sd;

		}

		//wait for certain activity to happen on the server

		int retVal = select(max_sd+1,&readfds,NULL,NULL,NULL);

		if(retVal < 0)
		{
			perror("select() ");
			exit(EXIT_FAILURE);
		}

		if(FD_ISSET(master_sock,&readfds))
		{
			newSfd = accept(master_sock,(struct sockaddr*)&serv_address,(socklen_t*) &addr_len);
			if(newSfd < 0)
			{
				close(master_sock);
				perror("accept() ");
				exit(EXIT_FAILURE);
			}
			printf("\nServer: Client connected\n");

			if(send(newSfd,w_msg,strlen(w_msg),0) != strlen(w_msg))
			{
				perror("send() ");
				exit(EXIT_FAILURE);
			}
			printf("\nServer: sent welcome msg\n");

			for(int i=0;i<max_clients;i++)
			{
				if(client_sock[i] == 0)
				{
					client_sock[i] = newSfd;
					printf("\nServer: Added new client sfd to the list\n");
					break;
				}
			}



		}

		for(int i=0;i<max_clients;i++)
		{
			sd = client_sock[i];
			if(FD_ISSET(sd,&readfds))
			{
				read(sd,buff,MAXBUFF);
				getpeername(sd,(struct sockaddr*)&serv_address, (socklen_t *)&addr_len);

				printf("\nHost is disconnecte with ip: %s ",inet_ntoa(serv_address.sin_addr));
				printf("\nWith port no: %d",ntohs(serv_address.sin_port));
				close(sd);
				client_sock[i] = 0;
			}
			else
			{
				buff[strlen(buff)-1] = '\0';
				send(sd,buff,strlen(buff),0);
			}
		}


	}



	printf("\n\n");
	return 0;
}