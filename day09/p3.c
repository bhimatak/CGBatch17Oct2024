/*
2D-array demo
*/
#include <stdio.h>

#define ROW 2
#define COL 3

int main()
{
	int a1[ROW][COL] = {{1,2,3},{4,5,6}};
	int a2[ROW][COL] = {1,2,3,4,5,6};

	int riv,civ;

	printf("\n%d\n",a2[0][2]);

	for(riv=0;riv<ROW;riv++)
	{
		for(civ=0;civ<COL;civ++)
			scanf("%d",&a2[riv][civ]);
	}

	for(riv=0;riv<ROW;riv++)
	{
		for(civ=0;civ<COL;civ++)
			printf("%d ",a2[riv][civ]);

		printf("\n");
	}


	printf("\n\n");

	return 0;


}