#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 100
int m[MAX];
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

int main(){
urand(m);
printf("%d\n",max(m));
return 0;
}
