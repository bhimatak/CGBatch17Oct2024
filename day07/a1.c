/*
Desc: assignment 01 
	scan and print the employee records in the 
	following format
	SlNo | ID | NAME | GENDER | ADDRESS | PHNO | SALARY | DESG
	001	 | 101|Bhima | M      | Kar     | 8888 | 10000  | SE

Author: BT
DOC: 04-11-2024
Version: 0.1v

*/

#include <stdio.h>

int main()
{

	int id;
	int phno;
	float salary;
	char name[20];
	char address[20];
	char desg[20];
	char gender;

	int wdFld = 1;


	printf("\nEnter the Employee details\n");
	printf("\nID: ");
	scanf("%d",&id);
	printf("\nName: ");
	scanf("%s",name);
	printf("\nGender: ");
	scanf(" ");
	scanf("%c",&gender);
	printf("\nPhNo: ");
	scanf("%d",&phno);
	printf("\nAddress: ");
	scanf("%s",address);
	printf("\nSalary: ");
	scanf("%f",&salary);
	printf("\nDesgination: ");
	scanf("%s",desg);



	printf("\n%-4s\t|%s| NAME | GENDER | ADDRESS | PHNO | SALARY | DESG","SlNo","ID");
	printf("\n%03d\t| %d | %s | %c | %s | %d | %f | %s\n",1,id,name,gender,address, phno,salary, desg);
	printf("\n\n");


}