//============================================================================
// Name        : Assg3.cpp
// Author      : Atharva Kulkarni,23329,F11
// Version     : 
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

class complex
{
	float real,imag;
	public:
	complex()
	{
		real=0.0;
		imag=0.0;
	}
	complex(float a,float b)
	{
		real=a;
		imag=b;
	}
	friend complex operator + (complex,complex);
	friend complex operator - (complex,complex);
	complex operator * (complex c)
	{
		complex temp;
		temp.real=real*c.real;
		temp.imag=imag*c.imag;
		if(temp.real==-0)
			temp.real=0;
		if(temp.imag==-0)
			temp.imag=0;
		return temp;
	}
	complex operator / (complex c)
	{
		complex temp;
		temp.real=real/c.real;
		temp.imag=imag/c.imag;
		if(temp.real==-0)
			temp.real=0;
		if(temp.imag==-0)
			temp.imag=0;
		return temp;
	}
	void display();
	int val();
};

complex operator + (complex c1,complex c2)
{
	complex temp;
	temp.real=c1.real+c2.real;
	temp.imag=c1.imag+c2.imag;
	return temp;
}
complex operator - (complex c1,complex c2)
{
	complex temp;
	temp.real=c1.real-c2.real;
	temp.imag=c1.imag-c2.imag;
	return temp;
}
void complex::display()
{
	cout<<"("<<real<<") + ("<<imag<<")i\n";
}
int complex::val()
{
	if(real==0.0||imag==0.0)
		return 1;
	else
		return 0;
}
complex getdata()
{
	float real,imag;
	cout<<"\tEnter real part of complex number:\t";
	cin>>real;
	cout<<"\tEnter imaginary part of complex number:\t";
	cin>>imag;
	complex temp(real,imag);
	return temp;
}
void dis(complex c1,complex c2)
{
	cout<<"Complex No 1:\t";
	c1.display();
	cout<<"Complex No 2:\t";
	c2.display();
}
int main()
{
	int cont,choice,val;
	complex c1,c2,res;
	cout<<"Complex Number 1:\n";
	c1=getdata();
	cout<<"Complex Number 2:\n";
	c2=getdata();
	do
	{
		cout<<"------MENU------	\n";
		cout<<"\t1.Add\n\t2.Subtract\n\t3.Multiply\n\t4.Divide\n\t5.Change Values\n\t6.Exit\n";
		cout<<"Enter your choice:\t";
		cin>>choice;
		switch(choice)
		{
		case 1:
			res=c1+c2;
			dis(c1,c2);
			cout<<"The Result of Addition is:\t";
			res.display();
			cout<<"\tPress 1 to continue,else press 0:\t";
			cin>>cont;
			break;
		case 2:
			res=c1-c2;
			dis(c1,c2);
			cout<<"The Result of Subtraction c1-c2 is:\t";
			res.display();
			res=c2-c1;
			cout<<"The Result of Subtraction c2-c1 is:\t";
			res.display();
			cout<<"\tPress 1 to continue,else press 0:\t";
			cin>>cont;
			break;
		case 3:
			res=c1*c2;
			dis(c1,c2);
			cout<<"The Result of Multiplication is:\t";
			res.display();
			cout<<"\tPress 1 to continue,else press 0:\t";
			cin>>cont;
			break;
		case 4:
			dis(c1,c2);
			val=c2.val();
			if(val==0)
			{
				res=c1/c2;				
				cout<<"The Result of Division c1/c2 is:\t";
				res.display();
			}
			else
				cout<<"\tDivision c1/c2 not possible!\n";
			val=c1.val();
			if(val==0)
			{
				res=c2/c1;
				cout<<"The Result of Division c2/c1 is:\t";
				res.display();
			}
			else
				cout<<"\tDivision c2/c1 not possible!\n";
			cout<<"\tPress 1 to continue,else press 0:\t";
			cin>>cont;
			break;
		case 5:
			cout<<"Enter new values:\n";
			cout<<"Complex Number 1:\n";
			c1=getdata();
			cout<<"Complex Number 2:\n";
			c2=getdata();
			cont==1;
			break;
		case 6:
			cont=0;
			break;
		default:
			cout<<"\tInvalid Input!!!";
			cout<<"\tPress 1 to continue,else press 0:\t";
			cin>>cont;
			break;
		}
	}while(cont==1);
	return 0;
}
			
		

