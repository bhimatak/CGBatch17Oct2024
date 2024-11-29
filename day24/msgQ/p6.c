#include "myheader.h"
#define PERMS 0666
int main()
{
	int msgid;
	msgid = msgget((key_t)15,IPC_CREAT|PERMS);
	if(msgid < 0){
		perror("msgget ");
		_exit(EXIT_SUCCESS);
	}
	printf("\nMSG queue created with %d id\n",msgid);
	printf("\nTO remove msgid = %d from ipc table\n",msgid);
	if(msgctl(msgid,IPC_RMID,0)<0)
	{
		perror("msgctl ");
		_exit(EXIT_SUCCESS);	
	}
	printf("\n\n");
	return 0;
}