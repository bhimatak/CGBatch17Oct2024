/*
thread demo
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define ITNERS 1000000

void printHello();

int main()
{
	pthread_t tid;

	int status=0;

	printf("\nIn the Main Function\n");
	printf("\nI am Main Program/Process/MainThread\n");

	status = pthread_create(&tid,NULL,printHello,NULL);
	// pthread_join(tid,NULL);
	
	
	sleep(1);
	printf("\nAfter completing (Main)\n");	

	return 0;
}

void printHello()
{
	int i;
	printf("\nHello World\n");
	for(i=0;i<ITNERS;i++)
		printf("\n\ti=%d",i);

}