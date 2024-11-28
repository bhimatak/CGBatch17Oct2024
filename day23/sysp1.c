#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t cpid;
	int status=0;
	printf("\nI am in main\n");
	
	pid_t id = fork();

	if(id == 0)
	{
		
		printf("\nI am Child PID: %d\n",getpid());
		printf("\nChild's Parent id PPID: %d",getppid());
		printf("\nChild's fork returned id = %d",id);
		exit(EXIT_FAILURE);
		
	}
	else
	{
		cpid = wait(&status);
		printf("\nI am Parent PID: %d\n",getpid());
		printf("\nParent's PPID: %d",getppid());
		printf("\nChild's Process fork returned id = %d",id);
		printf("\nCPID : %d",cpid);	

		printf("\nStatus: %d",status);
		if((int)status/256 == 1)
				printf("\nChild died with failure and error: %d",((int)status/256));
		else
				printf("\nChild exited normally");
	}
	printf("\nHello World %d\n",getppid());
	printf("\n\n");

	return 0;
}