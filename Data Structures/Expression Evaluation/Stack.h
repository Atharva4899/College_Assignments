/*
 * stack.h
 *
 *  Created on: 26-Dec-2018
 *      Author: f11
 */

#ifndef STACK_H_
#define STACK_H_

template<typename T>
class stack {
	struct node
	{
		T data;
		struct node* next;
	};
	struct node* top;
public:
	stack();
	virtual ~stack();
	void push(T x);
	T pop();
	int isEmpty();
	T peep();
};

#endif /* STACK_H_ */
