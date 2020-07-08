//-----------------------------------------------------------------------------------------------
//				Assignment 4
//	Roll no. : 33341
//	Batch	 : M11
//-----------------------------------------------------------------------------------------------


#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

int x=10,i;
int a[5];
sem_t mutex11,empty,full;


void* producer(void* para)
{
	while(1)
	{
		int pno=(int*) para;
		
		sem_wait(&empty);
		sem_wait(&mutex11);
		
		x++;
		x%=5;
		a[x]=x*3;
		
		printf("\nProducer %d produces the item %d\nThe buffer is \t[",pno,a[x]);
		
		for(i=0;i<5;i++)
		{
			printf(" %d ",a[i]);
		}
		printf("]\n");
		
		sem_post(&mutex11);
		sem_post(&full);
		
		sleep(2);
	}
}
 
void* consumer(void* para)
{
	while(1)
	{
		int cno=(int*) para;
		
		sem_wait(&full);
		sem_wait(&mutex11);
		printf("\nConsumer %d consumes item %d\n",cno,a[x]);
		
		a[x]=-1;
		x--;
		
		printf("The buffer is \t[");
		for(i=0;i<5;i++)
		{
			printf(" %d ",a[i]);
		}
		printf("]\n");
		
		sem_post(&mutex11);
		sem_post(&empty);
		
		sleep(2);
	}
}

int main()
{
	sem_init(&mutex11,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,5);
	
	pthread_t tidp[5],tidc[5];
	
	for(i=0;i<5;i++)
	{
		a[i]=-1;
	}
	
	printf("\nThe initial state of buffer is \t[");
	for(i=0;i<5;i++)
	{
		printf(" %d ",a[i]);
	}
	printf("]\n");
	
	for(i=0;i<5;i++)
	{
		pthread_create(&tidp[i],NULL,producer,(void*)i);
		pthread_create(&tidc[i],NULL,consumer,(void*)i);
	}
	
	for(i=0;i<5;i++)
	{
		pthread_join(tidp[i],NULL);
		pthread_join(tidc[i],NULL);
	}
	
	pthread_exit(NULL);

	return 0;
}
