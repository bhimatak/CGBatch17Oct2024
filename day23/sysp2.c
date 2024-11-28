#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t id,cpid;
	printf("\nI am in main\n");
	
	id = fork();

	if(id == 0)
	{
		
		printf("\nI am Child 1 PID: %d\n",getpid());
		printf("\nChild's Parent id PPID: %d",getppid());
		printf("\nChild's Process id = %d",id);
		cpid = fork();
		if(cpid == 0)
		{
			printf("\nI am Child 2 PID: %d\n",getpid());
			printf("\nChild's Parent id PPID: %d",getppid());
			printf("\nChild's Process id = %d",cpid);
			
		}
		else
		{
			wait(0);
			printf("\nI am Parent(child 1) PID: %d\n",getpid());
			printf("\nParent's PPID: %d",getppid());
			printf("\nChild's Process id = %d",id);		
		}

		
	}
	else
	{
		wait(0);
		printf("\nI am Parent PID: %d\n",getpid());
		printf("\nParent's PPID: %d",getppid());
		printf("\nChild's Process id = %d",id);	
		cpid = fork();
		if(cpid == 0)
		{
			printf("\nMain child's PID: %d",getpid());
			printf("\nMain child's PPID: %d",getppid());
		}
	}
	printf("\nHello World %d\n",getppid());
	printf("\n\n");

	return 0;
}