//-----------------------------------------------------------------------------------------------
//				Assignment 5
//	Roll no. : 33341
//	Batch	 : M11
//-----------------------------------------------------------------------------------------------


#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

sem_t mutex,wrt;
int rcount=0,data=5;

void* writer(void* para)
{
	do
	{
		sem_wait(&wrt);
		data++;
		printf("Writer has written data %d\n", data);
		
		sleep(1);
		sem_post(&wrt);
		sleep(1);
	}while(1);
}

void* reader(void* para)
{
	do
	{
		sem_wait(&mutex);
		rcount++;
		
		if(rcount==1)
			sem_wait(&wrt);
			
		sem_post(&mutex);
		printf("Reader has read data %d\n", data);
		sleep(1);
		sem_wait(&mutex);
		
		rcount--;
		if(rcount==0)
			sem_post(&wrt);
		sem_post(&mutex);
		sleep(1);
	}while(1);
}

int main()
{
	pthread_t r,w;
	
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	
	pthread_create(&w,NULL,writer,NULL);
	pthread_create(&r,NULL,reader,NULL);
	
	pthread_join(r,NULL);
	pthread_join(w,NULL);
}
