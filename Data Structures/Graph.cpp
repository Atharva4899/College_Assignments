//============================================================================
// Name        : Graph.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <string>
#include<stack>
#include<queue>
using namespace std;

typedef struct node
{
	char name[20];
	int comments;
	int posts;
	int friends;
	int visited;
	struct node* dlink;
	struct edge* next;
}node;

typedef struct edge
{
	struct node* flink;
	struct edge* nextlink;
}edge;

node* getNode()
{
	node* temp=new node();
	cout<<"\nEnter name:\t";
	cin>>temp->name;
	cout<<"\nEnter total comments:\t";
	cin>>temp->comments;
	temp->dlink=NULL;
	temp->next=NULL;
	return temp;
}

class Graph
{
	node* startVertex;
	int totalVertices;
public:
	Graph()
{
		startVertex=NULL;
		totalVertices=0;
}

	node* insertVertex(node* vertex,node* temp)
	{

		if(vertex==NULL)
		{
			totalVertices++;
			return temp;
		}
		else if(strcmp(temp->name,vertex->name)==0)
		{
			cout<<"\n\tInvalid!! Duplication not allowed!";
			return vertex;
		}
		else
		{
			vertex->dlink = insertVertex(vertex->dlink,temp);
			return vertex;
		}
	}

	void createGraph()
	{
		int tot;
		node* temp;
		cout<<"\nEnter total vertices in the graph:\t";
		cin>>tot;
		for(int i=0;i<tot;i++)
		{
			temp=getNode();
			startVertex=insertVertex(startVertex,temp);
		}
	}

	void insertPerson()
	{
		node* temp=getNode();
		startVertex=insertVertex(startVertex,temp);
	}

	void displayAdjList()
	{
		node* temp=startVertex;
		edge* tlink;
		while(temp!=NULL)
		{
			tlink=temp->next;
			cout<<temp->name;
			while(tlink!=NULL)
			{
				cout<<"->"<<tlink->flink->name;
				tlink=tlink->nextlink;
			}
			temp=temp->dlink;
			if(temp!=NULL)
				cout<<"\n|\n";
		};
	}

	node* searchVertex(char key[])
	{
		node* temp=startVertex;
		while(temp!=NULL)
		{
			if(strcmp(key,temp->name)==0)
			{
				return temp;
			}
			temp=temp->dlink;
		}
		return NULL;
	}

	void insertFriend()
	{
		char f1[30],f2[30];
		edge* tlink1=new edge();
		edge* tlink2=new edge();
		edge* t;

		cout<<"Enter name of first friend:\t";
		cin>>f1;
		cout<<"Enter name of second friend:\t";
		cin>>f2;
		node* fr1=searchVertex(f1);
		node* fr2=searchVertex(f2);

		if(fr1!=NULL && fr2!=NULL)
		{
			tlink1->flink=fr2;
			tlink1->nextlink=NULL;

			t=fr1->next;
			if(t==NULL)
			{
				fr1->next=tlink1;
				fr1->friends++;
			}
			else
			{
				while(t->nextlink!=NULL)
					t=t->nextlink;
				t->nextlink=tlink1;
				fr1->friends++;
			}

			tlink2->flink=fr1;
			tlink2->nextlink=NULL;

			t=fr2->next;
			if(t==NULL)
			{
				fr2->next=tlink2;
				fr2->friends++;
			}
			else
			{
				while(t->nextlink!=NULL)
					t=t->nextlink;
				t->nextlink=tlink2;
				fr2->friends++;
			}
		}
		else
		{
			cout<<"\nInvalid Vertices!\n";
		}
	}

	node* maxFriends(node* current)
	{
		queue<node *>q;
		node* p,*max=current;
		edge* temp=NULL;
		q.push(current);
		current->visited=1;
		while(!q.empty())
		{
			p=q.front();
			q.pop();
			if(p->friends>max->friends)
				max=p;
			temp=p->next;
			while(temp!=NULL)
			{
				if((temp->flink)->visited!=1)
				{
					q.push(temp->flink);
					(temp->flink)->visited=1;
				}
				temp=temp->nextlink;
			}
		}
		p=startVertex;
		while(p!=NULL)
		{
			if(p->visited==0)
			{
				p=maxFriends(p);
				if(p->friends>max->friends)
					max=p;
			}
			p=p->dlink;
		}
		return max;
	}

	void MaxFriends()
	{
		node* max;
		max=maxFriends(startVertex);
		cout<<"\n"<<max->name<<" has max friends, i.e. "<<max->friends<<"\n";
		unvisit();
	}

	node* minComments(node* current,node* min)
	{
		current->visited=1;
		if(current->comments<min->comments)
		{
			min=current;
		}
		edge* temp=current->next;
		while(temp!=NULL)
		{
			if((temp->flink)->visited!=1)
			{
				min=minComments(temp->flink,min);
			}
			temp=temp->nextlink;
		}
		return min;
	}

	void MinComments()
	{
		node* min=NULL;
		node* p=startVertex;
		min=minComments(startVertex,startVertex);
		while(p!=NULL)
		{
			if(p->visited!=1)
			{
				min=minComments(p,min);
			}
			p=p->dlink;
		}
		cout<<"\n"<<min->name<<" has least comments i.e. "<<min->comments<<"\n";
		unvisit();
	}

	void unvisit()
	{
		node* p=startVertex;
		while(p!=NULL)
		{
			p->visited=0;
			p=p->dlink;
		}
	}

};

int menu()
{
	int choice;
	cout<<"\nMENU:\n";
	cout<<"\n\t1.Insert new Person\n\t2.Make Friends\n\t3.Who has Max Friends?\n\t4.Who has Min Comments?\n\t5.Display Adj List\n\t6.Exit\n\t";
	cin>>choice;
	return choice;
}

int main()
{
	Graph G;
	int cont,choice,t;
	G.createGraph();
	G.displayAdjList();
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			G.insertPerson();
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 2:
			cout<<"\nHow many pairs of friends?\t";
			cin>>t;
			for(int i=0;i<t;i++)
				G.insertFriend();
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 3:
			G.MaxFriends();
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 4:
			G.MinComments();
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 5:
			G.displayAdjList();
			cout<<"\nPress 1 for menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 6:
			cont=0;
			break;
		default:
			cout<<"\n\tInvalid!!\n";
			cont=1;
			break;
		}
	}while(cont==1);
	return 0;
}
