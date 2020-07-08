/*
 ============================================================================
 Name        : Assgn2.c
 Author      : Atharva Kulkarni,23329,F11
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define msize 10
int i,j,k;

void validinfo(int*,int*);
int** memacc(int,int);
void getmat(int**,int,int);
void display(int**,int,int);
void addmat(int**,int**,int**,int,int);
void mulmat(int**,int**,int**,int,int,int,int);
void transpose(int**,int**,int,int);
void saddlept(int**,int,int);

int main(void)
{
	int row1,col1,row2,col2,choice,cont;
	int **m1=NULL,**m2=NULL,**ad=NULL,**ml=NULL,**t1=NULL,**t2=NULL;
	printf("Enter number of rows and columns in Matrix1:\n");
	validinfo(&row1,&col1);
	printf("Enter number of rows and columns in Matrix2:\n");
	validinfo(&row2,&col2);
	m1=memacc(row1,col1);
	m2=memacc(row2,col2);
	do{
		printf("Enter your choice:\n");
			printf("1.Input Matrix\n2.Display Matrix\n3.Addition\n4.Multiplication\n5.Transpose\n6.Saddle Point\n7.Exit");
			scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter Matrix 1:\n");
				getmat(m1,row1,col1);
				printf("\nEnter Matrix 2:\n");
				getmat(m2,row2,col2);
				printf("Press 1 to continue,0 to exit\n");
				scanf("%d",&cont);
			break;
			case 2:
				printf("\nMatrix 1 is:\n");
				display(m1,row1,col1);
				printf("\nMatrix 2 is:\n");
				display(m2,row2,col2);
				printf("Press 1 to continue,0 to exit\n");
				scanf("%d",&cont);
			break;
			case 3:
				if(row1==row2&&col1==col2)
				{
					ad=memacc(row1,col1);
					addmat(m1,m2,ad,row1,col1);
					printf("Addition of the two matrices is:\n");
					display(ad,row1,col1);
				}
				else
					printf("Addition not Possible");
				printf("Press 1 to continue,0 to exit\n");
				scanf("%d",&cont);
			break;
			case 4:
				if(col1==row2)
				{
					ml=memacc(row1,col2);
					mulmat(m1,m2,ml,row1,col1,row2,col2);
					printf("Multiplication of the two matrices is:\n");
					display(ml,row1,col2);
				}
				else
					printf("Multiplication not possible");
				printf("Press 1 to continue,0 to exit\n");
				scanf("%d",&cont);
			break;
			case 5:
				t1=memacc(row1,col1);
				printf("\nTranspose of Matrix1 is:\n");
				transpose(m1,t1,row1,col1);
				display(t1,col1,row1);
				t2=memacc(row2,col2);
				printf("\nTranspose of Matrix 2 is:\n");
				transpose(m2,t2,row2,col2);
				display(t2,col2,row2);
				printf("Press 1 to continue,0 to exit\n");
				scanf("%d",&cont);
			break;
			case 6:
				printf("Saddle Point of Matrix 1:\n");
				saddlept(m1,row1,col1);
				printf("\nSaddle Point of Matrix 2:\n");
				saddlept(m2,row2,col2);
				printf("Press 1 to continue,0 to exit\n");
				scanf("%d",&cont);
			break;
			case 7:
				cont=0;
			break;
		}
	}while(cont==1);
	return EXIT_SUCCESS;
}
void validinfo(int* row,int* col)
{
	int temp1,temp2,flag=0;
	do
	{
		flag=0;
		scanf("%d%d",&temp1,&temp2);
		if(temp1>msize||temp2>msize)
		{
			printf("Size exceeds max size,enter another value:");
			flag=1;
		}
		else
		{
			*row=temp1;
			*col=temp2;
		}
	}while(flag==1);
}
int** memacc(int r,int c)
{
	int** p=(int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		p[i]=(int*)malloc(c*sizeof(int));
	return p;
}
void getmat(int** m,int row,int col)
{
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			scanf("%d",(*(m+i)+j));
}
void display(int** m,int row,int col)
{
	for(i=0;i<row;i++)
	{
		printf("|\t");
		for(j=0;j<col;j++)
			printf("%d\t",m[i][j]);
		printf("|\n");
	}
}
void addmat(int** m1,int** m2,int** ad,int row,int col)
{
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			ad[i][j]=m1[i][j]+m2[i][j];
}
void mulmat(int** m1,int** m2,int** ml,int row1,int col1,int row2,int col2)
{
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col2;j++)
		{
			ml[i][j]=0;
			for(k=0;k<col1;k++)
				ml[i][j]+=m1[i][k]*m2[k][j];
		}
	}
}
void transpose(int** m,int** t,int row,int col)
{
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			t[i][j]=m[j][i];
}
void saddlept(int** m,int row,int col)
{
	int min,max,pos[2][2],t1,t2;
	for(i=0;i<row;i++)
	{
		min=m[i][0];
		for(j=0;j<col;j++)
		{
			if(min>=m[i][j])
			{
				min=m[i][j];
				pos[0][0]=i;
				pos[0][1]=j;
			}
		}
			j=pos[0][1];
			max=m[0][j];
			for(k=0;k<row;k++)
			{
				if(max<=m[k][j])
				{
					max=m[k][j];
					pos[1][0]=k;
					pos[1][1]=j;
				}
			}
			if(min==max)
			{
				if(pos[0][0]==pos[1][0]&&pos[0][1]==pos[1][1])
				{
					t1=pos[0][0];
					t2=pos[0][1];
					printf("Saddle Point is at:%d,%d\n",(t1+1),(t2+1));
					printf("The element is %d\n",m[t1][t2]);
				}
			}
		}
	}

