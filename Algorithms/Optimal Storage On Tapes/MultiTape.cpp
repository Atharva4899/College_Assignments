#include<bits/stdc++.h>
using namespace std;

void findMRT(int tape[],int l)
{
	float mrt=0;
	int t1[10],t2[10],t3[10];
	int p1=0,p2=0,p3=0;

	int time1[l],time2[l],time3[l];
	if(l>=1)
	{
		time1[0]=tape[0];
		mrt+=time1[0];
		t1[0]=tape[0];
		p1++;
	}
	if(l>=2)
	{
		time2[0]=tape[1];
		mrt+=time2[0];
		t2[0]=tape[1];
		p2++;
	}

	if(l>=3)
	{
		time3[0]=tape[2];
		mrt+=time3[0];
		t3[0]=tape[2];
		p3++;
	}
	
	for(int i=3;i<l;i++)
	{
		int mod=i%3;
		switch(mod)
		{
			case 0:
				time1[p1]=time1[p1-1]+tape[i];
				t1[p1]=tape[i];
				mrt+=time1[p1];
				p1++;
				break;
			case 1:
				time2[p2]=time2[p2-1]+tape[i];
				t2[p2]=tape[i];
				mrt+=time2[p2];
				p2++;
				break;
			case 3:
				time3[p3]=time3[p3-1]+tape[i];
				t3[p3]=tape[i];
				mrt+=time3[p3];
				p3++;
				break;
		}
	}
	
	mrt/=l;
	
	cout<<"\nOptimal Storage will be:\n";
	for(int i=0;i<p1;i++)
		cout<<t1[i]<<"("<<time1[i]<<")"<<"\t";
	cout<<"\n";

	for(int i=0;i<p2;i++)
		cout<<t2[i]<<"("<<time2[i]<<")"<<"\t";
	cout<<"\n";


	for(int i=0;i<p3;i++)
		cout<<t3[i]<<"("<<time3[i]<<")"<<"\t";
	cout<<"\n";
	
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
