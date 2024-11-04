#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,j;
	char w[5] = "2002";
	char buff[1024];
	char buff1[1024];

	int res=0;
	scanf("%d%d",&i,&j);
	printf("\ni=%d\tj=%d",i,j);
	sprintf(buff,"\ni=%d\tj=%d",i,j);
	printf("\nBuffer value: %s",buff);
	sprintf(buff1,"%d",i);
	printf("\nBuff1: %s",buff1);
	res = atoi("2002")+2;
	printf("\nResult = %d",res);
	printf("\n\n");
	return 0;
}