#include "head.h"
void urand(int *a){
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<MAX;i++){
		a[i]=(int)(rand()%1000+1);
	}
}

int max(int *a){
int i;
int smax=-1;
for(i=0;i<MAX;i++){
		if(a[i]>smax)
{
smax=a[i];
}
	}
return smax;
}

int sum(int *a){
	int i,sum=0;
	for(i=0;i<MAX;i++){
		sum=sum+a[i];
	}
return sum;
}
