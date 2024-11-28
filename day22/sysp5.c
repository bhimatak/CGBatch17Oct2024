#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	printf("\nI am in main\n");
	
	pid_t id = fork();

	if(id == 0)
	{
		
		printf("\nI am Child PID: %d\n",getpid());
		printf("\nChild's Parent id PPID: %d",getppid());
		printf("\nChild's Process id = %d",id);
		
	}
	else
	{
		wait(0);
		printf("\nI am Parent PID: %d\n",getpid());
		printf("\nParent's PPID: %d",getppid());
		printf("\nChild's Process id = %d",id);	
	}
	printf("\nHello World %d\n",getppid());
	printf("\n\n");

	return 0;
}