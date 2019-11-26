#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <wait.h>

int main()
{
  int pid;
  if((pid=fork())<0)
   {
     perror("fork failed!\n");
     return -1;
   }
  else if(pid==0)
   {
     printf("%d: child is exit now\n",getpid());
     return 0;
   }
  else
   {
     printf("%d: parent is running now\n",getpid());
	 while(1);
   }
	exit(0);
}
