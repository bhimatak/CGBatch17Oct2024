#include <isPrime.h>


int isPrime(int val)
{
	int it, flag=0;
	if(val <=1)
		return False;

	for(it=2;it<=val/2;it++)
	{
		if(val%it == 0)
		{
			flag = 1;
			break;
		}
	}
	if(flag ==1)
		return False;
	else
		return True;
}