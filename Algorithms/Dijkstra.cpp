//============================================================================
// Name        : Djikstra.cpp
// Author      : 23329
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
#include <string>
#include<stack>
#include<queue>
#define infinity 99999
using namespace std;

typedef struct node
{
	char name[20];
	int visited;
	int distance;
	struct node* dlink;
	struct edge* next;
}node;

typedef struct edge
{
	struct node* flink;
	struct edge* nextlink;
	int weight;
}edge;

node* getNode()
{
	node* temp=new node();
	cout<<"\nEnter name:\t";
	cin>>temp->name;
	temp->dlink=NULL;
	temp->next=NULL;
	temp->distance=infinity;
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

	void insertSVertex()
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
				cout<<" -- "<<tlink->weight<<" > "<<tlink->flink->name;
				tlink=tlink->nextlink;
			}
			temp=temp->dlink;
			if(temp!=NULL)
				cout<<"\n|\n";
		}
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

	void insertEdge()
	{
		char f1[30],f2[30];
		int w;
		edge* tlink1=new edge();
		edge* tlink2=new edge();
		edge* t;

		cout<<"Enter name of first Vertex:\t";
		cin>>f1;
		cout<<"Enter name of second Vertex:\t";
		cin>>f2;
		cout<<"Enter weight of edge:\t";
		cin>>w;
		node* fr1=searchVertex(f1);
		node* fr2=searchVertex(f2);

		if(fr1!=NULL && fr2!=NULL)
		{
			tlink1->flink=fr2;
			tlink1->nextlink=NULL;
			tlink1->weight=w;

			t=fr1->next;
			if(t==NULL)
			{
				fr1->next=tlink1;
			}
			else
			{
				while(t->nextlink!=NULL)
					t=t->nextlink;
				t->nextlink=tlink1;
			}

			tlink2->flink=fr1;
			tlink2->nextlink=NULL;
			tlink2->weight=w;

			t=fr2->next;
			if(t==NULL)
			{
				fr2->next=tlink2;
			}
			else
			{
				while(t->nextlink!=NULL)
					t=t->nextlink;
				t->nextlink=tlink2;
			}
		}
		else
		{
			cout<<"\nInvalid Vertices!\n";
		}
	}

	void dijkstra()
	{
		char key[30];
		int pre_dist=0;
		node* temp,*Start;
		edge* tempedge;
		cout<<"\nEnter name of vertex from which distances are needed:\t";
		cin>>key;
		Start=searchVertex(key);
		temp=Start;
		if(temp==NULL)
		{
			cout<<"\nInvalid Vertex\n";
			return;
		}
		temp->distance=0;
		while(temp!=NULL)
		{
			pre_dist=temp->distance;
			tempedge=temp->next;
			while(tempedge!=NULL)
			{
				if(tempedge->flink!=Start)
					if(tempedge->flink->distance>(tempedge->weight+pre_dist))
					{
						tempedge->flink->distance=tempedge->weight+pre_dist;
					}
				tempedge=tempedge->nextlink;
			}
			temp=temp->dlink;
		}
		temp=startVertex;
		cout<<"\nStart Vertex:\t"<<Start->name<<"\n";
		while(temp!=NULL)
		{
			if(temp!=Start)
			{
				cout<<temp->name<<"\t"<<temp->distance<<"\n";
			}
			temp=temp->dlink;
		}
	}
};

int main()
{
	Graph g;
	int edges;
	g.createGraph();
	cout<<"\n\nHow many edges to enter?\t";
	cin>>edges;
	for(int i=0;i<edges;i++)
		g.insertEdge();
	g.dijkstra();
	return 0;
}
