#include <sys/ipc.h>
# define NULL 0
#include <sys/shm.h>
#include <sys/types.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
# include<ctype.h>
# include<string.h>
#include <sys/wait.h>
#include <stdio_ext.h>
// parent writing a char in shared memory and child reads it and prints it.
int main()
{
int pid;
char *a,*b,*y,filename[10];
int id,n,i,id1,sz,id2;
FILE *fp;
printf("Enter the file name : ");
scanf("%s",filename);
id=shmget(111,50,IPC_CREAT | 00666);
id1=shmget(112,50,IPC_CREAT | 00666);
y=shmat(id1,NULL,0);
a=shmat(id,NULL,0); 
fp = fopen(filename,"r");
fread(a,1,1000,fp);
y[0]='1';

shmdt(a);
shmdt(y);
fclose(fp);
}
