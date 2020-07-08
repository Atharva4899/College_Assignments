/*
 * Queue.h
 *
 *  Created on: 18-Jan-2019
 *      Author: f11
 */

#ifndef QUEUE_H_
#define QUEUE_H_

template<typename T>
class Queue
{
	struct node
	{
		T d;
		int prior;
		struct node* next;
	};
	struct node* head;
	struct node* rear;
public:
	Queue();
	virtual ~Queue();
	void enqueue(T);
	T dequeue();
	int isEmpty();
	int displayRec(T[]);
};

#endif /* QUEUE_H_ */
