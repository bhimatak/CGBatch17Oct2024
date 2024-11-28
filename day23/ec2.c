#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	printf("\nec2.c\n");
	printf("\nPID: %d",getpid());

	printf("\n%s\n%s",argv[0],argv[1]);
	printf("\nHello, %s\nWelcome to the World of Programming\n\n",argv[1]);
	return 0;
}