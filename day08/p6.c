/*

for(initial section;cond section;counter)
{
	sts;
}
i=0;
j=0;
for(;;)
{
	sts;
	if((i>10)&&(j>10))
		break;
	i++;
	j+=2;
}
*/

#include <stdio.h>

int main()
{
	int i,j;

	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			printf("\ni=%d\tj=%d",i,j);

	}
	printf("\n\n");

	return 0;
}