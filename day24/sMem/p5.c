#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <string.h>

#define PERMS 0666
#define MAXBUF 1024


int main()
{
	key_t key = 10003;
	int shmid;
	// char msg[] = "Hello Bhima, WellCome to C Programmming class";// = NULL; //(char *)malloc(MAXBUF);
	
	shmid = shmget(key,1,PERMS|IPC_CREAT);

	char *ptr = NULL;

	if(shmid < 0)
	{
		perror("shmget()");
		printf("\nDirectly use this shm mem to read and write");
		exit(EXIT_FAILURE);
	}
	printf("\nShared mem id =%d\n",shmid);
	
	
	ptr = (char *)shmat(shmid,(void *)0,0);
	printf("\nMsg = %s\n",ptr);
	
	shmdt(ptr);

	shmctl(shmid,IPC_RMID,0);
	return 0;
}