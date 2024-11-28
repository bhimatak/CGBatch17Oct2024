#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	/*
	int pid = getpid();
	pid_t ppid = getppid();
	int id;

	printf("\nMy own Pid = %d\n",pid);
	printf("\nfor %d parent is %d\n",pid,ppid);
	*/
	printf("\nI am Parent and my id is %d\n",getpid());
	printf("\nParent's PPID: %d",getppid());
	pid_t id = fork();

	if(id == 0)
	{
		printf("\nI am Child Process\n");
		printf("\nMy Id = %d",getpid());
	}
	else
	{
		printf("\nIn the Parent child Process id = %d",id);	
	}
	printf("\nHello World\n");
	printf("\n\n");

	return 0;
}