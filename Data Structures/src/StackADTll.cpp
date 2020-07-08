//============================================================================
// Name        : StackADT.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stack.h"
#include "stack.cpp"
using namespace std;

int main() {
	stack<char> s;
	int x;
	char data;
	cout<<"Enter total characters:\t";
	cin>>x;
	cout<<"\nEnter characters:\t";
	for(int i=0;i<x;i++)
	{
		cin>>data;
		s.push(data);
	}
	cout<<"Reversed list is:\n";
	for(int i=0;i<x;i++)
	{
		cout<<s.pop()<<"\t";
	}
	return 0;
}
