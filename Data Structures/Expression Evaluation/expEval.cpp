//============================================================================
// Name        : expEval.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<math.h>
#include "Stack.h"
#include "Stack.cpp"
#define CLRSCR system("cls")
using namespace std;

int menu()
{
	int choice;
	cout<<"\nMENU:\n";
	cout<<"\t1.Infix to Postfix\n\t2.Infix to Prefix\n\t3.Evaluate(Postfix)\n\t4.Evaluate(Prefix)\n\t5.Exit\n";
	cin>>choice;
	return choice;
}

int priority(char x)
{
	int p;
	switch(x)
	{
	case ('-'):
			p=1;
	break;
	case ('+'):
			p=1;
	break;
	case ('*'):
			p=2;
	break;
	case ('/'):
			p=2;
	break;
	case ('^'):
			p=3;
	break;
	default:
			p=0;
	break;
	}
	return p;
}

int associativity(char x)
{
	if(x=='^')
		return 1;
	return 0;
}

void postfix(char t[],char res[])
{
	stack <char> s;
	char x,y;
	int i=0,j=0;

	while(t[i]!='\0')
	{
		x=t[i];
		if(isalpha(x)||isdigit(x))
		{
			res[j]=x;
			j++;
		}
		else if(x=='(')
		{
			s.push(x);
		}
		else if(x==')')
		{
			y=s.pop();
			while(y!='(')
			{
				res[j]=y;
				j++;
				y=s.pop();
			}
		}
		else
		{
			while(priority(s.peep())>=priority(x))
			{
				if(x==s.peep())
				{
					if(associativity(s.peep()))
					{
						break;
					}
					else
					{
						y=s.pop();
						res[j]=y;
						j++;
					}
				}
				else
				{
					y=s.pop();
					res[j]=y;
					j++;
				}
			}
			s.push(x);
		}
		i++;
	}
	while(!(s.isEmpty()))
	{
		y=s.pop();
		res[j]=y;
		j++;
	}
	res[j]='\0';
}

void prefix(char t[],char r[])
{
	stack <char> s;
	char res[50];
	char x,y;
	int i=0,j=0;

	int l=strlen(t);
	for(i=0;i<l;i++)
	{
		r[i]=t[l-i-1];
		if(t[l-i-1]=='(')
			r[i]=')';
		if(t[l-i-1]==')')
			r[i]='(';
	}
	r[i]='\0';
	i=0;
	while(r[i]!='\0')
	{
		x=r[i];
		if(isalpha(x)||isdigit(x))
		{
			res[j]=x;
			j++;
		}
		else if(x=='(')
		{
			s.push(x);
		}
		else if(x==')')
		{
			y=s.pop();
			while(y!='(')
			{
				res[j]=y;
				j++;
				y=s.pop();
			}
		}
		else
		{
			while(priority(s.peep())>=priority(x))
			{
				if(x==s.peep())
				{
					if(associativity(s.peep()))
					{
						y=s.pop();
						res[j]=y;
						j++;
					}
					else
						break;
				}
				else
				{
					y=s.pop();
					res[j]=y;
					j++;
				}
			}
			s.push(x);
		}
		i++;
	}
	while(!(s.isEmpty()))
	{
		y=s.pop();
		res[j]=y;
		j++;
	}
	res[j]='\0';
	l=strlen(res);
	for(i=0;i<l;i++)
	{
		r[i]=res[l-i-1];
	}
	r[i]='\0';
}

void calc(int op1,int op2,char x,int* res)
{
	switch(x)
	{
	case ('+'):
			*res=op1+op2;
	break;
	case ('-'):
			*res=op1-op2;
	break;
	case ('*'):
			*res=op1*op2;
	break;
	case ('/'):
			if(op2!=0)
				*res=op1/op2;
			else
				*res=0;
	break;
	case ('^'):
			*res=pow(op1,op2);
	break;
	}
}

int evaluatePost(char t[])
{
	stack<int> s;
	int res=0,i=0,temp,op1,op2;
	char r[50];
	postfix(t,r);
	char x;
	while(r[i]!='\0')
	{
		x=r[i];
		if(isalpha(x))
		{
			cout<<"Enter value of "<<x<<":\t";
			cin>>temp;
			s.push(temp);
		}
		else if(isdigit(x))
		{
			temp=x-'0';
			s.push(temp);
		}
		else
		{
			op2=s.pop();
			op1=s.pop();
			calc(op1,op2,x,&res);
			s.push(res);
		}
		i++;
	}
	return res;
}

int evaluatePre(char t[])
{
	stack<int> s;
	int res=0,i=0,temp,op1,op2;
	char r[50],rev[50];
	prefix(t,r);
	int l=strlen(r);
	for(i=0;i<l;i++)
	{
		rev[i]=r[l-i-1];
	}
	rev[i]='\0';
	char x;
	i=0;
	while(rev[i]!='\0')
	{
		x=rev[i];
		if(isalpha(x))
		{
			cout<<"Enter value of "<<x<<":\t";
			cin>>temp;
			s.push(temp);
		}
		else if(isdigit(x))
		{
			temp=x-'0';
			s.push(temp);
		}
		else
		{
			op1=s.pop();
			op2=s.pop();
			calc(op1,op2,x,&res);
			s.push(res);
		}
		i++;
	}
	return res;
}

int validate(char exp[])
{
	int countop=0,countcl=0,l=strlen(exp),i,j=0,oprtr=0,oprnd=0;
	char c;
	char temp[50];
	for(i=0;i<l;i++)
	{
		c=exp[i];
		if(c=='(')
			countop++;
		else if(c==')')
			{
				countcl++;
				if(countcl>countop)
					return 0;
			}
		else
		{
			temp[j]=c;
			j++;
			if(isalpha(c)||isdigit(c))
				oprnd++;
			else
				oprtr++;
		}
	}
	temp[j]='\0';
	if(countop!=countcl || oprtr!=(oprnd-1))
		return 0;
	l=strlen(temp);
	for(i=0;i<l;i++)
	{
		c=temp[i];
		if(i%2==0)
			if(!isalpha(c)&&!isdigit(c))
				return 0;
		if(i%2==1)
			if(isalpha(c)||isdigit(c))
				return 0;
	}
	return 1;
}

int main() {
	setvbuf( stdout, NULL, _IONBF, 0 );
	int cont,choice,eval,v;
	char t[50],res[50];
	do
	{
		CLRSCR;
		choice=menu();
		switch(choice)
		{
		case 1:
			cout<<"Infix expression:\t";
			cin>>t;
			v=validate(t);
			if(v==1)
			{
				postfix(t,res);
				cout<<"Postfix expression:\t"<<res<<"\n";
			}
			else
				cout<<"Invalid expression\n";
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 2:
			cout<<"Infix expression:\t";
			cin>>t;
			v=validate(t);
			if(v==1)
			{
				prefix(t,res);
				cout<<"Prefix Expression:\t"<<res<<"\n";
			}
			else
				cout<<"Invalid expression\n";
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 3:
			cout<<"Infix expression:\t";
			cin>>t;
			v=validate(t);
			if(v==1)
			{
				eval=evaluatePost(t);
				cout<<"Answer is:\t"<<eval;
			}
			else
				cout<<"Invalid expression\n";
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 4:
			cout<<"Infix expression:\t";
			cin>>t;
			v=validate(t);
			if(v==1)
			{
				eval=evaluatePre(t);
				cout<<"Answer is:\t"<<eval;
			}
			else
				cout<<"Invalid expression\n";
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 5:
			cont=0;
			break;
		default:
			cout<<"\nInvalid Input\n";
			cont=1;
			break;
		}
	}while(cont==1);
	return 0;
}
