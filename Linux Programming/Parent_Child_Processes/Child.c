#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void binary_search(int s[],int total)
{
	int left=0,right=total-1,middle,query;
	printf("\nEnter number to be searched:\t"); // user input
	scanf("%d", &query);

	while(left<=right)
	{
		middle=(left+right)/2;
		
		if(s[middle]<query) //element in right side
		{
			left=middle+1;
		}
		else if(s[middle]>query) //element in right side
		{
			right=middle-1;
		}
		else //element found
		{
			printf("Found at location %d\n",middle+1);
			return;
		}
	}
	printf("\nElement not found!!\n");
}

void printArr(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d", arr[i]); 
    printf("\n\n"); 
} 

int main(int argc,char* argv[], char *envp[])
{
	printf("\nIn Child Process started by execv....\n");

	int arr[10];
	int i,query;

	for(i=0;i<5;i++) //convert back to integer
	{
		arr[i]=strtol(argv[i+1],NULL,10);
	}
	binary_search(arr,5); //search
}
