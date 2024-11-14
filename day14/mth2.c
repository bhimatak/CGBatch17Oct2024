#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <time.h>


typedef unsigned long long ULL;
struct varg
{
	ULL start;
	ULL  end;
};


typedef struct Employee
{
	int id;
	char name[20];
	float sal;
}EMP;

ULL sumOdd = 0;
ULL sumEven = 0;

void *findEven(void *vargs)
{
	ULL i;
	ULL start,end;
	struct varg *ptr = (struct varg *)vargs;

	start = ptr->start;
	end = ptr->end;

	printf("\n%lld \n%lld\n",ptr->start,ptr->end);
	for(i = start;i<=end;i++)
	{
		if((i & 1) == 0)
		{
			sumEven += i;
			// sleep(1);
		}

	}

	printf("\nIn Thread Sum Even = %lld\n", sumEven);
}

void *func(void *vargs)
{
	struct varg *ptr = (struct varg *)vargs;
	// printf("\nvargs = %d\n",*ptr);
	// char *Name = (char *)vargs;
	// printf("\nvargs = %s\n",Name);
	// struct varg *ptr  = (struct varg *)vargs;
	// printf("\n%d\n%d\n",ptr->a,ptr->b);

	printf("\n1st arg = %llu",ptr->start);
	
	printf("\n2nd arg = %llu",ptr->end);
}

void *printEmp(void *vargs)
{
	EMP *ptr = (EMP *)vargs;

	printf("\nID: %d",ptr->id);
	printf("\nName: %s",ptr->name);
	printf("\nSalary: %f",ptr->sal);
}

int main()
{
	int a=10;
	char name[20] = "Bhima";
	struct varg arg;
	EMP e;
	pthread_t tid;

	struct timespec start, end;
    double time_taken;


	// arg.a = 101;
	// arg.b = 201;

	arg.start = 110;
	arg.end = 1900000000;
	
	e.id=101;
	strcpy(e.name,"Bhima");
	e.sal = 10001.1;

	clock_gettime(CLOCK_MONOTONIC, &start);

	// pthread_create(&tid, NULL, func,&arg);
	pthread_create(&tid, NULL, findEven,&arg);

	// pthread_create(&tid,NULL,printEmp,&e);

	 // Stop clock
	pthread_join(tid,NULL);
    clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate time taken in seconds
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Time taken by function: %f seconds\n", time_taken);

	printf("\nSum Even = %lld\n",sumEven);

	pthread_exit(NULL);


	return 0;
}