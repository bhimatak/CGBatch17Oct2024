#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

	char s1[400],s2[20];

	char *ptr=NULL;

	printf("\nEnter the Line with delimiter\n");
	scanf("%[^\n]s",s1);

	ptr = strtok(s1,",");

	printf("\nptr = %s",ptr);

	printf("\n\n");

	return 0;

}

