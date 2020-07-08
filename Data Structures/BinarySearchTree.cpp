//============================================================================
// Name        : bst.cpp
// Author      : 23328
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define COUNT 10
using namespace std;

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
}node;

node* getNode(int x)
{
	node* temp=new node();
	temp->data=x;
	temp->left=temp->right=NULL;
	return temp;
}

class BST
{
	node* root;
public:
	BST()
	{
		root=NULL;
	}

	node* insertNode(int x,node* r)
	{

		if(r==NULL)
		{
			r=getNode(x);
			return r;
		}
		if(x<r->data)
			r->left=insertNode(x,r->left);
		else if(x>r->data)
			r->right=insertNode(x,r->right);
		else
		{
			cout<<"\nDuplicate Node not allowed!\n";
		}
		return r;
	}

	void createBST()
	{
		int count=0,i,x;
		cout<<"\nHow many nodes?:\t";
		cin>>count;
		for(i=0;i<count;i++)
		{
			cout<<"\nEnter data:\t";
			cin>>x;
			root=insertNode(x,root);
		}
	}

	void Insert()
	{
		int key;
		cout<<"\nEnter data to add:\t";
		cin>>key;
		root=insertNode(key,root);
		Print();
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

	void inorder(node* r)
	{
		if(r!=NULL)
		{
			inorder(r->left);
			cout<<r->data<<" ";
			inorder(r->right);
		}
	}

	void InOrder()
	{
		if(root)
		{
			cout<<"\nInorder Traversal of binary search tree is :\n\n";
			inorder(root);
		}
		else
		{
			cout<<"\n\nTree is Empty!";
		}
	}

	void Print()
	{
		if(root==NULL)
		{
			cout<<"\n\nTree is empty!\n\n";
			return;
		}
		cout<<"\n\nThe Binary Search Tree is:\n\n";
		print(root,0);
	}

	node* searchNode(node* r,int key)
	{
		node* temp=NULL;;
		if (r==NULL)
			return r;
		if(r->data==key)
			return r;
		if(r->data>key)
			temp = searchNode(r->left,key);
		else if(r->data<key)
			temp = searchNode(r->right,key);
		return temp;
	}

	void search()
	{
		if(root)
		{
			node* res;
			int key;
			cout<<"\nEnter data to be searched:\t";
			cin>>key;
			res=searchNode(root,key);
			if(res!=NULL)
				cout<<"\nNode found!\n";
			else
				cout<<"\nNode not found!\n";
		}
		else
			cout<<"\n\nTree is Empty!!";
	}

	node* findmin(node* r)
	{
		node* temp=NULL;
		if(r->left==NULL)
			temp=r;
		else
			temp=findmin(r->left);
		return temp;
	}

	node* deleteNode(node* r,int key)
	{
		node* temp=NULL;
		if(r!=NULL)
		{
			if(key<r->data)
			{
				r->left=deleteNode(r->left,key);
				temp=r;
			}
			else if(key>r->data)
			{
				r->right=deleteNode(r->right,key);
				temp=r;
			}
			else if(key==r->data)	//node found
			{
				if(r->left==NULL&&r->right==NULL)
				{
					delete(r);
					temp=NULL;
				}
				else if(r->left==NULL)
				{
					temp=r->right;
					delete(r);
				}
				else if(r->right==NULL)
				{
					temp=r->left;
					delete(r);
				}
				else
				{
					temp=findmin(r->right);
					r->data=temp->data;
					r->right=deleteNode(r->right,temp->data);
					temp=r;
				}
			}
		}
		else
		{
			cout<<"\nNode not found!\n";
			temp=r;
		}
		return temp;
	}

	void DeleteNode()
	{
		if(root)
		{
			int key;
			cout<<"\nEnter data to delete:\t";
			cin>>key;
			root=deleteNode(root,key);
			Print();
		}
		else
			cout<<"\n\nTree is Empty!!";
	}

	node* mirror(node* r)
	{
		node* temp=NULL;
		if(r!=NULL)
		{
			if(r->left==NULL&&r->right==NULL)
				temp=r;
			else
			{
				temp=r->left;
				r->left=mirror(r->right);
				r->right=mirror(temp);
				temp=r;
			}
		}
		return temp;
	}

	void Mirror(int flag)
	{
		if(root)
		{
			root=mirror(root);
			if(flag)
				{
					cout<<"\nTree mirrored successfully!\n";
					Print();
				}
		}
		else
			cout<<"\n\nTree is Empty!!";
	}
};

int menu()
{
	int choice;
	cout<<"\nMENU:\n\t1.Insert node\n\t2.Search node\n\t3.Display Tree\n\t4.Delete node\n\t5.Mirror Tree\n\t6.Exit\n\t";
	cin>>choice;
	return choice;
}

int main()
{
	BST b;
	int cont,choice;
	b.createBST();
	cout<<"\n";
	b.Print();
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			b.Insert();
			cout<<"\n\nEnter 1 for menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 2:
			b.search();
			cout<<"\n\nEnter 1 for menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 3:
			b.Print();
			cout<<"\n\nEnter 1 for menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 4:
			b.DeleteNode();
			cout<<"\n\nEnter 1 for menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 5:
			b.Mirror(1);
			b.Mirror(0);
			cout<<"\n\nEnter 1 for menu,any other key to exit:\t";
			cin>>cont;
			break;
		case 6:
			cont=0;
			break;
		default:
			cout<<"\nInvalid choice!!\n";
			cont=1;
			break;
		}
	}while(cont==1);
	return 0;
}
