/*============================================================================
                              HASHING
Assignment no. : 9
Roll no.       : 23333
Batch          : F11
============================================================================*/

#include <iostream>
using namespace std;
typedef struct hash
{
	int id;
	char name[20];
	long long int phn;
	int chain;
}hasht;

int hash_function(long ph)
{
	int a=ph%10;
	return a;
}

int menu()
{
	int ch;
	cout<<"\n\nMENU :\n1.Create hash table\n2.Insert\n3.Search\n4.Display table\n5.Exit\nEnter your choice : ";
	cin>>ch;
	return ch;
}

hasht input()
{
	hasht temp;
	cout<<"\n\nEnter id : "; cin>>temp.id;
	cout<<"Enter name : "; cin>>temp.name;
	cout<<"Enter phone number : "; cin>>temp.phn;
	temp.chain=-1;
	return temp;
}

class without_replacement
{
	hasht h[10];
public:
	without_replacement()
{
		for(int i=0; i<10; i++)
		{
			h[i].id=0;
			h[i].phn=0;
			h[i].chain=-1;
		}
}

	void display()
	{
		cout<<"Index\tID\tName\t\tPhone No.\tChain\n";
		for(int i=0 ; i<10; i++)
		{
			if(h[i].phn!=0)
				cout<<i<<"\t"<<h[i].id<<"\t"<<h[i].name<<"\t\t"<<h[i].phn<<"\t\t"<<h[i].chain<<"\n";
			else
				cout<<i<<"\t--\t--\t\t--\t\t--\t\n";
		}
	}

	void search()
	{
		long ph1;
		int c=0;
		cout<<"\nEnter the phone number to be searched : ";
		cin>>ph1;
		int a=hash_function(ph1);
		while(1)
		{
			if(h[a].phn==ph1)
			{
				cout<<"\n\nRecord found";
				cout<<"\t"<<h[a].id<<"\t"<<h[a].name<<"\t"<<h[a].phn<<"\n";
				c++;
				break;
			}
			else if(h[a].chain!=-1)
			{
				a=h[a].chain;
			}
			else
				break;

		}
		if(c==0)
			cout<<"\nRecord not found!!";
	}

	void insert()
	{
		hasht temp=input();
		add(temp);
		cout<<"\nInserted Successfully!!";
	}

	void create()
	{
		int n;
		cout<<"How many records do you want to add : "; cin>>n;
		for(int i=1; i<=n; i++)
		{
			hasht temp=input();
			add(temp);
		}
	}

	void add(hasht temp)
	{
		int index=hash_function(temp.phn);
		if(h[index].phn==0)
			h[index]=temp;
		else
		{
			int i=index;
			while(h[i].phn!=0)
			{
				i++;
				if(i>9)
					i=0;
			}
			h[i]=temp;
			if(hash_function(h[index].phn)==index)
			{
				while(h[index].chain!=-1)
					index=h[index].chain;
				h[index].chain=i;
			}
			else
			{
				int j=index+1;
				while(h[j].chain!=-1)
					j=h[j].chain;
				if(h[j].phn!=temp.phn)
					h[j].chain=i;
			}
		}
	}
};


class with_replacement
{
	hasht h[10];
public:
	with_replacement()
{
		for(int i=0; i<10; i++)
		{
			h[i].id=0;
			h[i].phn=0;
			h[i].chain=-1;
		}
}

	void display()
	{
		cout<<"Index\tID\tName\t\tPhone No.\tChain\n";
		for(int i=0 ; i<10; i++)
		{
			if(h[i].phn!=0)
				cout<<i<<"\t"<<h[i].id<<"\t"<<h[i].name<<"\t\t"<<h[i].phn<<"\t\t"<<h[i].chain<<"\n";
			else
				cout<<i<<"\t--\t--\t\t--\t\t--\t\n";
		}
	}

	void search()
	{
		long ph1;
		int c=0;
		cout<<"\nEnter the phone number to be searched : ";
		cin>>ph1;
		int a=hash_function(ph1);
		while(1)
		{
			if(h[a].phn==ph1)
			{
				cout<<"\n\nRecord found";
				cout<<"\t"<<h[a].id<<"\t"<<h[a].name<<"\t"<<h[a].phn<<"\n";
				c++;
				break;
			}
			else if(h[a].chain!=-1)
			{
				a=h[a].chain;
			}
			else
				break;

		}
		if(c==0)
			cout<<"\nRecord not found!!";
	}

	void create()
	{
		int n;
		cout<<"How many records do you want to add : "; cin>>n;
		for(int i=1; i<=n; i++)
		{
			hasht temp=input();
			add(temp);
		}
	}

	void add(hasht temp)
	{
		int index=hash_function(temp.phn),j;
		if(h[index].phn==0)
			h[index]=temp;
		else
		{
			hasht new1;
			new1=h[index];
			if(hash_function(new1.phn)!=index)
			{
				h[index]=temp;
				int i=index;
				while(h[i].phn!=0)
				{
					i++;
					if(i>9)
						i=0;
				}
				h[i]=new1;
				int j=hash_function(new1.phn);
				while(h[j].chain!=index)
				{
					j=h[j].chain;
				}
				h[j].chain=i;
			}
			else if(hash_function(new1.phn)==index)
			{
				int i=index;
				while(h[i].chain!=-1)
					i=h[i].chain;
				j=i;
				while(h[i].phn!=0)
				{
					i++;
					if(i>9)
						i=0;
				}
				h[i]=temp;
				h[j].chain=i;
			}
		}
	}

	void insert()
	{
		hasht temp=input();
		add(temp);
		cout<<"\nInserted Successfully!!";
	}

};

int main()
{
	int choice;
	do
	{
		cout<<"\n\nMENU:\n1.Without replacement\n2.With replacement\n3.Exit\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
		case 1:
		{
			without_replacement w;
			do
			{
				choice=menu();
				switch(choice)
				{
				case 1:
					w.create();
					break;
				case 2:
					w.insert();
					break;
				case 3:
					w.search();
					break;
				case 4:
					w.display();
					break;
				}
			}while(choice!=5);
		}
		break;
		case 2:
		{
			with_replacement w1;
			do
			{
				choice=menu();
				switch(choice)
				{
				case 1:
					w1.create();
					break;
				case 2:
					w1.insert();
					break;
				case 3:
					w1.search();
					break;
				case 4:
					w1.display();
					break;
				}
			}while(choice!=5);
		}
		break;
		case 3:
			cout<<"\n\nTHANK YOU!!";
			break;
		default:
			cout<<"\nPlease enter a valid option!!";
		}
	}while(choice!=3);
}
