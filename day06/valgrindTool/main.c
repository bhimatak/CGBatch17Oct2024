#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *ptr = NULL,i=0;

	ptr = (int *)malloc(sizeof(int)*3);

	ptr[0] = 10;
	ptr[1] = 20;
	ptr[2] = 30;

	i=0;
	while(i<3){
		printf(" %d ",ptr[i]);
		i++;
	}

	printf("\n\n");
	free(ptr);
	return 0;
}
