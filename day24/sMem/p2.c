#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

#define PERMS 0666
#define MAXBUF 1024

typedef struct Employee
{
	int _id;
	int sal;
	char name[MAXBUF];

}EMP;

int main()
{
	key_t key = 10002;
	EMP *e =NULL;
	int shmid;
	char *msg;// = NULL; //(char *)malloc(MAXBUF);

	shmid = shmget(key,sizeof(EMP)*1,PERMS|IPC_CREAT);

	if(shmid < 0)
	{
		perror("shmget()");
		printf("\nDirectly use this shm mem to read and write");
		exit(EXIT_FAILURE);
	}
	printf("\nShared mem id =%d\n",shmid);

	return 0;
}