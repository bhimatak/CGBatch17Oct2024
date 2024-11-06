#include <stdio.h>
#include <stdlib.h>
#include <isPrime.h>

int main()

{
	int num;
	scanf("%d",&num);
	if(isPrime(num)==True)
		printf("\n%d is a Prime Number",num);
	else
		printf("\n%d is not a Prime Number",num);
	
	

	printf("\n\n");
	return 0;
}