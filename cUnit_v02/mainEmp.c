#include "emp.h"
#include <stdio.h>

int main()
{
	EMP *e = NULL;

	getDetails(e);

	printf("\n%d %s %f",e->id,e->name,e->sal);

	printf("\n\n");

	return 0;
}