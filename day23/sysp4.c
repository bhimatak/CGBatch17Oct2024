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
	printf("\nThis is sPrg04\n");
	if(fork()>0){
		wait(0);
		printf("\nsPrg04 PID: %d", getpid());
	}
	else{
		execl("/usr/bin/ls","/usr/bin/ls",(char *)0);
	}
	printf("\nEnding sPrg04");

	printf("\n\n");
	return 0;
}