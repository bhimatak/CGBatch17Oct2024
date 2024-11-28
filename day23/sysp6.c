#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	printf("\nIn the sysPrg6.c\n");
	
	// printf("\n%s\n%s",argv[1],argv[2]);
	execl(argv[1],argv[2],argv[3],(char*)0);
	printf("\nThis line will not print\n\n");

	return 0;
}