//============================================================================
// Name        : exptree.cpp
// Author      : 23328
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include<string.h>
#include "stack.cpp"
#include "stack.h"
#define COUNT 10

using namespace std;

typedef struct node
{
	char data;
	struct node* left;
	struct node* right;
}node;

class ExpTree
{
	node* exptree;
	char exp[30];

public:

	ExpTree()
{
		exptree=NULL;
}

	node* getNode(char c)
	{
		node* temp;
		temp=new node();
		temp->data=c;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}

	node* posttoTree(char exp[])
	{
		node* temp=NULL;
		stack<node*> s;
		int i=0;
		char c;
		while(exp[i]!='\0')
		{
			c=exp[i];
			temp=getNode(c);
			if(isalpha(c)||isdigit(c))
			{
				s.push(temp);
			}
			else
			{
				temp->right=s.pop();
				temp->left=s.pop();
				s.push(temp);
			}
			i++;
		}
		return s.pop();
	}

	void PostToTree()
	{
		exptree=posttoTree(exp);
	}

	node* pretoTree(char exp[])
	{
		node* temp=NULL;
		stack<node*> s;
		char exprev[30];
		char c;
		int l=strlen(exp),i=0;
		for(i=0;i<l;i++)
		{
			exprev[i]=exp[l-i-1];
		}
		exprev[i]='\0';
		i=0;
		while(exprev[i]!='\0')
		{
			c=exprev[i];
			temp=getNode(c);
			if(isalpha(c)||isdigit(c))
			{
				s.push(temp);
			}
			else
			{
				temp->left=s.pop();
				temp->right=s.pop();
				s.push(temp);
			}
			i++;
		}
		return s.pop();
	}

	void PreToTree()
	{
		exptree=pretoTree(exp);
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

	void Print()
	{
		print(exptree,0);
	}

	void preorderRec(node* root)
	{
		if(root!=NULL)
		{
			cout<<root->data<<"  ";
			preorderRec(root->left);
			preorderRec(root->right);
		}
	}

	void PreOrderRec()
	{
		preorderRec(exptree);
	}

	void inorderRec(node* root)
	{
		if(root!=NULL)
		{
			inorderRec(root->left);
			cout<<root->data<<"  ";
			inorderRec(root->right);
		}
	}

	void InOrderRec()
	{
		inorderRec(exptree);
	}

	void postorderRec(node* root)
	{
		if(root!=NULL)
		{
			postorderRec(root->left);
			postorderRec(root->right);
			cout<<root->data<<"  ";
		}
	}

	void PostOrderRec()
	{
		postorderRec(exptree);
	}

	void inorderNRec(node* root)
	{
		stack<node*> s;
		while(true)
		{
			while(root!=NULL)
			{
				s.push(root);
				root=root->left;
			}
			if(s.isEmpty())
			{
				return;
			}
			root=s.pop();
			cout<<root->data<<"  ";
			root=root->right;
		}
	}

	void InOrderNRec()
	{
		inorderNRec(exptree);
	}

	void preorderNRec(node* root)
	{
		stack<node*> s;
		while(true)
		{
			while(root!=NULL)
			{
				cout<<root->data<<"  ";
				s.push(root);
				root=root->left;
			}
			if(s.isEmpty())
				return;
			root=s.pop();
			root=root->right;
		}
	}

	void PreOrderNRec()
	{
		preorderNRec(exptree);
	}

	void postorderNRec(node* root)
	{
		stack<node*> s1,s2;
		node* temp;
		s1.push(root);
		while(!s1.isEmpty())
		{
			temp=s1.pop();
			s2.push(temp);
			if(temp->left!=NULL)
				s1.push(temp->left);
			if(temp->right!=NULL)
				s1.push(temp->right);
		}
		while(!s2.isEmpty())
		{
			temp=s2.pop();
			cout<<temp->data<<"  ";
		}
	}

	void PostOrderNRec()
	{
		postorderNRec(exptree);
	}

	void ipExp()
	{
		cout<<"\nEnter expression:\t";
		cin>>exp;
	}
};

int menu()
{
	int choice;
	cout<<"\nCreate Expression Tree from:\n\t1.Postfix Expression\n\t2.Prefix Expression\n\t3.Exit\n\t";
	cin>>choice;
	return choice;
}

int main()
{
	int cont,choice;
	ExpTree t;
	do
	{
		choice=menu();
		switch(choice)
		{
		case 1:
			t.ipExp();
			t.PostToTree();
			cout<<"\n\nExpression Tree is:\n\n";
			t.Print();

			cout<<"\n\nInorder Recursive Traversal:\n\n";
			t.InOrderRec();
			cout<<"\n\nInorder Non recursive Traversal:\n\n";
			t.InOrderNRec();

			cout<<"\n\nPreorder Recursive Traversal:\n\n";
			t.PreOrderRec();
			cout<<"\n\nPreorder Non recursive Traversal:\n\n";
			t.PreOrderNRec();

			cout<<"\n\nPostorder Recursive Traversal:\n\n";
			t.PostOrderRec();
			cout<<"\n\nPostorder Non recursive Traversal:\n\n";
			t.PostOrderNRec();

			cout<<"\n\nEnter 1 for menu,any other key to exit:\t";
			cin>>cont;

			break;
		case 2:
			t.ipExp();
			t.PreToTree();
			cout<<"\n\nExpression Tree is:\n\n";
			t.Print();

			cout<<"\n\nInorder Recursive Traversal:\n\n";
			t.InOrderRec();
			cout<<"\n\nInorder Non recursive Traversal:\n\n";
			t.InOrderNRec();

			cout<<"\n\nPreorder Recursive Traversal:\n\n";
			t.PreOrderRec();
			cout<<"\n\nPreorder Non recursive Traversal:\n\n";
			t.PreOrderNRec();

			cout<<"\n\nPostorder Recursive Traversal:\n\n";
			t.PostOrderRec();
			cout<<"\n\nPostorder Non recursive Traversal:\n\n";
			t.PostOrderNRec();

			cout<<"\n\nEnter 1 for menu,any other key to exit:\t";
			cin>>cont;

			break;
		case 3:
			cont=0;
			break;
		default:
			cout<<"\n\nInvalid Input!\n\n";
			cont=1;
			break;
		}
	}while(cont==1);
	return 0;
}
