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
	fp = fopen("db2.txt","r");
	if(fp == NULL)
	{
		perror("fopen: ");
		exit(1);
	}
	printf("\nFile Pointer is at: %lu",ftell(fp));
	
	bytes = fread(&e1,sizeof(EMP),1,fp);
	printf("\nBytes=%d",bytes);
	printf("\nFile Pointer is at: %lu",ftell(fp));
	printf("\nDetails are\n");
	printf("\n%d\t%s\t%c",e1.id,e1.Name,e1.Gender);
	printf("\t%d\t%d\n",e1.phno,e1.sal);
	
	printf("\n\n");
	return 0;

}