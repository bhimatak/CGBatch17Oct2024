#include "emp.h"
#include <stdio.h>

int getDetails(EMP *e)
{
	if (e==NULL)
		return 102;
	if(scanf("%d",&e->id)!=1)
		return 0;
	if(scanf("%s",e->name)!=1)
		return 0;
	if(scanf("%f",&e->sal)!=1)
		return 0;

	return 1;

}