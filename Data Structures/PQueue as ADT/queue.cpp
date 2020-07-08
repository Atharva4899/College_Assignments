/*
 * Queue.cpp
 *
 *  Created on: 18-Jan-2019
 *      Author: f11
 */

#include "queue.h"
#include <iostream>
#include<iomanip>
using namespace std;

template<typename T>
Queue<T>::Queue()
{
	head=rear=NULL;
	// TODO Auto-generated constructor stub
}

template<typename T>
Queue<T>::~Queue()
{
	// TODO Auto-generated destructor stub
}

template<typename T>
int Queue<T>::isEmpty()
{
	if(head==NULL&&rear==NULL)
		return 1;
	return 0;
}

template<typename T>
void Queue<T>::enqueue(T def)

{
	struct node* t=new struct node();
	t->next=NULL;
	if(isEmpty())
	{
		head=rear=t;
	}
	else
	{
		rear->next=t;
		rear=t;
	}
	t->d=def;
	t->prior=def.prior;
}

template<typename T>
T Queue<T>::dequeue()
{
	T def;
	struct node* temp,*pr,*t;
	pr=temp=t=head;
	if(head==rear)
	{
		def=head->d;
		head=rear=NULL;
		return def;
	}
	while(pr->prior!=1 && temp->next!=NULL)
	{
		if((temp->next)->prior < pr->prior)
		{
			pr=temp->next;
			t=temp;
		}
		temp=temp->next;
	}
	def=pr->d;
	if(pr==head)
	{
		head=head->next;
		delete(pr);
	}
	else if(pr==rear)
	{
		rear=t;
		rear->next=NULL;
		delete(pr);
	}
	else
	{
		t->next=pr->next;
		delete(pr);
	}
	return def;
}

template<typename T>
int Queue<T>::displayRec(T def[])
{
	int i=0;
	struct node* temp=head;
	if(!isEmpty())
	{
		while(temp!=NULL)
		{
			def[i]=temp->d;
			i++;
			temp=temp->next;
		}

	}
	else
		cout<<"\n\nNo patients remaining!\n\n";
	return i;
}
