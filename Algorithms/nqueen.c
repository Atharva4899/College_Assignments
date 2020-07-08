#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int x[8]={0};						//initial board

void print(int b_size)					//print chessboard
{
	int i,j;
	
	for(i=0;i<b_size;i++)				//for ith queen
	{
		for(j=0;j<b_size;j++)			//print ith row
		{
			if(x[i]==j)			//if ith queen placed in column j, print 'Q' else '-'
				printf(" Q ");
			else
				printf(" - ");
		}
		
		printf("\n");
	}
	
	printf("\n\n");
}

int place(int qno,int colno)				//check if queen can be placed at row qno and column colno
{
	int j;

	for(j=0;j<qno;j++)
	{
		if(x[j]==colno || abs(x[j]-colno)==abs(j-qno))
			return 0;
	}
	
	return 1;
}

int NQueens(int qno,int b_size)
{
	int i;
	for(i=0;i<b_size;i++)				//one queen in each row
	{
		if(place(qno,i))			//if queen can be placed
		{
			x[qno]=i;			//store colno of this queen

			if(qno==b_size-1)		//if all queens placed, print solution
				print(b_size);
			else
				NQueens(qno+1,b_size);	//try next queen
		}
	}
	return 0;
}

int main()
{
	int bsize;
	printf("Enter dimension of chess-board:  ");
	scanf("%d",&bsize);
	
	NQueens(0,bsize);
	
	return 0;
}
