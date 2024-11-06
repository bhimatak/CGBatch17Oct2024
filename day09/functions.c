/*
functions

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// functions without input args without return dt
void disp();

//functions with input args and return dt
int add(int, int);

//functions with input args and no return dt

void changeName(char *);




int main()
{
	char Name[20]="Bhima";
	disp();
	printf("\nAddition: %d\n",add(10,30));
	printf("\nName before change: %s",Name);
	changeName(Name);
	printf("\nName after change: %s",Name);
	
	printf("\n\n");
	return EXIT_SUCCESS;
}


void disp()
{
	int i;
	for(i=0;i<30;i++)
		printf("=");
	printf("\n=========Welcome=======\n");
	for(i=0;i<30;i++)
		printf("=");
	printf("\n\n");
}

int add(int v1, int v2)
{
	return (v1+v2);
}

void changeName(char *name)
{
	strcpy(name,"TestName");
}