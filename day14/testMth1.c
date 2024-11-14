#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>



typedef unsigned long long ULL;

struct varg
{
	ULL s;
	ULL e;
	ULL k;	
};

void *findNum(ULL,ULL,ULL);

void *findNumT(void *);


int main()
{
	pthread_t tid1,tid2,tid3,tid4,tid5;
	struct varg a1,a2,a3,a4,a5;

	struct timespec start, end;
    double time_taken;

	
	a1.s=0;
	a1.e=1900000;
	a1.k=1899999999;

	a2.s=1900000;
	a2.e=19000000;
	a2.k=1899999999;

	a3.s=19000000;
	a3.e=190000000;
	a3.k=1899999999;

	a4.s=190000000;
	a4.e=199000000;
	a4.k=1899999999;

	a5.s=199000000;
	a5.e=1900000000;
	a5.k=1899999999;



	printf("\nI am in main");
	
	/*
	ULL s=0;
	ULL e=1900000000;
	ULL k=1899999999;

	s=0;
	e=1900000;
	findNum(s,e,k);
	s=1900000;
	e=19000000;
	findNum(s,e,k);

	s=19000000;
	e=1900000000;
	findNum(s,e,k);
	*/
	clock_gettime(CLOCK_MONOTONIC, &start);
	pthread_create(&tid1,NULL,findNumT,&a1);
	pthread_create(&tid2,NULL,findNumT,&a2);
	pthread_create(&tid3,NULL,findNumT,&a3);
	pthread_create(&tid4,NULL,findNumT,&a4);
	pthread_create(&tid5,NULL,findNumT,&a5);
	

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_join(tid3, NULL);
	pthread_join(tid4, NULL);
	pthread_join(tid5, NULL);

	 // Stop clock
	clock_gettime(CLOCK_MONOTONIC, &end);

    // Calculate time taken in seconds
    time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

    printf("Time taken by function: %f seconds\n", time_taken);

	printf("\nProgram Ended\n");

	return 0;

}

void *findNumT(void *vargs)
{
	ULL i;
	struct varg *ptr = (struct varg *)vargs;

	int flag=0;
	ULL s = ptr->s;
	ULL e = ptr->e;
	ULL key = ptr->k;
	
	for(i=s;i<e;i++)
	{
		if(i==key)
		{
			
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		printf("\nFound @ pos =%llu\n",i);
	}
	else
		printf("\nNot Found \n");
}


void *findNum(ULL s, ULL e, ULL key)
{
	ULL i;
	int flag=0;
	for(i=s;i<e;i++)
	{
		if(i==key)
		{
			
			flag = 1;
			break;
		}
	}
	if(flag == 1)
	{
		printf("\nFound @ pos =%llu\n",i);
	}
	else
		printf("\nNot Found \n");
}


