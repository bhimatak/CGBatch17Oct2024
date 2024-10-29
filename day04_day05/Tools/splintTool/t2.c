#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr=NULL;
	*ptr = 10;
	printf("%d",*ptr);
	//free(ptr);	
	return 0;
}
