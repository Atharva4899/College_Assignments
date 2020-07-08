/*
 * SllADT.h
 *
 *  Created on: 21-Dec-2018
 *      Author: f11
 */

#ifndef SLLADT_H_
#define SLLADT_H_

struct node
{
	int data;
	struct node* next;
};

class SllADT {
	struct node* head;
public:
	SllADT();
	virtual ~SllADT();
	struct node* getnode();
	void insertnode();
	void deletenode();
	void reverselist();
	void display();
};

#endif /* SLLADT_H_ */
