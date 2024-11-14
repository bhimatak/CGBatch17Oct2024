#include <pthread.h> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t lock; // name for the mutex lock
						// global it can be accessable within
						// sub programs

int shared_counter = 0; // Shared resource 

void* increment(void* arg) {
	pthread_mutex_lock(&lock); 
	for (int i = 0; i < 100000; ++i) { 
	printf("\n%d",shared_counter);
	shared_counter++; // Race condition
	// sleep(1); 
	} 
	pthread_mutex_unlock(&lock);
	return NULL; 
}

int main() 
{ 
	pthread_t t1, t2;
	if(pthread_mutex_init(&lock,NULL))
	{
		perror("pthread_mutex_init: ");
		return 1;
	} 
	// Create two threads 
	pthread_create(&t1, NULL, increment, NULL); 
	pthread_create(&t2, NULL, increment, NULL); 
	// Wait for both threads to finish 
	pthread_join(t1, NULL); 
	pthread_join(t2, NULL); 
	// increment(NULL);
	// increment(NULL);
	
	printf("Final counter value: %d\n", shared_counter);
	pthread_mutex_destroy(&lock);  
	
	return 0; 
} 