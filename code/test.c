#include"/home/wz/桌面/homework/test7/head.h"
#include<stdlib.h>
#include<dlfcn.h>
int main()
{
int m[MAX];
void * handle;
int(*f1)();
int(*f2)();
int(*f3)();
char *error;
handle=dlopen("/home/wz/桌面/homework/test7/libtest.so",RTLD_LAZY);
if(!handle)
{
perror("load failed!\n");
exit(1);
}
f1=dlsym(handle,"max");
if((error=dlerror())!=NULL)
{
fprintf(stderr,"%s\n",error);
exit(1);
}

f2=dlsym(handle,"sum");
if((error=dlerror())!=NULL)
{
fprintf(stderr,"%s\n",error);
exit(1);
}

f3=dlsym(handle,"urand");
if((error=dlerror())!=NULL)
{
fprintf(stderr,"%s\n",error);
exit(1);
}

f3(m);
printf("max=%d\n",f1(m));
printf("sum=%d\n",f2(m));
return 0;
}
