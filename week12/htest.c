#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	int pipefd[2];
	const char *msg = "h";
	int count = -1;
	char buf[65536];
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
 
		close(pipefd[0]);
		
		while (1)
		{
			stat=write(pipefd[1],msg,strlen(msg));
			if(stat<=0){			
				_exit(0);
			}
			count++;
			//printf("%d\n",count);
		}
		close(pipefd[1]);
		exit(0);
	}
	else
	{
 
		close(pipefd[1]);
		sleep(1);
		stat=read(pipefd[0],buf,65536);
		printf("parent read ok,%s,total %d\n",buf,stat);
		close(pipefd[0]);
		exit(0);
	}
	return 0;
}

