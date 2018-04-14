#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

volatile int s=0;//Variável compartilhada
volatile int vez=0;
volatile int interesse[2]={0,0};

void* f_thread_0(void *v){
	int i;
	for(i=0;i<1e8;i++){
		interesse[0]=1;
		//sleep(1);
		while(interesse[1])
			if(vez!=0){
				interesse[0]=0;
				while(vez!=0);
				interesse[0]=1;
			}
		s=0;
		if(s!=0)printf("Thread 0,s= %d.\n",s);
		vez=1;
		interesse[0]=0;
		//sleep(1);
	}
	return NULL;
}

void* f_thread_1(void *v)
{
	int i;
	for(i=0;i<1e8;i++){
		interesse[1]=1;
		while(interesse[0])
			if(vez!=1){
				interesse[1]=0;
				while(vez!=1);
				sleep(1);
				interesse[1]=1;
			}
		s=1;
		if(s!=1)printf("Thread 1,s= %d.\n",s);
		vez=0;
		interesse[1]=0;
	}
	return NULL;

}

int main(){
	pthread_t thr0,thr1;
    pthread_create(&thr1,NULL,f_thread_1,NULL);
    pthread_create(&thr0,NULL,f_thread_0,NULL);
    pthread_join(thr0,NULL);pthread_join(thr1,NULL);
    
    return 0;
}
