/*
 ============================================================================
 Name        : Search_Sort.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{
	int r_no;
	char name[50];
	float perc;
};
void add(struct student*[],int);
void display(struct student*[],int);
void bubble(struct student*[],int,int);
void selectsort(struct student* [],int);
int binsr(struct student* [],int,int);
int binsrec(struct student* [],int,int,int,int);
int compare(int,int);

int main(void) {
	setvbuf( stdout, NULL, _IONBF, 0 );
	struct student* s[50];
	int size;
	int flag=0,query,pos;
	int choice,cont;
	do
	{
		printf("MENU:\n\t1.Add Record\n\t2.Bubble Sort\n\t3.Selection Sort\n\t4.Binary Search\n\t5.Exit");
		printf("\nEnter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				do
				{
					printf("\nEnter number of records:\t");
					scanf("%d",&size);
					if(size<=0)
					{
						printf("Invalid Input!");
					}
				}while(size<=0);
				add(s,size);
				flag=1;
				display(s,size);
				puts("To continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 2:
				if(flag!=0)
				{
					bubble(s,size,0);
					printf("\nSorted:\n");
					display(s,size);
					puts("To continue press 1 else 0");
					scanf("%d",&cont);
				}
				else
				{
					printf("No records entered!!\n");
					cont=1;
				}
			break;
			case 3:
				if(flag!=0)
				{
					selectsort(s,size);
					printf("\nSorted:\n");
					display(s,size);
					puts("To continue press 1 else 0");
					scanf("%d",&cont);
				}
				else
				{
					printf("No records entered!!\n");
					cont=1;
				}
			break;
			case 4:
				if(flag!=0)
				{
					printf("\nEnter Roll Number to be searched:\t");
					scanf("%d",&query);
					bubble(s,size,1);
					pos=binsr(s,query,size);
					if(pos!=-1)
					{
						printf("\nRecord Found!");
						printf("\nR.No:%d",s[pos]->r_no);
						printf("\nName:%s",s[pos]->name);
						printf("\nPercentage:%f",s[pos]->perc);
						printf("\n\n");
					}
					else
						printf("Record not found!");
					puts("To continue press 1 else 0");
					scanf("%d",&cont);
				}
				else
				{
					printf("No records entered!!\n");
					cont=1;
				}
			break;
			case 5:
				cont=0;
				break;
			default:
				printf("\tInvalid Input!!\n");
				cont=1;
		}
	}while(cont==1);

	return EXIT_SUCCESS;
}
void add(struct student* s[],int size)
{
	int i,j,flag;
	for(i=0;i<size;i++)
		s[i]=(int*)malloc(size*sizeof(int));
	for(i=0;i<size;i++)
	{
		do
		{
			flag=0;
			do
			{
				printf("\nEnter roll no:\t");
				scanf("%d",&s[i]->r_no);
				if(s[i]->r_no<=0)
				{
					printf("Invalid Input!");
				}
			}while(s[i]->r_no<=0);
			for(j=0;j<i;j++)
				if(s[i]->r_no==s[j]->r_no)
				{
					printf("\nInvalid Input!!");
					flag=1;
					break;
				}
		}while(flag==1);
		printf("\nEnter name:\t");
		scanf("\n");
		gets(s[i]->name);
		printf("\nEnter percentage:\t");
		scanf("%f",&s[i]->perc);
		printf("\n");
	}
}
void display(struct student* s[],int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("R.No:%d",s[i]->r_no);
		printf("\nName:%s",s[i]->name);
		printf("\nPercentage:%f",s[i]->perc);
		printf("\n\n");
	}
}
void bubble(struct student* s[],int size,int flag)
{
	int sorted=0;
	int last=size-1;
	int swap,check;
	struct student* temp;
		for(int i=0;i<last&&!sorted;i++)
		{
			sorted=1;
			swap=0,check=0;
			for(int j=last;j>i;j--)
				{
					check++;
					if(s[j-1]->r_no >s[j]->r_no)
						{
							temp=s[j-1];
							s[j-1]=s[j];
							s[j]=temp;
							sorted=0;
							swap++;
						}
					if(flag==0)
					{
						printf("Checks:\t%d\tSwap:\t%d\n",check,swap);
						display(s,size);
					}
				}
		}
}
void selectsort(struct student* s[50],int size)

{
	int i;
	struct student* temp;
	for(i=0;i<size-1;i++)
	{
		int check=0;
		int swap=0;
		int max=i;
		for(int j=i+1;j<size;j++)
		{
			if(strcmp(s[j]->name,s[max]->name)>0)
			{
				max=j;
				check++;
			}
		}
		if(max!=i)
		{
			temp=s[i];
			s[i]=s[max];
			s[max]=temp;
			swap++;
		}
		printf("Checks:\t%d\tSwap:\t%d\n",check,swap);
		display(s,size);
	}
}
int binsr(struct student* s[50],int query,int n)
{
	int left=0;
	int right=n-1;
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		switch(compare(s[middle]->r_no,query))
		{
		case -1:
			left=middle+1;
			printf("Left=%d,Right=%d,Middle=%d,Middle value=%d\n",left,right,middle,s[middle]->r_no);
			break;
		case 0:
			printf("Left=%d,Right=%d,Middle=%d,Middle value=%d\n",left,right,middle,s[middle]->r_no);
			return middle;
			break;
		case 1:
			right=middle-1;
			printf("Left=%d,Right=%d,Middle=%d,Middle value=%d\n",left,right,middle,s[middle]->r_no);
			break;
		}

	}
	return -1;
}
int compare(int mid,int que)
{
	if(mid<que)
		return -1;
	else if(mid==que)
		return 0;
	else
		return 1;
}
int binsrec(struct student* s[],int size,int query,int left,int right)
{
	int middle;
	if(left<=right)
	{
		middle=(left+right)/2;
		switch(compare(s[middle]->r_no,query))
		{
			case -1:
				left=middle+1;
				printf("Left=%d,Right=%d,Middle=%d,Middle value=%d\n",left,right,middle,s[middle]->r_no);
				binsrec(s,size,query,left,right);
				break;
			case 0:
				printf("Left=%d,Right=%d,Middle=%d,Middle value=%d\n",left,right,middle,s[middle]->r_no);
				return middle;
				break;
			case 1:
				right=middle-1;
				printf("Left=%d,Right=%d,Middle=%d,Middle value=%d\n",left,right,middle,s[middle]->r_no);
				binsrec(s,size,query,left,right);
				break;
		}
	}
	return -1;
}
