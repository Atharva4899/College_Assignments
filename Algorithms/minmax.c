#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void min_max(int arr[],int left,int right,int* min,int* max)
{
	int tot=right-left+1,mid;
	int minl,maxl,minr,maxr;
	
	switch(tot)
	{
		case 1:
			*min=arr[left];
			*max=arr[right];
			break;
		case 2:
			if(arr[left]>arr[right])
			{
				*min=arr[right];
				*max=arr[left];
			}
			else
			{
				*max=arr[right];
				*min=arr[left];
			}
			break;
		default:
			mid=(right+left)/2;
			min_max(arr,left,mid,&minl,&maxl);
			min_max(arr,mid+1,right,&minr,&maxr);
			
			if(minl<minr)
				*min=minl;
			else
				*min=minr;
				
			if(maxl>maxr)
				*max=maxl;
			else
				*max=maxr;
			break;
	}
}

int main()
{
	int n,i;
	printf("Enter total numbers:\t");
	scanf("%d",&n);
	
	int* arr=(int*)malloc(n*sizeof(int)),min,max;
	
	for(i=0;i<n;i++)
	{
		printf("Enter value %d : ",i+1);
		scanf("%d",(arr+i));
	}
	
	min_max(arr,0,n-1,&min,&max);
	
	printf("\nMin:%d\nMax:%d",min,max);
	
	return 0;
}