/*
while(cond1)
{
	sts
}
*/

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define True 1
#define False 0


int displayMenu();

int main()
{
	int ch;
	int flag = 0, val1, val2;
	while(True){
		flag = 0;
		ch = displayMenu();
		if(ch == 5)
			break;
		printf("\nEnter the two values: ");
		scanf("%d%d",&val1,&val2);
		switch(ch)
		{
			case 1:
				printf("\nAdd of %d + %d = %d\n",val1,val2,(val1+val2));
				break;
			case 2:
				printf("\nSub of %d + %d = %d\n",val1,val2,(val1-val2));
				break;
			case 3:
				printf("\nMul of %d + %d = %d\n",val1,val2,(val1*val2));
				break;
			case 4:
				printf("\nDiv of %d + %d = %f\n",val1,val2,(float)val1/val2);
				break;
			case 5:
				printf("\nExiting from the Application\n");
				//exit(SUCCESS);
				flag = 1;
				break;
			default:
				printf("\nEnter the correct Choice\n");

		}//end of switch

		if(flag == 1)
			break;

	}//end of while loop

	printf("\nProgram Ended\n\n");
	return (SUCCESS);
}

int displayMenu()
{
	int choice;

	printf("\nPress,");
	printf("\n1. Addition");
	printf("\n2. Sub");
	printf("\n3. Mul");
	printf("\n4. Division");
	printf("\n5. Exit");
	printf("\nChoice: ");
	scanf("%d",&choice);

	return choice;
}