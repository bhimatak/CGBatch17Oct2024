#include <stdio.h>
#include <string.h>


int main()
{
	char Lines[] = "101|Amit Kumar|M|8888|10000";
	char Names[10][20];
	int row=0,col=0,i;
	char *ptr=NULL;
	int flag = 0;

	
	ptr = strtok(Lines,"|");

	
	do{
		strcpy(Names[row],ptr);
		// puts(Names[row]);
		ptr = strtok(NULL,"|");
		row++;
	}while(ptr != NULL);

	
	for(i=0;i<row;i++)
		printf("\n%s",Names[i]);
	
	printf("\n\n");
	return 0;
}