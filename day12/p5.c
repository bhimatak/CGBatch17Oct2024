#include <stdio.h>
#include <string.h>
#include <stdlib.h>



typedef struct Employee  
{
	int id;
	int sal;
	int phno;
	char Name[20];
	char Gender;

}EMP;

int printEmp(EMP *);
int getEmp(EMP *);

int main()
{
	EMP e1;

	EMP *e=NULL;

	// e = &e1;

	e = (EMP *)malloc(sizeof(EMP));

/*
	scanf("%d%d%d",&e1.id,&e1.sal,&e1.phno);
	scanf("%s",e1.Name);
	getchar();
	scanf("%c",&e1.Gender);
*/

	scanf("%d%d%d",&e->id,&e->sal,&e->phno);
	scanf("%s",e->Name);
	getchar();
	scanf("%c",&e->Gender);


	printf("\nID: %d",e->id);
	printf("\nName: %s",e->Name);
	printf("\nGender: %c",e->Gender);
	printf("\nPhNo: %d",e->phno);
	printf("\nSalary: %d",e->sal);

	printf("\n\n");
	return 0;

}