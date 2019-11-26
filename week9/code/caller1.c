#include "my.h"
int main()
{
    int ret;
    printf("caller1:pid=%d,ppid=%d\n",getpid(),getppid());
    ret=system("/home/wz/桌面/week9");
	printf("after calling");
    sleep(1);
    return 0;
}
