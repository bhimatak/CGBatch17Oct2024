#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Employee  
{
	int id;
	int sal;
	int phno;
	char Name[20];
	char Gender;

}EMP;


int main()
{
	FILE *fp=NULL;
	EMP e1;
	int bytes=0;

	e1.id = 103;
	e1.sal = 10000;
	strcpy(e1.Name,"Bhima");
	e1.Gender = 'M';
	e1.phno = 9998;

	fp = fopen("db2.txt","w");
	if(fp == NULL)
	{
		perror("fopen: ");
		exit(1);
	}
	printf("\nFile Pointer is at: %lu",ftell(fp));
	
	bytes = fwrite(&e1,sizeof(EMP),1,fp);
	printf("\nBytes=%d",bytes);
	printf("\nFile Pointer is at: %lu",ftell(fp));
	

	printf("\n\n");
	return 0;

}