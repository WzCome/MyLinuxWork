#include "my.h"
void *worker(void *){
	int TID =pthread_self();
	printf("thread--%d:gettid retrun %d\n",TID,getpid());
	printf("thread--%d:pthread_self return %p\n",TID,(void *)pthread_self());
	printf("thread--%d:I will exit now.\n",TID);
	pthread_eixt(NULL);
	return NULL;

}

int main(){
	pthread_t tid =0;
	int ret;
	ret = pthread_create(&tid,NULL,worker,NULL);
	ret = pthread_join(tid ,NULL);
	ret = pthread_create(&tid,NULL,worker,NULL);
	ret = pthread_join(tid ,NULL);
	printf("ALL finished!\n");
	return 0;
}
