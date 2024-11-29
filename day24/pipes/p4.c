#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define BUFF 1024


void func1(int id)
{
	printf("\nParent Failed\n");
	printf("\nSignal Caught=%d\n",id);
}

int main()
{
	int fd[2];
	int status, ret=0;
	pid_t cpid;
	char line[BUFF]="Hello";

	signal(SIGPIPE,func1);
	pipe(fd);

	cpid = fork();
	if(cpid == 0)
	{
		//child process
		close(fd[0]);
		close(fd[1]);
		printf("\nChild Exiting\n");
		_exit(EXIT_SUCCESS);
	}
	else
	{
		//parent process
		sleep(1);
		close(fd[0]); //reading is closed
		ret = write(fd[1],line,6);
		printf("\nRet=%d\n",ret);
		close(fd[1]);
	}

	printf("\nEnd of Program\n\n");
	return 0;
}