#include "my.h"

void sighandler(int signo)
{
	printf("parent catch a SIGPIPE signal and signum=%d\n",signo);
}
int main(){
	int fd[2];
	pid_t pid;
	pipe(fd);
	pid=fork();
	if(pid==-1){
		fprintf(stderr,"fork error (%s)\n",strerror(errno));
		exit(-3);	
	}
	else if(pid==0){
		fprintf(stdout,"child i will close the last read ebd of pipe.pid=%d,ppid=%d\n",getpid(),getppid());
		close(fd[0]);
	}
	else{
		close(fd[0]);
		sleep(5);
		int ret;
		ret=write(fd[1],"hello",6);
		if(ret==-1){
			fprintf(stderr,"parent write error %s \n",strerror(errno));
		}
		return 0;
	}
}
