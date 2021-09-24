#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int buffer[100];
int in= -1;
int out= -1;
int count= 0;

void* producer(void* arg);
void* consumer(void *arg);

int main(void){
	int i;

	pthread_t threads[2];
	pthread_create(&threads[0], NULL, producer, NULL);
	pthread_create(&threads[1], NULL, consumer, NULL);

	for(i=0; i<2; i++) pthread_join(threads[i], NULL);

	pthread_exit(NULL);

	return 0;

}

void* producer(void* arg){
	int i;
	for(i=0; i<500; i++){
		printf("producer data = %d\n",i);
		printf("producer count = %d\n", count);
		in++;
		count++;
		in %= 100;
		buffer[in] = i;
	}
}

void* consumer(void* arg){
        int i, data;
        for(i=0; i<500; i++){
                
                out++;
		count--;
                out %= 100;
                data = buffer[out];

		printf("              consumer data = %d\n",data);
		printf("              consumer count = %d\n", count);

        }
}




