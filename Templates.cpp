#include<iostream>
using namespace std;

template<typename T>
void add(T a[10][10],T b[10][10],T res[10][10],int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			res[i][j]=a[i][j]+b[i][j];
		}
	}
}

template<typename T>
void subtract(T a[10][10],T b[10][10],T res[10][10],int r,int c)
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			res[i][j]=a[i][j]-b[i][j];
		}
	}
}

template<typename T>
void input(T a[10][10],int r,int c)
{
	cout<<"Enter the Matrix:\n";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
}

template<typename T>
void display(T a[10][10],int r,int c)
{
	for(int i=0;i<r;i++)
	{
		cout<<"|\t";
		for(int j=0;j<c;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"|\n";
	}
}

int main()
{
	int row,col,type,choice,cont1,cont2,flag;
	do
	{
		cout<<"---MAIN MENU---\n\t1.Integer Matrix\n\t2.Floating Matrix\n\t3.Exit\n";
		cin>>type;
		switch(type)
		{

			case 1:
			{
				int m1[10][10],m2[10][10],res[10][10];
				int ip=0;
				do
				{
				cout<<"\n\t---MENU---\n\t1.Input Matrices\n\t2.Add Matrices\n\t3.Subtract Matrices\n\t4.Main Menu\n";
				cin>>choice;
					switch(choice)
					{
					case 1:
						do
						{
							flag=0;
							cout<<"Enter rows and columns for matrices:\t";
							cin>>row>>col;
							if(row<=0||col<=0)
							{
								cout<<"Invalid Dimensions!\n";
								flag=1;
							}
						}while(flag==1);
						input<int>(m1,row,col);
						input<int>(m2,row,col);
						cout<<"\nMatrix 1:\n";
						display<int>(m1,row,col);
						cout<<"\nMatrix 2:\n";
						display<int>(m2,row,col);
						cont2=1;
						ip=1;
						break;
					case 2:
						if(ip==1)
						{
							add<int>(m1,m2,res,row,col);
							cout<<"Resultant Matrix:\n";
							display<int>(res,row,col);
						}
						else
						{
							cout<<"No Data Entered!\n";
						}
						cout<<"Press 1 for previous Menu, 0 for Main Menu:\t";
						cin>>cont2;
						break;
					case 3:
						if(ip==1)
						{
							subtract<int>(m1,m2,res,row,col);
							cout<<"Resultant Matrix:\n";
							display<int>(res,row,col);
						}
						else
						{
							cout<<"No Data Entered!\n";
						}
						cout<<"Press 1 for previous Menu, 0 for Main Menu:\t";
						cin>>cont2;
						break;
					case 4:
						cont2=0;
						cont1=1;
						break;
					default:
						cout<<"Invalid Input!\n";
						cont2=1;
						break;
					}
				}while(cont2==1);
				break;
			}
			case 2:
			{
				float m1[10][10],m2[10][10],res[10][10];
				int ip=0;
				do
				{
				cout<<"\n\t---MENU---\n\t1.Input Matrices\n\t2.Add Matrices\n\t3.Subtract Matrices\n\t4.Main Menu\n";
				cin>>choice;
					switch(choice)
					{
					case 1:
						do
						{
							flag=0;
							cout<<"Enter rows and columns for matrices:\t";
							cin>>row>>col;
							if(row<=0||col<=0)
							{
								cout<<"Invalid Dimensions!\n";
								flag=1;
							}
						}while(flag==1);
						input<float>(m1,row,col);
						input<float>(m2,row,col);
						cout<<"\nMatrix 1:\n";
						display<float>(m1,row,col);
						cout<<"\nMatrix 2:\n";
						display<float>(m2,row,col);
						cont2=1;
						ip=1;
						break;
					case 2:
						if(ip==1)
						{
							add<float>(m1,m2,res,row,col);
							cout<<"Resultant Matrix:\n";
							display<float>(res,row,col);
						}
						else
						{
							cout<<"No Data Entered!\n";
						}
						cout<<"Press 1 for previous Menu, 0 for Main Menu:\t";
						cin>>cont2;
						break;
					case 3:
						if(ip==1)
						{
							subtract<float>(m1,m2,res,row,col);
							cout<<"Resultant Matrix:\n";
							display<float>(res,row,col);
						}
						else
						{
							cout<<"No Data Entered!\n";
						}
						cout<<"Press 1 for previous Menu, 0 for Main Menu:\t";
						cin>>cont2;
						break;
					case 4:
						cont2=0;
						cont1=1;
						break;
					default:
						cout<<"Invalid Input!\n";
						cont2=1;
						break;
					}
				}while(cont2==1);
				break;
			}
			case 3:
				cont1=0;
				break;
			default:
				cout<<"Invalid Input!\n";
				cont1=1;
				break;
		}
	}while(cont1==1);
}
