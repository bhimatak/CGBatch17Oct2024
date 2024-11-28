/*
Get env variables and print it with capturing field name and value
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


extern char**environ;

int main()
{
	int i;
	
	for(i=0;environ[i];i++){
		printf("\n%s",environ[i]);
		
	}


	printf("\n\n");
	return 0;
}