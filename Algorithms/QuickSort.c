/*
 ============================================================================
 Name        : QuickSort.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   :
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct customer
{
	char name[20];
	char mobile[11];
	float bill;
};
void input(struct customer [],int);
int val(struct customer[],int);
void display(struct customer [],int);
void quicksort(struct customer [],int,int,int);
int split(struct customer [],int,int,int);
void swap(struct customer[],int,int);
int main(void)
{
	setvbuf( stdout, NULL, _IONBF, 0 );
	struct customer c[20];
	int no;
	do
	{
		printf("Enter number of records:\t");
		scanf("%d",&no);
		if(no<=1)
			printf("Invalid!!");
	}while(no<=1);
	input(c,no);
	printf("\nRecords are:");
	printf("\nName\t\t\tMobile\t\t\tBill");
	display(c,no);
	printf("\n\n");
	quicksort(c,no,0,(no-1));
	printf("\nSorted in Descending Order:");
	printf("\nName\t\t\tMobile\t\t\tBill");
	display(c,no);
	return EXIT_SUCCESS;
}
void input(struct customer c[],int no)
{
	for(int i=0;i<no;i++)
	{
		printf("\nEnter name:\t");
		scanf("%s",c[i].name);
		do
		{
			printf("\nEnter mobile number:\t");
			scanf("%s",c[i].mobile);
		}while(val(c,i));
		printf("\nEnter Bill Amount:\t");
		scanf("%f",&c[i].bill);
	}
}
int val(struct customer c[],int i)
{
	if(strlen(c[i].mobile)!=10)
	{
		printf("Invalid Mobile Number!");
		return 1;
	}
	for(int k=0;k<i;k++)
	{

		if(strcmp(c[k].mobile,c[i].mobile)==0)
		{
			printf("\nMobile Number already exists!");
			return 1;
		}
	}
	return 0;
}
void display(struct customer c[],int size)
{

	for(int i=0;i<size;i++)
	{
		printf("\n%s\t\t\t%s\t\t%f",c[i].name,c[i].mobile,c[i].bill);
	}
}
void quicksort(struct customer c[],int size,int left,int right)
{
	int pos;
	if(left<right)
	{
		pos=split(c,size,left,right);
		swap(c,left,pos);
		printf("\tPivot:%s\tPivot Position:%d",c[pos].name,pos);
		printf("\nName\t\t\tMobile\t\t\tBill");
		display(c,size);
		printf("\n");
		quicksort(c,size,left,pos-1);
		quicksort(c,size,pos+1,right);
	}
}
int split(struct customer c[],int size,int left,int right)
{
	int i=left;
	int j=right+1;
	int count=0;
	int swapct=0;
	char pivot[20];
	strcpy(pivot,c[left].name);
	do{
		do{
			i++;
			count++;
		}while(strcmp(c[i].name,pivot)>=0);
		do{
			j--;
			count++;
		}while(strcmp(c[j].name,pivot)<0);
		if(i<j)
		{
			swap(c,j,i);
			swapct++;
		}
	}while(i<j);
	printf("\nChecks:%d\tSwaps:%d",count,swapct);
	return j;
}
void swap(struct customer c[],int p1,int p2)
{
	struct customer temp;
	temp=c[p1];
	c[p1]=c[p2];
	c[p2]=temp;
}
