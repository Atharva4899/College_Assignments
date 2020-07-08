#include<bits/stdc++.h>
using namespace std;

void findMRT(int tape[],int l)
{
	float mrt=0;

	int time[l];
	time[0]=tape[0];
	mrt+=time[0];
	
	for(int i=1;i<l;i++)
	{
		time[i]=time[i-1]+tape[i];
		mrt+=time[i];
	}
	
	mrt/=l;
	
	cout<<"\nOptimal Storage will be:\n";
	for(int i=0;i<l;i++)
		cout<<tape[i]<<"\t";
	
	cout<<"\n\nMRT is:\t"<<mrt<<"\n";
}

int main()
{
	int tape[10],size;
	
	cout<<"Enter total no of elements:\n";
	cin>>size;
	
	cout<<"Enter lengths of each element:\n";
	for(int i=0;i<size;i++)
	{
		cin>>tape[i];
	}
	
	sort(tape,tape+size);
	
	findMRT(tape,size);
	
}
