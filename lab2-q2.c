#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#define MILLION 1000000
pthread_mutex_t mutx;
struct timeval tlast1, tlast2;
struct timeval tthis1, tthis2;
void *Count(void *a){
	int i;
	int count=0;
	for(i=0;i<10000;i++){
		count++;
	}
	gettimeofday(&tthis1,NULL);
}
void *Count2(void *a){
	pthread_mutex_lock(&mutx);
        int i;
        int count=0;
        for(i=0;i<10000;i++){
                count++;
        }
        gettimeofday(&tthis2,NULL);
	pthread_mutex_unlock(&mutx);

}

int main(){
	pthread_t threads[10];
	int b, c;
	int result[10];
	int i;
	gettimeofday(&tlast1,NULL);
	for(i=0;i<10;i++){
		c=pthread_create(&threads[i],NULL,&Count,(void *)&b);
	}
	for(i=0;i<10;i++){
		c=pthread_join(threads[i],(void **)&result[i]);
	}
//        for(i=0;i<10;i++){
//                pthread_exit(threads[i],NULL);
//        }

	printf("unlock time: %ld",MILLION*(tthis1.tv_sec-tlast1.tv_sec)+tthis1.tv_usec-tlast1.tv_usec);
	gettimeofday(&tlast2,NULL);
        for(i=0;i<10;i++){
               c=pthread_create(&threads[i],NULL,&Count2,(void *)&b);
        }
        for(i=0;i<10;i++){
               c=pthread_join(threads[i],(void **)&result[i]);
        }
        printf("lock time: %ld",MILLION*(tthis2.tv_sec-tlast2.tv_sec)+tthis2.tv_usec-tlast2.tv_usec);

	return 0;
}
