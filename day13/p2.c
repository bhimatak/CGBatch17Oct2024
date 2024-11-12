#include <stdio.h>

enum daysOfWeek
{
	Monday=1000,
	Tuesday,
	Wednesday,
	Thrusday=4005,
	Friday,
	Saturday,
	Sunday
}Days;


int main()
{
	Days = Friday;

	
	printf("\nDay = %d",Days);

	printf("\n\n");

	return 0;
}