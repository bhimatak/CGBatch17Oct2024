#include <stdio.h>

int main()
{

	int itr;

	itr = 10;

	/*
	while(itr < 10)
	{
		printf("\nHello");
		itr++;
	}*/

/*
	do
	{
		printf("\nHello");
		itr++;
	}while(itr<10);
*/
/*
	for(itr=8;;itr++)
	{
		printf("\nHello");
		if(itr>=10)
			break;
	}

	*/

	itr = 1;
LoopLabel:
	printf("\nitr=%d",itr);
	itr++;
	if(itr >5)
		goto ExitLable;
	else
		goto LoopLabel;
ExitLable:
	printf("\n\n");

	return 0;
}




