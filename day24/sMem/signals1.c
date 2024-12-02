/*

	Signals

	signal(signum, function_handler);

*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void display()
{
	printf("\n================================\n");
	printf("Welcome to the C Programming Class\n");
	printf("\n================================\n");
	printf("\nPID : %d",getpid());
}
void sigFUNC(int sigNo)
{
	printf("Signal No : %d caught\n",sigNo);
	if(sigNo == 8)
	{
		printf("divide by zero error\n");
		_exit(EXIT_FAILURE);
	}
	if(sigNo == 11)
	{
		printf("allocate space first\n");
		_exit(EXIT_FAILURE);
	}
	if(sigNo == 2)
	{
		display();
	}
	if(sigNo == 19)
	{
		printf("\nYour process is running in the background with the pid: %d", getpid());
	}


}

void initSignals()
{
	signal(SIGINT,sigFUNC);
	signal(SIGFPE,sigFUNC);
	signal(SIGSEGV,sigFUNC);
	// signal(SIGINT,sigFUNC);
	signal(SIGSTOP, sigFUNC);
	signal(SIGHUP,sigFUNC);
	// signal(SIGINT, SIG_IGN);
}

int main()
{
	int a,b;
	int sum=0;
	initSignals();	
	printf("Press delete key to terminate");
	printf("Enter a and b values: ");
	scanf("%d%d",&a,&b);
	sum = a+b;
	printf("Sum = %d",sum);
	while(1);

	
	return 0;
}
