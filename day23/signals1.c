#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void abc(int id)
{
	printf("\nInterrupted by signal: %d\n",id);
	exit(EXIT_SUCCESS);

}

void abc1(int id)
{
	printf("\nInterrupted by signal: %d\n",id);
	if(id == 8)
	{
		printf("\nFloat point exp occured\n");
		exit(EXIT_FAILURE);
	}

}

float div1(int a, int b)
{
	return (a/b);
}


int main()

{
	int status=0;
	signal(SIGINT, abc);
	signal(SIGQUIT, abc);
	signal(SIGSEGV, abc);
	signal(SIGFPE, abc1);
	if(fork() == 0){
		// div1(10,0);
		while(1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		printf("Parent died: status : %d\n",status/256);
	}

	return 0;
}
