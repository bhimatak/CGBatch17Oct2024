#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	int pid, ppid;
	FILE *fp;
	char *chr="Bhima";
	char rchr[10];
	long int i; 
	char c;
	pid = fork();
	if(pid < 0)
	{
		printf("\nUnable to create child process");
		exit(EXIT_FAILURE);
	}
	
	if(pid == 0)
	{
		// sleep(1);
		fp = fopen ("test.dat","a+");
		for(i=5000;i<8000;i++){
			fprintf(fp," c=%ld",i);
			// sleep(1);
		}
		printf("\nWriting to the file is done!");
		printf("\nChild is exiting");
		fclose(fp);
		
	}
	else
	{
		// wait(0);
		// sleep(1);
		fp = fopen ("test.dat","a+");
		if(fp==NULL)
		{
			printf("\nUnable to open the ip file");
			exit(EXIT_FAILURE);
		}
		for(i=1;i<2000;i++){
			fprintf(fp," p=%ld",i);
			// sleep(2);
		}
		printf("\nWriting to the file is done!");
		printf("\nParent is exiting");
		
		// fscanf(fp,"%c",rchr);
		// printf("\nRead char from the file = %s", rchr);
		fclose(fp);
	
	}

	printf("\n\n");

	return 0;
}