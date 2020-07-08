/*
 ============================================================================
 Name        : SparseMatrix.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
	int row;
	int col;
	int val;
}sparse;
void input(int[][MAX],int,int);
void createSparse(int[][MAX],sparse[],int,int);
void display(sparse[]);
void displayMatrix(int[][MAX],int,int);
void add(sparse[],sparse[],sparse[]);
void simpleTrans(sparse[],sparse[]);
void fastTrans(sparse[],sparse[]);

int main(void) {
	setvbuf( stdout, NULL, _IONBF, 0 );
	sparse s1[MAX],s2[MAX],addition[MAX],trans[MAX],ftrans[MAX];
	int arr1[MAX][MAX]={0},arr2[MAX][MAX]={0};
	int cont,choice,flag;
	int row,col;
	do
	{
		printf("MENU:\n\t1.Addition\n\t2.Simple Transpose\n\t3.Fast Transpose\n\t4.Exit");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter total rows and columns in the Matrix1:\t");
			do
			{
				flag=0;
				scanf("%d %d",&row,&col);
				if(row<=0||col<=0)
				{
					printf("Invalid Dimensions!!");
					flag=1;
				}
			}while(flag==1);
			input(arr1,row,col);
			createSparse(arr1,s1,row,col);
			printf("Matrix is :\n");
			displayMatrix(arr1,row,col);
			printf("Sparse Table is :\n");
			display(s1);
			printf("Enter total rows and columns in the Matrix2:\t");
			do
			{
				flag=0;
				scanf("%d %d",&row,&col);
				if(row<=0||col<=0)
				{
					printf("Invalid Dimensions!!");
					flag=1;
				}
			}while(flag==1);
			input(arr2,row,col);
			createSparse(arr2,s2,row,col);
			printf("Matrix is :\n");
			displayMatrix(arr2,row,col);
			printf("Sparse Table is :\n");
			display(s2);
			if(s1[0].row==s2[0].row&&s1[0].col==s2[0].col)
			{
				add(s1,s2,addition);
				printf("\nAddition:\n");
				display(addition);
			}
			else
			{
				printf("\nAddition not possible!\n");
			}
			printf("Press 1 for Menu, 0 to Exit:\t");
			scanf("%d",&cont);
			break;
		case 2:
			printf("Enter total rows and columns in the Matrix:\t");
			do
			{
				flag=0;
				scanf("%d %d",&row,&col);
				if(row<=0||col<=0)
				{
					printf("Invalid Dimensions!!");
					flag=1;
				}
			}while(flag==1);
			input(arr1,row,col);
			createSparse(arr1,s1,row,col);
			printf("Matrix is :\n");
			displayMatrix(arr1,row,col);
			printf("Sparse Table is :\n");
			display(s1);
			printf("\nTranspose:\n");
			simpleTrans(s1,trans);
			display(trans);
			printf("Press 1 for Menu, 0 to Exit:\t");
			scanf("%d",&cont);
			break;
		case 3:
			printf("Enter total rows and columns in the Matrix:\t");
			do
			{
				flag=0;
				scanf("%d %d",&row,&col);
				if(row<=0||col<=0)
				{
					printf("Invalid Dimensions!!");
					flag=1;
				}
			}while(flag==1);
			input(arr1,row,col);
			createSparse(arr1,s1,row,col);
			printf("Matrix is :\n");
			displayMatrix(arr1,row,col);
			printf("Sparse Table is :\n");
			display(s1);
			printf("\nTranspose:\n");
			fastTrans(s1,ftrans);
			display(ftrans);
			printf("Press 1 for Menu, 0 to Exit:\t");
			scanf("%d",&cont);
			break;
		case 4:
			cont=0;
			break;
		default:
			printf("Invalid Input!\n");
			cont=1;
		}
	}while(cont==1);
	return EXIT_SUCCESS;
}

void input(int a[][MAX],int row,int col)
{
	int flag=0;
	int trow,tcol,tval;
	int nonzero;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			a[i][j]=0;
		}
	}
	do
	{
		flag=0;
		printf("\nEnter total nonzero elements:\t");
		scanf("%d",&nonzero);
		if(nonzero>(0.5*row*col)||nonzero<=0)
		{
			if(nonzero<=0)
			{
				printf("Cannot be less than or equal to Zero!\n");
				flag=1;
			}
			else
			{
				printf("Invalid! More than 50 percent elements are nonzero");
				flag=1;
			}
		}
	}while(flag==1);
	printf("\nEnter the elements of the array:\n");
		for(int i=0;i<nonzero;i++)
		{
			do
			{
				flag=0;
				printf("Enter position:row no. and col no.[Indices start from 0]:\t");
				scanf("%d %d",&trow,&tcol);
				if(trow>=row||tcol>=col)
				{
					flag=1;
					printf("Invalid Position\n");
				}
				if(flag==0)
				{
					if(a[trow][tcol]!=0)
					{
						printf("Position already entered!\n");
						flag=1;
					}
				}
			}while(flag==1);
			do
			{
				flag=0;
				printf("Enter value at the position:\t");
				scanf("%d",&tval);
				if(tval!=0)
				{
					a[trow][tcol]=tval;
				}
				else
				{
					printf("Please enter NonZero Value!\n");
					flag=1;
				}
			}while(flag==1);
		}
}

void createSparse(int a[][MAX],sparse s[],int row,int col)
{
	int i,j,k=0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(a[i][j]!=0)
			{
				k++;
				s[k].row=i;
				s[k].col=j;
				s[k].val=a[i][j];
			}
		}
	}
	s[0].row=row;
	s[0].col=col;
	s[0].val=k;
}

void display(sparse s[])
{
	printf("Row\tCol\tValue\n");
		for(int i=0;i<=s[0].val;i++)
		{
			printf("%d\t%d\t%d\n",s[i].row,s[i].col,s[i].val);
		}
}

void displayMatrix(int a[][MAX],int row,int col)
{
	for(int i=0;i<row;i++)
	{
		printf("|\t");
		for(int j=0;j<col;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("|\n");
	}
}

void add(sparse s1[],sparse s2[],sparse add[])
{
	int i=1;
	int j=1;
	int k=0;
	while(i<=s1[0].val&&j<=s2[0].val)
	{
		if(s1[i].row==s2[j].row)
		{
			if(s1[i].col==s2[j].col)
			{
				k++;
				add[k].val=s1[i].val+s2[j].val;
				add[k].row=s1[i].row;
				add[k].col=s1[i].col;
				i++;
				j++;

			}
			else if(s1[i].col<s2[j].col)
			{
				k++;
				add[k].val=s1[i].val;
				add[k].row=s1[i].row;
				add[k].col=s1[i].col;
				i++;

			}
			else if(s1[i].col>s2[j].col)
			{
				k++;
				add[k].val=s2[j].val;
				add[k].row=s2[j].row;
				add[k].col=s2[j].col;
				j++;

			}
		}
		else if(s1[i].row<s2[j].row)
		{
			k++;
			add[k].val=s1[i].val;
			add[k].row=s1[i].row;
			add[k].col=s1[i].col;
			i++;

		}
		else if(s1[i].row>s2[j].row)
		{
			k++;
			add[k].val=s2[j].val;
			add[k].row=s2[j].row;
			add[k].col=s2[j].col;
			j++;
		}
	}
	while(j<=s2[0].val)
	{
		k++;
		add[k].val=s2[j].val;
		add[k].row=s2[j].row;
		add[k].col=s2[j].col;
		j++;
	}
	while(i<=s1[0].val)
	{
		k++;
		add[k].val=s1[i].val;
		add[k].row=s1[i].row;
		add[k].col=s1[i].col;
		i++;
	}
	add[0].row=s1[0].row;
	add[0].col=s1[0].col;
	add[0].val=k;
}

void simpleTrans(sparse s[],sparse t[])
{
	int i,j;
	int k=0;
	for(i=0;i<s[0].col;i++)
	{
		for(j=1;j<=s[0].val;j++)
		{
			if(s[j].col==i)
			{
				k++;
				t[k].val=s[j].val;
				t[k].row=s[j].col;
				t[k].col=s[j].row;
			}
		}
	}
	t[0].row=s[0].col;
	t[0].col=s[0].row;
	t[0].val=k;
}

void fastTrans(sparse s[],sparse t[])
{
	int row_terms[MAX]={0};
	int starting_pos[MAX];
	int i,j;
	starting_pos[0]=1;
	for(i=1;i<=s[0].val;i++)
	{
		row_terms[s[i].col]++;
	}
	for(i=1;i<=s[0].col;i++)
	{
		starting_pos[i]=starting_pos[i-1]+row_terms[i-1];
	}
	for(i=1;i<=s[0].val;i++)
	{
		j=starting_pos[s[i].col]++;
		t[j].row=s[i].col;
		t[j].col=s[i].row;
		t[j].val=s[i].val;
	}
	t[0].row=s[0].col;
	t[0].col=s[0].row;
	t[0].val=s[0].val;
}
