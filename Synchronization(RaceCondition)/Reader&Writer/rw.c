#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

sem_t wrt; // a semaphore that used in the writer section
pthread_mutex_t mutex; // mutual exclusive
int numreader = 0; // the # of reader

void* writer(void* wno)
{
	sem_wait(&wrt);
	printf("Writer %d is in the critical section\n", *((int *)wno));
	sem_post(&wrt);
}
void* reader(void* rno)
{
	pthread_mutex_lock(&mutex);
	numreader++;
	if(numreader == 1) { // the first reader in the section
		printf("Reader %d said 'I am the first reader!'\n",*((int *)rno));
		sem_wait(&wrt);
	}
	pthread_mutex_unlock(&mutex);
	printf("Reader %d: is in the critical section\n",*((int *)rno));

	pthread_mutex_lock(&mutex);
	numreader--;
	if(numreader == 0){ // the last reader in the section
		printf("Reader %d said 'I am the last reader!'\n",*((int *)rno));
	    	sem_post(&wrt);
	}
	pthread_mutex_unlock(&mutex);
}

int main(){
	pthread_t read[10], write[5]; // total reader : 10 / writer : 5
	pthread_mutex_init(&mutex, NULL);
	sem_init(&wrt,0,1);

	int a[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i = 0; i < 10; i++) pthread_create(&read[i], NULL, reader,(void*)&a[i]);
	for(int i = 0; i < 5; i++) pthread_create(&write[i], NULL, writer,(void*)&a[i]);
	for(int i = 0; i < 10; i++) pthread_join(read[i], NULL);
	for(int i = 0; i < 5; i++) pthread_join(write[i], NULL);

	// kill the mutex, semaphore
	pthread_mutex_destroy(&mutex);
	sem_destroy(&wrt);

	return 0;

}

