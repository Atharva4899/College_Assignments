//============================================================================
// Name        : prqueue.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include "queue.h"
#include "queue.cpp"
using namespace std;

typedef struct data
{
	int id;
	int prior;
	char name[30];
	char disease[30];
	char bg[5];
}data;

void disonerec(data def)
{
	cout<<"\nNext Patient:\n\n";
	cout<<"ID:\t"<<def.id<<"\n";
	cout<<"Name:\t"<<def.name<<"\n";
	cout<<"Disease:\t"<<def.disease<<"\n";
	cout<<"Blood Group:\t"<<def.bg<<"\n";
	cout<<"Priority:\t"<<def.prior<<"\n";
}

int menu()
{
	int choice;
	cout<<"\nMenu:";
	cout<<"\n\t1.Add patient details\n\t2.Display all records\n\t3.Call next patient\n\t4.Exit\n";
	cin>>choice;
	return choice;
}

int priority(char dis[])
{
	int p;
	if(strcmp(dis,"Heart Attack")==0||strcmp(dis,"Accident")==0)
		p=1;
	else if(strcmp(dis,"TB")==0||strcmp(dis,"Malaria")==0)
		p=2;
	else
		p=3;
	return p;
}

data getData(int id)
{
	data d;
	int flag;
	cout<<"\nEnter patient details:\n";
	cin.ignore();
	do
	{
		cout<<"Enter name:\t";
		cin.getline(d.name,30);
		for(int i=0;d.name[i]!='\0';i++)
		{
			flag=0;
			if(!isalpha(d.name[i])&& d.name[i]!=' ')
			{
				flag=1;
				cout<<"Invalid name!\n";
				break;
			}
		}
	}while(flag==1);
	cout<<"Enter disease:\t";
	cin.getline(d.disease,30);
	cout<<"Enter blood group:\t";
	cin.getline(d.bg,5);
	d.prior=priority(d.disease);
	d.id=id;
	return d;
}

void tabletail()
{
	for(int i=0;i<70;i++)
		cout<<"-";
	cout<<"\n";
}

int main()
{
	setvbuf( stdout, NULL, _IONBF, 0 );
	static int id=100;
	Queue<data> q;
	data def[30];
	int cont,choice,size;
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			q.enqueue(getData(id++));
			cout<<"\nPress 1 for Menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 2:
			size=q.displayRec(def);
			if(size!=0)
			{
				cout<<"\n\tDetails of patients are as follows:\n\n";
				tabletail();
				cout<<std::left<<"|"<<setw(5)<<" ID "<<"|"<<setw(25)<<" Name "<<"|"<<setw(25)<<" Disease "<<"|"<<setw(5)<<" BG "<<"|"<<setw(5)<<"Prior"<<"|\n";
				tabletail();
				for(int i=0;i<size;i++)
				{
					cout<<std::left<<"|"<<setw(5)<<def[i].id<<"|"<<setw(25)<<def[i].name<<"|"<<setw(25)<<def[i].disease<<"|"<<setw(5)<<def[i].bg<<"|"<<setw(5)<<def[i].prior<<"|\n";
					tabletail();
				}

			}
			cout<<"\nPress 1 for Menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 3:
			if(!q.isEmpty())
			{
				disonerec(q.dequeue());
			}
			else
				cout<<"\nNo patients remaining!\n";
			cout<<"\nPress 1 for Menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 4:
			cont=0;
			break;
		default:
			cout<<"\nInvalid Input!\n";
			cont=1;
			break;
		}
	}while(cont==1);
	return 0;
}
