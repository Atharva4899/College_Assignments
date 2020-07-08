#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++)       
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++)  
           if (arr[j] > arr[j+1]) 
              swap(&arr[j], &arr[j+1]); 
} 
  
/* Function to print an array */
void printArr(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n\n"); 
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
	printf("Enter 5 numbers to sort:\t"); //user input
	int i,arr[5];
	for(i=0;i<5;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int choice;
	printf("\nEnter 1 for Demo of Zombie, 2 for Orphan, and 0 to exit:\t");
	scanf("%d",&choice);
	
	//----------------------------------Zombie-----------------------------------
	
	if(choice==1)
	
	{
		int pid;
		pid=getpid();
		printf("\nCurrent Process id is:\t%d", pid);
		printf("\nForking...\n");
		
		pid=fork(); //call fork
		
		if(pid<0) //creation failed
		{
			printf("\nProcess creation failed!");
			exit(-1);
		}
		else if(pid==0) //child
		{
			printf("\nChild Process started!");
			printf("\nProcess ID is:\t%d", getpid());
			printf("\nParent Process ID is:\t%d\n", getppid());
			bubbleSort(arr,5);
			printf("\nSorted Array:\t");
			printArr(arr,5);
			printf("\nI am now a Zombie!\n");
			
		}
		else //parent
		{
			system("wait"); //wait for child
			
			printf("\nParent Process started!");
			printf("\nProcess ID is:\t%d", getpid());
			printf("\nParent Process ID is:\t%d\n", getppid());
			
			quicksort(arr,0,4);
			printf("\nSorted Array:\t");
			printArr(arr,5);
			
			printf("\n\n");
			system("ps -elf | grep a.out"); //print all processes
		}
	}
	
	//-----------------------------------------------------------------------
	//----------------------------Orphan-------------------------------------
	
	else if(choice==2)
	{
		int pid;
		pid=getpid();
		printf("\nCurrent Process id is:\t%d", pid);
		printf("\nForking...\n");
		
		pid=fork(); //calling fork
		
		if(pid<0) //creation failed
		{
			printf("\nProcess creation failed!");
			exit(-1);
		}
		else if(pid==0) //child
		{
			
			printf("\nChild Process started!");
			printf("\nProcess ID is:\t%d", getpid());
			printf("\nParent Process ID is:\t%d\n", getppid());
			
			bubbleSort(arr,5);
			printf("\nSorted Array:\t");
			printArr(arr,5);
			
			printf("---Child is sleeping---\n\n");
			sleep(5); //sleep child and go to parent
			
			printf("\n\n---Back in child---\n");
			printf("\nProcess ID is:\t%d", getpid());
			printf("\nParent Process ID is:\t%d\n\n", getppid());
			printf("I am now a Orphan!\n\n");
			
			system("ps -elf | grep a.out"); //print all processes
		}
		else
		{
			system("wait"); //wait for child
			
			printf("\nParent Process started!");
			printf("\nProcess ID is:\t%d", getpid());
			printf("\nParent Process ID is:\t%d\n", getppid());
			
			quicksort(arr,0,4);
			printf("\nSorted Array:\t");
			printArr(arr,5);
			
			printf("----Parent is dying----\n\n");
		}
	}
	
	//--------------------------------------------------------------------
	
	else if(choice==0)
		exit(0);
	else
		printf("\nInvalid Input\n");
	return 0;
}
