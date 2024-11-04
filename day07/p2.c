#include <stdio.h>

int main()
{
	char name[20];
	char temp[20];
	scanf("%[^\n]s",name);
	printf("\nName: %s",name);
	scanf("%s",temp);
	printf("\nTemp: %s",temp);
	printf("\n\n");
	return 0;
}