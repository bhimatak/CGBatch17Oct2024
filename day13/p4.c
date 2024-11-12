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
	char ch;

	e1.id = 103;
	e1.sal = 10000;
	strcpy(e1.Name,"Bhima");
	e1.Gender = 'M';
	e1.phno = 9998;

	fp = fopen("db1.txt","r");
	if(fp == NULL)
	{
		perror("fopen: ");
		exit(1);
	}
	printf("\nFile Pointer is at: %lu",ftell(fp));
	// fprintf(fp,"%d|%s|%c|%d|\n",e1.id,e1.Name,e1.Gender,e1.phno);
	// printf("\nFile Pointer after writing: %lu",ftell(fp));
	fseek(fp,11,SEEK_SET);
	printf("\nFile Pointer is at: %lu",ftell(fp));
	ch = fgetc(fp);
	printf("\nch=%c",ch);
	fseek(fp,9,SEEK_CUR);
	printf("\nFile Pointer is at: %lu",ftell(fp));
	ch = fgetc(fp);
	printf("\nch=%c",ch);
	
	fseek(fp,-13,SEEK_CUR);
	ch = fgetc(fp);
	printf("\nch=%c",ch);
	

	fclose(fp);
	printf("\n\n");
	return 0;
}