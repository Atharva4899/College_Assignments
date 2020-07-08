//============================================================================
// Name        : classTemp.cpp
// Author      : Atharva Kulkarni,F11,23329
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

template<typename T>
class Matrix
{
	T m[10][10];
	int r,c;
	public:
		Matrix()
		{
			//m={0};
			r=c=0;
		}
		void getMat()
		{
			cout<<"Enter Total rows and columns:\t";
			cin>>r>>c;
			cout<<"Enter Matrix:\n";
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					cin>>m[i][j];
				}
			}
		}
		int getRow()
		{
			return r;
		}
		int getCol()
		{
			return c;
		}
		void disMat()
		{
			for(int i=0;i<r;i++)
			{
				cout<<"|\t";
				for(int j=0;j<c;j++)
				{
					cout<<m[i][j]<<"\t";
				}
				cout<<"|\n";
			}
		}

		void add(Matrix m1,Matrix m2)
		{
			//Matrix res;
			if(m1.r==m2.r&&m1.c==m2.c)
			{
				int r1=m1.r;
				int c1=m1.c;
				for(int i=0;i<r1;i++)
				{
					for(int j=0;j<c1;j++)
					{
						m[i][j]=m1.m[i][j]+m2.m[i][j];
					}
				}
				r=r1;
				c=c1;
			}
			else
				cout<<"Addition not possible\n\n";
			//return res;
		}

		void trans(Matrix m1)
		{
			//Matrix res;
			int r1=m1.getRow();
			int c1=m1.getCol();
			r=c1;
			c=r1;
			for(int i=0;i<r;i++)
			{
				for(int j=0;j<c;j++)
				{
					m[i][j]=m1.m[j][i];
				}
			}
			//return res;
		}
};
int main()
{
	setvbuf( stdout, NULL, _IONBF, 0 );
	Matrix <double> m1,m2,addn,transp;
	m1.getMat();
	m2.getMat();
	cout<<"\nMatrix 1:\n";
	m1.disMat();
	cout<<"\nMatrix 2:\n";
	m2.disMat();
	cout<<"\nAddition:\n";
	addn.add(m1,m2);
	addn.disMat();
	cout<<"\nTranspose of Matrix 1:\n";
	transp.trans(m1);
	transp.disMat();
	cout<<"\nTranspose of Matrix 2:\n";
	transp.trans(m2);
	transp.disMat();
	return 0;
}
