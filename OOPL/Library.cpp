//============================================================================
// Name        : assg2.cpp
// Author      : Atharva Kulkarni,23329,F11
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#define max 50
using namespace std;

int i,j,k,flag,temp;
class book
{
	char title[15],author[15],publisher[15];
	int price,stock,ISBN,no;
public:
	static int stran,unstran;
	void add(int &);
	void display();
	void update();
	int search(book*[],int);
	void transac();
	int purchase(book*);
	int validate(int,book*[]);
};
int book::stran;
int book::unstran;

int main()
{
	book* b[max];
	book dummy;
	int pos,cont,choice,tran,val;
	static int bookno;
	do
	{
		cout<<"------MENU------\n";
		cout<<"\n   1.Add record\n   2.Display records\n   3.Search a book\n   4.Update details";
		cout<<"\n   5.Purchase book\n   6.Transaction history\n   7.Exit\n";
		cout<<"Enter your choice:\t";
		cin>>choice;
		switch(choice)
		{
		case 1:
			if(bookno<max)
			{
				b[bookno]=new book;
				b[bookno]->add(bookno);
				val=dummy.validate(bookno,b);
				if(val==1)
				{
					delete(b[(bookno-1)]);
					bookno--;
				}
			}
			else
				cout<<"\tCapacity is full,cannot add more records!";
		cout<<"\nPress 1 to continue else press 0:\t";
		cin>>cont;
		break;
		case 2:
			if(bookno==0)
				cout<<"\tNo Records Found!!!";
			else
				{
					for(i=0;i<bookno;i++)
						b[i]->display();
				}
			cout<<"\nPress 1 to continue else press 0:\t";
				cin>>cont;
		break;
		case 3:
			if(bookno==0)
				cout<<"\tNo Records Found!!!";
			else
			{
				pos=dummy.search(b,bookno);
				if(pos!=-1)
				{
					cout<<"Details of the searched book are:\n";
					b[pos]->display();
				}
				else
					cout<<"\tBook not found!";
			}
			cout<<"\nPress 1 to continue else press 0:\t";
			cin>>cont;
		break;
		case 4:
			if(bookno==0)
				cout<<"\tNo Records Found!!!";
			else 
			{
				pos=dummy.search(b,bookno);
				b[pos]->update();
			}
			cout<<"\nPress 1 to continue else press 0:\t";
			cin>>cont;
		break;
		case 5:
			if(bookno==0)
				cout<<"\tNo Records Found!!!";
			else
			{
				cout<<"Find book to be purchased:\n";
				pos=dummy.search(b,bookno);
				tran=dummy.purchase(b[pos]);
				if(tran==1)
				{
					cout<<"\nTransaction successful,updated stock is:\n";
					b[pos]->display();
				}
				else
					cout<<"\nTransaction Unsuccessful!";
			}
			cout<<"\nPress 1 to continue else press 0:\t";
			cin>>cont;
		break;
		case 6:
			dummy.transac();
			cout<<"\nPress 1 to continue else press 0:\t";
			cin>>cont;
		break;
		case 7:
			cont=0;
		break;
	}
	}while(cont==1);
	return 0;
}

void book::add(int &bookno)
{
	cout<<"Enter Title:\t";
	cin.ignore();
	cin.getline(title,15);
	cout<<"Enter ISBN no.:\t";
	cin>>ISBN;
	cout<<"Enter Author:\t";
	cin.ignore();
	cin.getline(author,15);
	cout<<"Enter the Publisher:\t";
	cin.ignore();
	cin.getline(publisher,15);
	do
	{
		cout<<"Enter Price:\t";
		cin>>temp;
		if(temp<0)
			cout<<"\tInvalid price!\n";
	}while(temp<0);
	price=temp;
	do
	{
		cout<<"Enter available stock:\t";
		cin>>temp;
		if(temp<0)
			cout<<"\tEnter valid stock!\n";
	}while(temp<0);
	stock=temp;
	bookno++;
	if(bookno==max)
		cout<<"\n\tWarning!This record will be the last as capacity is now full!";
	no=bookno;
}
void book::display()
{
	cout<<no<<".Title: "<<title<<"\tAuthor: "<<author<<"\tPublisher: "<<publisher;
	cout<<"\nPrice: "<<price<<"\tISBN: "<<ISBN<<"\tAvailable Stock: "<<stock<<"\n";
}
void book::update()
{
	int choice,cont;
	do
	{
		cout<<"What do you want to update?\n\t1.Price\n\t2.Available Stock\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			cout<<"Enter new price:\t";
			cin>>price;
			cout<<"Press 1 if you want to go back to Update Menu,else press 0:\t";
			cin>>cont;
		break;
		case 2:
			cout<<"Enter updated stock:\t";
			cin>>stock;
			cout<<"Press 1 if you want to go back to Update Menu,else press 0:\t";
			cin>>cont;
		}
	}while(cont==1);
}
int book::search(book* b[],int bookno)

{
	int choice,iquery,flag=0;
	char tquery[15];
	cout<<"Search with:\n\t1.Title\n\t2.ISBN\n";
	cin>>choice;
	switch(choice)
	{
	case 1:
		cout<<"Enter title:\t";
		cin.ignore();
		cin.getline(tquery,15);
		for(i=0;i<bookno;i++)
			if(strcmp(b[i]->title,tquery)==0)
			{
				flag=1;
				break;
			}
	break;
	case 2:
		cout<<"Enter ISBN:\t";
		cin>>iquery;
		for(i=0;i<bookno;i++)
			if(b[i]->ISBN==iquery)
			{
				flag=1;
				break;
			}
	break;
	default:
		cout<<"\tInvalid input!";
	break;
	}
	if(flag==1)
		return i;
	else
		return -1;
}
int book::purchase(book* b)

{
	int nob,flag;
	cout<<"Enter number of copies to buy:\t";
	cin>>nob;
	if(b->stock>nob)
	{
		b->stock-=nob;
		flag=1;
		stran++;
	}
	else
	{
		cout<<"\tInsufficient stock!!!";
		flag=0;
		unstran++;
	}
	return flag;
}
void book::transac()
{
	cout<<"Total Successful Transactions are:\t"<<stran<<"\n";
	cout<<"Total Unsuccessful Transactions are:\t"<<unstran<<"\n";
}
int book::validate(int bookno,book* b[])
{
	for(i=0;i<(bookno-1);i++)
	{
		flag=0;
		if(strcmp(b[i]->title,b[(bookno-1)]->title)==0||b[i]->ISBN==b[(bookno-1)]->ISBN)
		{
			cout<<"\n\tThis book already exists in the records!";
			cout<<"\n\tRecord creation failed!!";
			flag=1;
			break;
		}
	}
	return flag;
}
