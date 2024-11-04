#include <stdio.h>


int main()
{
	int i;
	float f;
	char ch;
	char str1[20];
	double d;


	printf("\nAddress of the variables\n");
	printf("\nAddress of i: %u",&i);
	printf("\nAddress of f: %u",&f);
	printf("\nAddress of ch: %u",&ch);
	printf("\nAddress of str1: %u",&str1);
	printf("\nAddress of d: %u",&d);
	
	
	printf("\nEnter the proper values\n");

	printf("\nEnter interger value: ");
	scanf("%3d",&i);

	scanf(" ");
	printf("\nEnter float value: ");
	scanf("%f",&f);

	printf("\nEnter double value: ");
	scanf("%lf",&d);

	printf("\nEnter string value: ");
	scanf("%s",str1);

	

	printf("\nEnter single character value: ");
	scanf(" ");
	//fflush(stdin);
	//scanf("%c",&ch);
	if(scanf("%c",&ch)<0)
		printf("\nnot scanned\n");
	else
		printf("\nSuccefully scnnned item");
	
	

	printf("\nInterger value: %05d\n",i);
	printf("\nFloat value: %f\n",f);
	printf("\nDouble value: %lf\n",d);
	printf("\nString value: %s\n",str1);
	printf("\nSingle character value: %c\n",ch);

	printf("\n%d\n",printf("hello"));

	return 0;
}
