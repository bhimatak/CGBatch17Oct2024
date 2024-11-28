/*

exec() : system lib functions/calls

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	// int pid, ppid;
	printf("\nThis is sPrg05\n");
	

	if(execl("/usr/bin/ls","ls",(char *)0)<0)
	{
		perror("execl: ");
		exit(EXIT_FAILURE);
	}
	printf("\nEnding sPrg05");

	printf("\n\n");
	return 0;
}