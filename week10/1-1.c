#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static void fun1(void){
	printf("invoked callbackfun!\n");
}

int main(){
	FILE*fp;
	char buf[]="HELLO    ";
	atexit(fun1);
	printf("%s",buf);
	if((fp=fopen("text.txt","w+"))==NULL){
		perror("fail to open\n");
		return -1;
	}
	if(fputs(buf,fp)==EOF){
		perror("fail to fputs\n");
		return -1;
	}
	return 0;
}
