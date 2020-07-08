//============================================================================
// Name        : binarytree.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define COUNT 10

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
}node;

node* getNode()
{
	node* temp=new node();
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

node* createTree(node* root)
{
	char ip;
	int l,r;

	if(root==NULL)
	{
		cout<<"\nEnter data:\t";
		cin>>ip;
		root=getNode();
		root->data=ip;
	}

	cout<<"\nCurrent node data:\t"<<root->data<<"\n";
	cout<<"\nPress 1 to go left,else press 0:\t";
	cin>>l;
	if(l==1)
		root->left=createTree(root->left);

	cout<<"\nCurrent node data:\t"<<root->data<<"\n";
	cout<<"\nPress 1 to go right,else press 0:\t";
	cin>>r;
	if(r==1)
		root->right=createTree(root->right);

	return root;
}

node* insertNode(node* root)
{
	char ip;
	int l,r;

	if(root==NULL)
	{
		cout<<"\nEnter data:\t";
		cin>>ip;
		root=getNode();
		root->data=ip;
		return root;
	}
	else
	{
		cout<<"\nCurrent node data:\t"<<root->data<<"\n";
		cout<<"\nPress 1 to go left,else press 0:\t";
		cin>>l;
		if(l==1)
		{
			root->left=insertNode(root->left);
			return root;
		}

		cout<<"\nCurrent node data:\t"<<root->data<<"\n";
		cout<<"\nPress 1 to go right,else press 0:\t";
		cin>>r;
		if(r==1)
		{
			root->right=insertNode(root->right);
			return root;
		}
	}

	return root;
}

void displayTree(node* root)
{
	if(root!=NULL)
	{
		displayTree(root->left);
		cout<<root->data<<"\t";
		displayTree(root->right);
	}
}

void displayLeaves(node* root)
{
	if(root!=NULL)
	{
		if(root->left==NULL && root->right==NULL)
		{
			cout<<root->data<<"\t";
		}
		displayLeaves(root->left);
		displayLeaves(root->right);
	}
}

int depthofTree(node* root)
{
	int htl,htr;
	htl=htr=0;
	if(root==NULL)
	{
		return 0;
	}
	else
	{
		htl=depthofTree(root->left)+1;
		htr=depthofTree(root->right)+1;
	}
	return htl>htr?htl:htr;
}

node* copyTree(node* root)
{
	node* newtree=NULL;
	if(root!=NULL)
	{
		newtree=new node();
		newtree->data=root->data;
		newtree->left=copyTree(root->left);
		newtree->right=copyTree(root->right);
	}
	return newtree;
}

void print(node* root,int space)
{
	if(root==NULL)
		return;
	space+=COUNT;
	print(root->right,space);
	cout<<"\n";
	for(int i=COUNT;i<space;i++)
		cout<<" ";
	cout<<root->data;
	print(root->left,space);
}

int menu()
{
	int choice;
	cout<<"\nMenu:\n\t1.Insert Node(s)\n\t2.Display Tree\n\t3.Display Leaves\n\t4.Depth of Tree\n\t5.Create Copy of Tree\n\t6.Exit\n\t";
	cin>>choice;
	return choice;
}

int main()
{
	node* root=NULL,*copytree=NULL;;
	int cont,choice,depth=0;
	root=createTree(root);
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			root=insertNode(root);
			cout<<"\nPress 1 for Menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 2:
			cout<<"Tree is as follows:\n";
			print(root,0);
			cout<<"\n\nPress 1 for Menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 3:
			cout<<"\nLeaf nodes are:\n\n";
			displayLeaves(root);
			cout<<"\n\nPress 1 for Menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 4:
			depth=depthofTree(root);
			cout<<"\nDepth of the Tree is:\t"<<depth<<"\n";
			cout<<"\n\nPress 1 for Menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 5:
			copytree=copyTree(root);
			cout<<"Copied Tree is :\n";
			print(copytree,0);
			cout<<"\n\nPress 1 for Menu, any other key to exit:\t";
			cin>>cont;
			break;
		case 6:
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
