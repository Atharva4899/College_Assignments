//============================================================================
// Name        : linkedADT.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "SllADT.h"
using namespace std;

int menu()
{
	int choice;
	cout<<"\n\nMENU\n\t1.Insert Node\n\t2.Delete Node\n\t3.Reverse List\n\t4.Display List\n\t5.Exit\n";
	cin>>choice;
	return choice;
}
int main() {
	SllADT l;
	int cont,choice;
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			l.insertnode();
			cout<<"List:\n";
			l.display();
			cout<<"Press 1 for menu else any other key to exit:\t";
			cin>>cont;
			break;
		case 2:
			l.deletenode();
			cout<<"List:\n";
			l.display();
			cout<<"Press 1 for menu else any other key to exit:\t";
			cin>>cont;
			break;
		case 3:
			l.reverselist();
			cout<<"List:\n";
			l.display();
			cout<<"Press 1 for menu else any other key to exit:\t";
			cin>>cont;
			break;
		case 4:
			l.display();
			cout<<"Press 1 for menu else any other key to exit:\t";
			cin>>cont;
			break;
		case 5:
			cont=0;
			break;
		default:
			cout<<"Invalid Choice:\n";
			cont=1;
			break;
		}
	}while(cont==1);
	return 0;
}
