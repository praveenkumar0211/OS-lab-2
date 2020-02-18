# include <sys/ipc.h>
# define  NULL 0
# include <sys/shm.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <stdio_ext.h>
# include <errno.h>
# include <fcntl.h>
# include <ctype.h>
# define  BUFF_SIZE 1024

int main()
{
	char *avail,*usr1,*usr2;
	int id,id1,id2;
	
	id=shmget(111,50,IPC_CREAT | 00666);
	id1=shmget(112,50,IPC_CREAT | 00666);
	id2=shmget(113,50,IPC_CREAT | 00666);
	
	avail=shmat(id,NULL,0);
	usr1=shmat(id1,0,0);
	usr2=shmat(id2,0,0);
	strcpy(usr1,"-1");
	strcpy(usr2,"-1");
	while(1){
	
		printf("You      : ");
		scanf (" %[^\n]",usr2);
	
		if(strcmp(usr1,"-1")!=0){
			printf("Client 1 : %s\n",usr1);
			strcpy(usr1,"-1");
		}

		if(strcmp(usr2,"exit")==0){
			shmdt(usr2);
			shmctl(id2, IPC_RMID,NULL);
			break;
		}
	}
}
