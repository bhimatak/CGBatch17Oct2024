/*
Get env variables and print it with capturing field name and value
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[], char *envp[])
{
	int i;
	char *temp;
	for(i=0;envp[i];i++){
		// printf("%s\n",envp[i]);
		if(strstr(envp[i],"="))
		{
			// printf("\nFound");
			temp = strtok(envp[i],"=");
			printf("\nField Name: %s",temp);
			temp = strtok(NULL,"=");
			printf("\nField Value: %s",temp);
					
		}
	}


	printf("\n\n");
	return 0;
}