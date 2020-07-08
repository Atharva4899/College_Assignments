/*
 * SllADT.cpp
 *
 *  Created on: 21-Dec-2018
 *      Author: f11
 */

#include "SllADT.h"
#include<iostream>
using namespace std;

SllADT::SllADT() {
	// TODO Auto-generated constructor stub
	head=NULL;
}

SllADT::~SllADT() {
	// TODO Auto-generated destructor stub
	struct node* temp,*t;
	temp=head;
	while(temp!=NULL)
	{
		t=temp->next;
		delete(temp);
		temp=t;
	}
	head=NULL;
}

struct node* SllADT::getnode()
{
	struct node* temp;
	temp=new struct node();
	int x;
	cout<<"Enter data:\t";
	cin>>x;
	temp->data=x;
	temp->next=NULL;
	return temp;
}

void SllADT::insertnode()
{
	int choice;
	struct node*temp=getnode();
	struct node* t=head;
	cout<<"Enter position to insert(0 for beginning,-1 for end)";
	cin>>choice;
	switch(choice)
	{
	case 0:
		temp->next=head;
		head=temp;
		break;
	case -1:
		if(t==NULL)
		{
			head=temp;
		}
		else
		{
			while(t->next!=NULL)
				t=t->next;
			t->next=temp;
		}
		break;
	default:
		for(int i=0;i<choice-1&&t!=NULL;i++)
			t=t->next;
		if(t!=NULL)
		{
			temp->next=t->next;
			t->next=temp;
		}
		else
		{
			cout<<"Invalid position\n";
			delete(temp);
		}
		break;
	}
}

void SllADT::display()
{
	struct node* temp;
	temp=head;
	if(head==NULL)
		cout<<"List is empty\n";
	while(temp!=NULL)
	{
		cout<<temp->data<<"\t";
		temp=temp->next;
	}
	cout<<"\n";
}

void SllADT::deletenode()
{
	int choice;
	struct node*temp=head;
	struct node* t=head;
	if(head!=NULL)
	{
		cout<<"Enter position to delete(0 for beginning,-1 for end)";
		cin>>choice;
		switch(choice)
		{
		case 0:
			temp=head->next;
			delete(t);
			head=temp;
			break;
		case -1:
			if(head->next==NULL)
			{
				delete(t);
				head=NULL;
			}
			else
			{
				while(t->next!=NULL)
				{
					temp=t;
					t=t->next;
				}
				temp->next=NULL;
				delete(t);
			}
			break;
		default:
			temp=head;
			t=temp->next;
			for(int i=0;i<choice-1&&t!=NULL;i++)
			{
				temp=temp->next;
				t=temp->next;
			}
			if(t!=NULL)
			{
				temp->next=t->next;
				delete(t);
			}
			else
				cout<<"Invalid position\n";
			break;
		}
	}
	else
		cout<<"List is Empty\n";
}

void SllADT::reverselist()
{
	struct node* temp,*res,*t;
	temp=head;
	res=NULL;

	if(head!=NULL/*&&head->next!=NULL*/)
	{
		t=temp->next;
		while(t->next!=NULL)
		{
			t=temp->next;
			temp->next=res;
			res=temp;
			temp=t;
		}
		head=res;
	}
	else
	{
		cout<<"List is empty\n";
	}
}
