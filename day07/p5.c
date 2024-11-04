#include <stdio.h>

int main()
{
	int i,j,k;

	char buff[100] = "10 20 30";
	sscanf(buff,"%d %d %d",&i,&j,&k);

	printf("\ni=%d\tj=%d\tk=%d\n",i,j,k);
	return 0;
}