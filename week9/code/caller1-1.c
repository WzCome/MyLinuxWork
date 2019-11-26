#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{ execl("/home/wz/桌面/week9/test1-1","123","456",NULL);
    int ret;
    printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
   
	printf("after calling");
    sleep(1);
    return 0;
}
