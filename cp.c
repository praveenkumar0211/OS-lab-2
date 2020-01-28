#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
void copy(int argc,char** argv);
void main(int argc,char** argv)
{	
	int choice;	
	printf("\n option: %s",argv[1]);
	printf("\nsource: %s",argv[2]);
	printf("\ndestination: %s",argv[3]);
	printf("\n");
	if(strcmp(argv[1],"i")==0)
	{
		int fdd=open(argv[3],O_RDONLY);
		//printf("%d",fdd);
		if(fdd!=0-1){
			printf("\n Do you want to overwrite and create a new file 1.yes 2.no");
			scanf("%d",&choice);
			if(choice==1)
			{
				int x=creat(argv[3],O_CREAT);
				copy(argc,argv);
			}
			else
			{	
				exit(1);
			}
			}
		else{
			int x=creat(argv[3],O_CREAT);
				copy(argc,argv);
		    }
	}
	else if(strcmp(argv[1],"f")==0)
	{
		printf("\nOverwriting the given file");
			int x=creat(argv[3],O_CREAT);
			copy(argc,argv);
	}
	else if(strcmp(argv[1],"n")==0)
	{
			int fd=open(argv[3],O_RDONLY);
			printf("%d",fd);
		if(fd!=-1)
		{
			printf("\n A No cobbler is set the file cant be overwritten");
			exit(1);
		}
		else
		{
			int x=creat(argv[3],O_CREAT);
			copy(argc,argv);
		}
	}	
}

void copy(int argc,char** argv){
	int fd=open(argv[2],O_RDONLY);
	if(fd==-1){
		printf("\nprocess failed");
		exit(1);
		}
	else{
		printf("\nsuccess in opening of the file");
	char *c=(char*)calloc(100,sizeof(char));
	int sz=read(fd,c,50);
	c[sz]='\0';
	printf("\n%s",c);
	int sd=open(argv[3],O_WRONLY);
	int sx=write(sd,c,50);
	close(sd);
	close(fd);}
	
}

