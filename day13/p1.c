/*
union demo
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sEmployee
{
	int id;
	float sal;
	char g;
	char Name[20];
}sEMP;

typedef union uEmployee
{
	int id;
	int sal;
	char g;
	char Name[20];
}uEMP;


int main()
{
	sEMP es;
	uEMP eu;
	uEMP *eu1=NULL;

	printf("\nSize of Struct = %d",sizeof(es));
	printf("\nSize of Union = %d",sizeof(eu));


	eu.id = 101;
	eu.sal = 10000;
	strcpy(eu.Name,"Bhimashankar");
	printf("\nNAme = %s",eu.Name);

	eu1 = (uEMP *)malloc(sizeof(uEMP));

	eu1->id = 102;
	printf("\nID: %d",eu1->id);

	printf("\n\n");

	return 0;
}