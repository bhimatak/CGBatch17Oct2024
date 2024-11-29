#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFF 1024

int main()
{
	int fd[2];
	int status;
	pid_t cpid;
	char line[BUFF]={'\0',};

	pipe(fd);

	cpid = fork();
	if(cpid == 0)
	{
		//child process
		// close(fd[0]); //reading is closed
		// write(fd[1],"Hello World",12);
		sleep(5);
		printf("\nChild Exiting\n");
		// _exit(EXIT_SUCCESS);
	}
	else
	{
		// wait(&status);
		// printf("\nChild with %d pid exited with status=%d\n",cpid,(status/256));
		//parent process
		close(fd[1]); //writing is closed
		read(fd[0],line,BUFF);
		printf("\nLine Read\n%s",line);

	}

	printf("\nEnd of Program\n\n");
	return 0;
}