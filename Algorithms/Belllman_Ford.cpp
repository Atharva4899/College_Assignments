#include <bits/stdc++.h>
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
	node* startnode;
	int totalnodes;
	public:
	Graph()
	{
		startnode=NULL;
		totalnodes=0;
	}

	node* insertnode(node* vertex,node* temp)	//insert single node in graph
	{

		if(vertex==NULL)	//first vertex
		{
			totalnodes++;
			return temp;
		}
		else if(strcmp(temp->name,vertex->name)==0)	//duplicate
		{
			cout<<"\n\tDuplicate node!";
			return vertex;
		}
		else	
		{
			vertex->dlink = insertnode(vertex->dlink,temp);
			return vertex;
		}
	}

	void createGraph()	//create graph with n vertices
	{
		int node_ct;
		node* temp;
		
		cout<<"\nEnter total nodes in the graph:\t";
		cin>>node_ct;
		
		for(int i=0;i<node_ct;i++)
		{
			temp=getNode();
			startnode=insertnode(startnode,temp);
		}
	}

	node* searchnode(char name[])	//find particular vertex
	{
		node* temp=startnode;
		while(temp!=NULL)
		{
			if(strcmp(name,temp->name)==0)
			{
				return temp;
			}
			temp=temp->dlink;
		}
		return NULL;
	}

	void insertlink()
	{
		char f1[30],f2[30];
		int w;
		edge* tlink1=new edge();
		edge* tlink2=new edge();
		edge* t;

		cout<<"Enter name of first node:\t";
		cin>>f1;
		cout<<"Enter name of second node:\t";
		cin>>f2;
		cout<<"Enter weight of edge:\t";
		cin>>w;
		node* fr1=searchnode(f1);
		node* fr2=searchnode(f2);

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

		}
		else
		{
			cout<<"\nInvalid node(s)!\n";
		}
	}

	void bellmanford()
	{
		char name[30];
		int pre_dist=0;
		node *temp,*Start;
		edge *tempedge;
		
		cout<<"\nEnter starting node name:\t";
		cin>>name;
		
		Start=searchnode(name);
		
		temp=Start;
		
		if(temp==NULL)	//node not found
		{
			cout<<"\nInvalid node\n";
			return;
		}
		
		for(int i=0;i<totalnodes;i++)	//loop for n-1 times
		{
			temp=Start;
			temp->distance=0;
			int flag=0;

			do
			{
				pre_dist=temp->distance;
				tempedge=temp->next;

				while(tempedge!=NULL)
				{
					if(tempedge->flink!=Start)
						if(tempedge->flink->distance>(tempedge->weight+pre_dist))
						{
							tempedge->flink->distance=tempedge->weight+pre_dist;
							flag=1;
						}
					tempedge=tempedge->nextlink;
				}

				temp=temp->dlink;
				if(temp==NULL)
					temp=startnode;

			}while(temp!=Start);

			if(flag==0)
				break;
		}

		temp=Start;

		do	//check for negative edge cycle
		{
			pre_dist=temp->distance;
			tempedge=temp->next;
			
			while(tempedge!=NULL)
			{
				if(tempedge->flink!=Start)
					if(tempedge->flink->distance>(tempedge->weight+pre_dist))
					{
						cout<<"Negative cycle!\n\n";
						return;
					}
				tempedge=tempedge->nextlink;
			}
			
			temp=temp->dlink;
			
			if(temp==NULL)
				temp=startnode;
				
		}while(temp!=Start);


		temp=startnode;
		cout<<"\nStart node:\t"<<Start->name<<"\n";
		
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
	int edge_ct;
	
	g.createGraph();
	cout<<"\n\nTotal edges in graph:\t";
	cin>>edge_ct;
	
	for(int i=0;i<edge_ct;i++)
		g.insertlink();
		
	g.bellmanford();
	return 0;
}