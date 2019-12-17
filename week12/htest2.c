#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	int pipefd[2];
	const char *msg = "h";
	char buf[65536];
	int count = -1;
	int stat=0;
	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		return 1;
	}
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return 2;
	}
	else if (id == 0)
	{
 
		close(pipefd[1]);
		stat=read(pipefd[0],buf,100);
		if(stat<=0){			
			_exit(0);
		}
		
		printf("childen read ok,%s,total %d\n",buf,stat);
		close(pipefd[0]);
		exit(0);
	}
	else
	{
 
		close(pipefd[0]);
		if((write(pipefd[1],"1234567890",10))>0){
			printf("parent write ok\n");
		}
		sleep(1);
		close(pipefd[1]);
		exit(0);
	}
	return 0;
}

