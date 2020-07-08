/*
 ============================================================================
 Name        : MergeSort.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define max 50
void merge(int[],int[],int,int,int);
void merge_pass(int[],int[],int,int);
void merge_sort(int[],int);
int main(void) {

	int a[10]={1,3,5,7,9,0,2,4,6,8};
	merge(a,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",a[i]);
	}
	return EXIT_SUCCESS;
}
void merge_sort(int arr[],int size)
{
	int length=1;
	int extra[max];
	while(length<size)
	{
		merge_pass(arr,extra,size,length);
		length*=2;
		merge_pass(extra,arr,size,length);
		length*=2;
	}
}
void merge_pass(int arr[],int sorted[],int size,int length)
{
	int i,j;
	for(i=0;i<size-2*length;i+=2*length)
	{
		merge(arr,sorted,i,i+length-1,2*length-1);
	}
	if(i+length<size)
	{
		merge(arr,sorted,i+length-1,size-1);
	}
	else
	{
		for(j=i;i<size;j++)
		{
			sorted[j]=arr[j];
		}
	}
}
void merge(int arr[],int sorted[],int i,int m,int n)
{
	int j,k=0,t;
	j=m+1;
	while(i<=m&&j<=n)
	{
		if(arr[i]<=arr[j])
		{
			sorted[k++]=arr[i++];
		}
		else
		{
			sorted[k++]=arr[j++];
		}
	}
	if(i>m)
	{
		for(t=j;t<n;t++)
		{
			sorted[k+t-j]=arr[j];
		}
	}
	else
	{
		for(t=i;t<=m;t++)
		{
			sorted[k+t-i]=arr[t];
		}
	}
}
