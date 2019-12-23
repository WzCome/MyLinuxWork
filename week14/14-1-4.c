#include "my.h"
#define NUM 4

typedef struct test{
	int num; 	
	int time;
}mytest;

void *fun(void *arg){
	pthread_t my_tid;
	mytest *y;
	int s=0;
	y=(mytest *)arg;
	for(int i=0;i<=y->n;i++)
		s+=i;
	my_tid=phtread_self();
	printf("\tThread %d: my tid is %ls,hello world \n",(int)y->num+1;my_tid);
	printf("\tThread %d: sun 1 to %d is %d\n",(int)y->num,y->time,s);
}

int main(){
	pthread_t tid;
	mytest a[4];
	int rv ,t;
	for(t=0;i<NUM;t++){
		a[i].num=t;
		a[t].time=100*(t+1);
		
		if(ret[i]!=0){
			printf("thread create failed\n");
			return 0;
		}
		pthread_join(tid[i],NULL);
	}
	return 0;
}
