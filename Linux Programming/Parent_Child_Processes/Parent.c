#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Function to print an array */
void printArr(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 
  
void quicksort(int number[],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      j=last;

      while(i<j)
      {
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j)
         {
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

int main()
{
	
	int i,arr[5];
	char* arr1[10];
	
	for(i=0;i<10;i++) //dynamic memory allocation
	{
		arr1[i]=(char*) malloc(20);
	}
	
	printf("Enter 5 numbers to sort:\t");

	for(i=0;i<5;i++) //get user input
	{
		scanf("%d",&arr[i]);
	}
	
	int srno;

	int pid;
	pid=getpid();
	printf("\nCurrent Process id is:\t%d", pid);
	printf("\nForking....................\n\n");
	
	pid=fork();	//fork
	
	if(pid<0) //process creation failed
	{
		printf("\nProcess creation failed!");
		exit(-1);
	}
	else if(pid==0) //child process
	{
		
		printf("\nChild Process started!");
		printf("\nProcess ID is:\t%d", getpid());
		printf("\nParent Process ID is:\t%d\n", getppid());

		quicksort(arr,0,4); //sort array
		printf("\nSorted Array:\t");
		printArr(arr,5);

		for(i=0;i<5;i++) //convert to character
		sprintf(arr1[i+1],"%d",arr[i]);
		
		arr1[0]="./child";
		arr1[6]=NULL;
		
		printf("\nNow starting process created by execv................\n");

		execv("./child",arr1); // calling other process through execv

		printf("\n\n........Child is dying...............\n");
		
	}
	else
	{
		system("wait");

		printf("\nParent Process started!");
		printf("\nProcess ID is:\t%d", getpid());
		printf("\nParent Process ID is:\t%d\n", getppid());
		
		printf("\n\n........Parent is dying...............\n");
		
	}
}
