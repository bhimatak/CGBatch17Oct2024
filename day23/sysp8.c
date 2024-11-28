#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	int i,count=0;
	
	char *temp[argc];
	for(i=0;i<argc;i++)
		temp[i] = (char *)malloc(1024);

	
	for(i=1,count=0;i<argc;i++,count++)
		strcpy(temp[count],argv[i]);	

	temp[count] = (char *)0;

	for(i=0;i<count;i++)
		printf("\n%s",temp[i]);
	printf("\nCount=%d",count);
	if(execv(argv[1], temp)<0)
		perror("execv ");
	
	printf("\nThis will not print at all\n\n");

	return 0;
}