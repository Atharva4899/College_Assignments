//============================================================================
// Name        : Weather_Report.cpp
// Author      : Atharva Kulkarni
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<iomanip>
using namespace std;

int i;
static int count;
class weather
{
 	private:
	float htemp,ltemp,rain,snow;
	static float htavg,ltavg,ravg,savg;
	public:
	int flag=0;
		weather()
	{
			flag=0;
			htemp=999;
			ltemp=-999;
			rain=999;
			snow=999;
	}
		void getdata();
		void avg1();
		void favg();
		void displaydata();
		void clravg();
};

float weather::htavg;
float weather::ltavg;
float weather::ravg;
float weather::savg;

void weather::getdata()

	{
		do
		{
		 cout<<"Highest Temp, Lowest Temp, Rain(mm),Snow(mm):";
		 cin>>htemp>>ltemp>>rain>>snow;
		 if(rain<0 || snow<0 || htemp<ltemp)
		 {
			cout<<"\nWrong Input!!!\n";
		 }
		}while(rain<0 || snow<0 || htemp<ltemp);
	}

void weather::displaydata()
{
	cout<<(i+1)<<setw(15)<<htemp<<setw(25)<<ltemp<<setw(20)<<rain<<setw(25)<<snow<<"\n";
}

void weather::avg1()
{
	htavg+=htemp;
	ltavg+=ltemp;
	ravg+=rain;
	savg+=snow;
}

void weather::favg()
{
	htavg/=count;
	ltavg/=count;
	ravg/=count;
	savg/=count;
	cout<<"Average Monthly Report:";
	cout<<"\nHighest Temperature:"<<htavg;
	cout<<"\nLowest Temperature:"<<ltavg;
	cout<<"\nRainfall(mm):"<<ravg;
	cout<<"\nSnowfall(mm):"<<savg;
}
void weather::clravg()
{
	htavg=0;
	ltavg=0;
	ravg=0;
	savg=0;
}

int main()
{
	weather w[31];
	int choice,cont,date,lastentered;
	do
	{	cout<<"------MENU------\n\n";
		cout<<"   1.Enter Values\n   2.Display Monthly Report\n   3.Display values\n   4.Exit\n\n";
		cout<<"Enter your choice:   ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				do
				{
					cout<<"Enter date for which data is to be entered:\t";
					cin>>date;
					if(date<1 || date>31)
						cout<<"\tInvalid date!!\n";
				}while(date<1 || date>31);
						w[(date-1)].getdata();
						if(w[(date-1)].flag==0)
						{
							w[(date-1)].flag=1;
							count++;
						}
				cout<<"Press 1 to go back, 0 to exit:\t";
				cin>>cont;
			break;
			case 2:
				if(count==0)
				{
					cout<<"\tNo data entered!";
				}
				else
				{
					for(i=0;i<31;i++)
						if(w[i].flag==1)
							{
								lastentered=i;
								w[i].avg1();
							}
					w[lastentered].favg();
				}
				for(i=0;i<31;i++)
					w[i].clravg();
				cout<<"\nPress 1 to go back, 0 to exit:\t";
				cin>>cont;
			break;
			case 3:
				if(count==0)
				{
					cout<<"\tNo data entered!";
				}
				else
				{
					cout<<"\tHighest Temp"<<setw(25)<<"Lowest Temp"<<setw(25)<<"Rainfall(mm)"<<setw(25)<<"Snowfall\n";
					for(i=0;i<31;i++)
						if(w[i].flag==1)
							w[i].displaydata();
				}
				cout<<"\nPress 1 to go back, 0 to exit:\t";
				cin>>cont;
			break;
			case 4:
				cont=0;
			break;
			default:
				cout<<"\n\tWrong Input!!!";
				cout<<"\nPress 1 to go back, 0 to exit:\t";
				cin>>cont;
			break;
		}
	}while(cont==1);
return 0;
}



