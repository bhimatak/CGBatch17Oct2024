#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/*
struct tagName1{
	mem/properities of structure
	struct tagName2{

	}
};

*/

typedef struct Employee  
{
	int id;
	int sal;
	int phno;
	char Name[20];
	char Gender;

}EMP;

int display(EMP *);


int main()
{
	char Lines[] = "101|Amit Kumar|M|8888|10000";
	char Names[10][20];
	int row=0,col=0,i;
	char *ptr=NULL;
	int flag = 0;
	EMP e1;
	EMP *testEmp=NULL;

	testEmp = (EMP *)malloc(sizeof(EMP));


	
	ptr = strtok(Lines,"|");

	
	do{
		strcpy(Names[row],ptr);
		// puts(Names[row]);
		ptr = strtok(NULL,"|");
		row++;
	}while(ptr != NULL);

	
	for(i=0;i<row;i++)
		printf("\n%s",Names[i]);

	// names[2][0]=>'M'
	// names[2][1]=>'\0'

	e1.id = atoi(Names[0]);
	strcpy(e1.Name,Names[1]);
	e1.Gender = Names[2][0];
	e1.phno = atoi(Names[3]);
	e1.sal = atoi(Names[4]);

	printf("\nEmployee Records are\n");
	if(display(&e1)==1)
	{
		printf("\nError in Display\n");
		return 1;
	}

	printf("\n\n");
	return 0;
}



/*
rdt fName(args)
{
	----
	return rtd;
}
*/

int display(EMP *e)
{
	if(e == NULL)
		return 1;
	printf("\nID: %d",e->id);
	printf("\nName: %s",e->Name);
	printf("\nGender: %c",e->Gender);
	printf("\nPhNo: %d",e->phno);
	printf("\nSalary: %d",e->sal);
	return 0;
}