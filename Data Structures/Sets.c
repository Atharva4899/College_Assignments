/*
 ============================================================================
 Name        : Asgn1_FINAL.c
 Author      : Atharva Kulkarni
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int unn(int[],int[],int[],int,int);
int intr(int[],int[],int[],int,int);
int diff(int[],int[],int[],int,int);
void display(int[],int[],int,int);
void getset(int[],int[],int);

int i,j,k;
int main(void)
{
	int set1[50],set2[50],inter[50],u[50],diff1[50],diff2[50],sdiff[50],univ[100];
	int e1,e2,a,l,d1,d2,cont,choice;
	for(i=0;i<100;i++)
		univ[i]=i;
	printf("Enter number of elements in set1 and set2\n");
	scanf("%d%d",&e1,&e2);
	printf("Enter elements of set 1:\n");
	getset(set1,univ,e1);
	printf("Enter elements of set 2:\n");
	getset(set2,univ,e2);
	display(set1,set2,e1,e2);
	do
	{
		puts("\nMENU:\n1.Union\n2.Intersection\n3.Difference\n4.Symmetric Difference");
		fflush(0);
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				display(set1,set2,e1,e2);
				a=unn(set1,set2,u,e1,e2);
				printf("\nUnion:\n{");
				for(i=0;i<a;i++)
					printf("%d ",u[i]);
				puts("}\nTo continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 2:
				display(set1,set2,e1,e2);
				k=intr(set1,set2,inter,e1,e2);
				printf("\nIntersection:\n{");
				for(i=0;i<k;i++)
					printf("%d ",inter[i]);
				puts("}\nTo continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 3:
				display(set1,set2,e1,e2);
				k=intr(set1,set2,inter,e1,e2);
				d1=diff(set1,diff1,inter,e1,k);
				printf("\nSet1-Set2:\n{");
				for(i=0;i<d1;i++)
					printf("%d ",diff1[i]);
				d2=diff(set2,diff2,inter,e2,k);
				printf("}\nSet2-Set1:\n{");
				for(i=0;i<d2;i++)
					printf("%d ",diff2[i]);
				puts("}To continue press 1 else 0");
				scanf("%d",&cont);
			break;
			case 4:
				display(set1,set2,e1,e2);
				k=intr(set1,set2,inter,e1,e2);
				d1=diff(set1,diff1,inter,e1,k);
				d2=diff(set2,diff2,inter,e2,k);
				l=unn(diff1,diff2,sdiff,d1,d2);
				printf("\nSymmetric Difference is:\n{");
				for(i=0;i<l;i++)
					printf("%d ",sdiff[i]);
				puts("}\nTo continue press 1 else 0");
				scanf("%d",&cont);
			break;
		}
	}while(cont==1);
	return EXIT_SUCCESS;
}
void getset(int set[],int univ[],int e)
{
	int temp,flag=1;
	for(i=0;i<e;i++)
	{
		do
		{
			flag=1;
			scanf("%d",&temp);
			for(k=0;k<100;k++)
			{
				if(univ[k]==temp)
				{
					flag=1;
					break;
				}
				else
				{
					flag=0;
				}
			}
			if(flag==0)
			{
				printf("Element outside of Universal Set,enter other value:");
			}
			for(j=0;j<i;j++)
			{
				if(set[j]==temp)
				{
					printf("Duplicate element,enter another value:");
					flag=0;
					break;
				}
			}
		}while(flag==0);

		if(flag==1)
			set[i]=temp;
	}
}

void display(int set1[],int set2[],int e1,int e2)
{
	printf("Set1:\n{");
	for(i=0;i<e1;i++)
		printf("%d ",set1[i]);
	printf("}\nSet2:\n{");
	for(i=0;i<e2;i++)
		printf("%d ",set2[i]);
	printf("}\n");
}
int unn(int set1[],int set2[],int u[],int e1,int e2)
{
	int a=e1;
	for(i=0;i<e1;i++)
		u[i]=set1[i];
	for(j=0;j<e2;j++)
	{
		int flag=0;
		for(i=0;i<e1;i++)
		{
			if(u[i]==set2[j])
				flag=1;
		}
		if(flag==0)
		{
			u[a]=set2[j];
			a++;
		}
	}
	return a;
}
int intr(int set1[],int set2[],int inter[],int e1,int e2)
{
	k=0;
	for(i=0;i<e1;i++)
	{
		for(j=0;j<e2;j++)
		{
			if(set1[i]==set2[j])
			{
				inter[k]=set1[i];
				k++;
			}
		}
	}
	return k;
}

int diff(int set[],int diff[],int inter[],int e,int k)
{
	int d=0;
	for(i=0;i<e;i++)
	{
		int flag=0;
		for(j=0;j<k;j++)
		{
			if(inter[j]==set[i])
				flag=1;
		}
			if(flag==0)
			{
				diff[d]=set[i];
				d++;
			}
	}
	return d;
}

