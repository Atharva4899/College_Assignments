/*
 * stack.cpp
 *
 *  Created on: 19-Dec-2018
 *      Author: f11
 */

#include "stack.h"
#include<iostream>
using namespace std;

template<typename T>
stack<T>::stack()
{
	// TODO Auto-generated constructor stub
	top=NULL;
}

template<typename T>
stack<T>::~stack()
{
	// TODO Auto-generated destructor stub
	struct node* temp;
	while(top!=NULL)
	{
		temp=top;
		top=top->next;
		delete(temp);
	}
}

template<typename T>
void stack<T>::push(T x)
{
	struct node* temp;
	temp=new struct node();
	temp->data=x;
	temp->next=top;
	top=temp;
}

template<typename T>
T stack<T>::pop()
{
	struct node* temp;
	temp=top;
	top=top->next;
	T x=temp->data;
	delete(temp);
	return x;
}

template<typename T>
int stack<T>::isEmpty()
{
	if(top==NULL)
		return 1;
	return 0;
}
