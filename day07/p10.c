#include <stdio.h>

int main()
{

	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);

	if(a>b)
	{
		//a is big than a and to be compared with rest i.e
		//c,d,e
		if(a>c)
		{
			if(a>d)
			{
				if(a>e)
				{
					printf("\na\n");
				}
				else
				{
					printf("\ne\n");
				}

			}
			else
			{
				if(d>e)
				{
					printf("\nd\n");	
				}
				else
				{
					printf("\ne\n");
				}
			}
		}
		else
		{
			if(c>d)
			{
				if(c>e)
					printf("\nc\n");
				else
					printf("\ne\n");
			}
			else
			{
				if(d>e)
					printf("\nd\n");
				else
					printf("\ne\n");	
			}
		}
		
	}
	else
	{
		//b is big than a and to be compared with rest i.e
		//c,d,e

		if(b>c)
		{
			if(b>d)
			{
				if(b>e)
					printf("\nb\n");
				else
					printf("\ne\n");
			}
			else
			{
				if(d>e)
					printf("\nd\n");
				else
					printf("\ne\n");
			}
		}
		else
		{
			if(c>d)
			{
				if(c>e)
					printf("\nc\n");
				else
					printf("\ne\n");
			}
			else
			{
				if(d>e)
					printf("\nd\n");
				else
					printf("\ne\n");
			}
		}
	}


	printf("\n\n");
	return 0;
}