#ifndef emp_h
#define emp_h

typedef struct emp
{
	int id;
	char name[20];
	float sal;
}EMP;


int getDetails(EMP *);

#endif