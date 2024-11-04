#include <stdio.h>
#include <string.h>

int main()
{
	char empName[20];

	int i;
	fgets(empName,19,stdin);
	puts(empName);

	/*
	if(strcmp(gets(buff),"quit")==0)
	{
		quit code
	}
	else{

			other than quit code
	}

	*/

	if(strcmp(empName,"bhima\n")==0)
		printf("\nEqual");
	else
		printf("\nNot Equal");



	for(i=0;i<strlen(empName);i++)
		printf("\n%c = %d",empName[i],empName[i]);
	printf("\n\n");
	return 0;

}