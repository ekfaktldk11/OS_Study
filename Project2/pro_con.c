#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

void* producer(void* arg);
void* consumer(void *arg);

int buffer[100]; // the buffer size
int in= -1; // the index that producer's produced items were inserted
int out= -1; // the index that consumer will be get
int count= 0; // the number of the existed items

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

pthread_cond_t buffer_has_space = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t buffer_has_data = PTHREAD_MUTEX_INITIALIZER;

int main(void){
	int i;
	
	// create two threads
	pthread_t threads[2];
	pthread_create(&threads[0], NULL, producer, NULL);
	pthread_create(&threads[1], NULL, consumer, NULL);

	// wait for joining of two threads
	for(i=0; i<2; i++) pthread_join(threads[i], NULL);
	
	// kill the threads
	pthread_cond_destroy(&buffer_has_space);
	pthread_cond_destroy(&buffer_has_data);

	pthread_exit(NULL);
	return 0;

}

void* producer(void* arg){
	int i;
	for(i=0; i<500; i++){
		printf("producer data = %d\n",i);
		//printf("producer count = %d\n", count);

		// wait for consumer if there is no empty_slot
		pthread_mutex_lock(&mutex);

		if(count == 100) pthread_cond_wait(&buffer_has_space,&mutex);

		in++;
		count++;
		in %= 100;
		buffer[in] = i;

		pthread_cond_signal(&buffer_has_data);
		pthread_mutex_unlock(&mutex);
	}
}

void* consumer(void* arg){
        int i, data;
        for(i=0; i<500; i++){
		pthread_mutex_lock(&mutex);
		
		if(count == 0) pthread_cond_wait(&buffer_has_data, &mutex);

                out++;
		count--;
                out %= 100;
                data = buffer[out];

		pthread_cond_signal(&buffer_has_space);

		pthread_mutex_unlock(&mutex);

		printf("              consumer data = %d\n",data);
		//printf("              consumer count = %d\n", count);

        }
}




