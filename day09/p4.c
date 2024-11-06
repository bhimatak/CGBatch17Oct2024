#include <stdio.h>

#define CAP 100

int main()
{
	int a[CAP], i;
	int mid, countOdd,countEven;
	int m=51, n=103;

	mid = (n-m)/2;
	// printf("\nmid=%d",mid);

	for(i=m,countOdd = 0, countEven=mid;i<n;i++)
	{
		if(i%2 != 0)
		{
			//odd
			a[countOdd] = i;
			// printf("\na[%d]=%d",countOdd,a[countOdd]);
			countOdd++;

		}
		else
		{
			//even

			a[countEven] = i;
			// printf("\na[%d]=%d",countEven,a[countEven]);
			countEven++;
		}
	}


	for(i=0;i<countEven;i++)
		printf("%d ",a[i]);

	printf("\n\n");
	return 0;

}