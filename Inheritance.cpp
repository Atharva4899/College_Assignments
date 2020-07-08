//============================================================================
// Name        : Inheritance.cpp
// Author      : Atharva Kulkarni,23329,F11
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
#include<string>
#define MAX 50
using namespace std;

class date
{
	int date,month,year;
	public:
		void setDOB();
		void getDOB();
};
void date::setDOB()
{
	int flag;
	do
	{
		cout<<"Date of Birth:\n";
		flag=0;
		cout<<"\tEnter Date:\t";
		cin>>date;
		cout<<"\tEnter Month:\t";
		cin>>month;
		cout<<"\tEnter Year:\t";
		cin>>year;
		if(date<1||date>31||month<1||month>12||year<1900||year>2018)
			{
				flag=1;
				cout<<"Invalid Date!!\n";
			}
	}while(flag==1);
}
void date::getDOB()
{
	cout<<date<<"/"<<month<<"/"<<year;
}

class basicInfo
{
        protected:
               char name[30];
               date dob;
               char bloodGp[5];
        public:
                void setName();
                void setBgp();
                char* getName();
                char* getBgp();
};
void basicInfo::setName()
{
	int flag=0;
	cin.ignore();
	do
	{
		cout<<"Enter name:\t";
		//cin.ignore();
		cin.getline(name,30);
		for(int i=0;name[i]!='\0';i++)
		{
			flag=0;
			if(!isalpha(name[i]))
			{
				flag=1;
				cout<<"Invalid name!\n";
				break;
			}
		}
	}while(flag==1);
}
char* basicInfo::getName()
{
	return name;
}
void basicInfo::setBgp()
{
	cout<<"Enter Blood Group:\t";
	cin>>bloodGp;
}
char* basicInfo::getBgp()
{
	return bloodGp;
}

class Health
{
        protected:
                float height,weight;
        public:
                void setHeight();
                void setWeight();
                float getHeight();
                float getWeight();
};
void Health::setHeight()
{
	int flag=0;
	do
	{
		cout<<"Enter Height(in Feet):\t";
		cin>>height;
		if(height<=0)
		{
			cout<<"Invalid height!\n";
			flag=1;
		}
	}while(flag==1);
}
void Health::setWeight()
{
	int flag=0;
	do
	{
		flag=0;
		cout<<"Enter Weight(in Kg):\t";
		cin>>weight;
		if(weight<=0)
		{
			cout<<"Invalid Weight!\n";
			flag=1;
		}
	}while(flag==1);
}
float Health::getHeight()
{
	return height;
}
float Health::getWeight()
{
	return weight;
}

class Insurance
{
        protected:
                int pol_no;
                char address[100];
        public:
                void setPol();
                void setAddress();
                int getPol();
                char* getAddress();
};
void Insurance::setAddress()
{
	cout<<"Enter Residential Address:\t";
	cin.ignore();
	cin.getline(address,100);
}
void Insurance::setPol()
{
		cout<<"Enter Policy No.:\t";
		cin>>pol_no;
}
int Insurance::getPol()
{
	return pol_no;
}
char* Insurance::getAddress()
{
	return address;
}

class Record:public basicInfo,public Health,public Insurance
{
        int license,telephone;
        public:
                void setLicense();
                int valPol(Record*[],int,int);
                void setTele();
                int getLicense();
                int getTele();
                void setAll(Record*[],int);
                void getAll();
                int searchRec(Record*[],int);
                void updateRec(Record*[],int,int);
                void deleteRec(Record*[],int,int);
};
void Record::setLicense()
{
	cout<<"Enter License ID:\t";
	cin>>license;
}
int Record::valPol(Record* r[],int size,int pol)
{
	int flag;
	for(int i=0;i<size;i++)
	{
		flag=0;
		if(r[i]->pol_no==pol)
		{
			flag=1;
			break;
		}
	}
	return flag;
}
void Record::setTele()
{
	cout<<"Enter Telephone No.:\t";
	cin>>telephone;
}
int Record::getLicense()
{
	return license;
}
int Record::getTele()
{
	return telephone;
}
void Record::setAll(Record* r[],int size)
{
	int flag;
	int pol;
	dob.setDOB();
	setName();
	setBgp();
	setHeight();
	setWeight();
	setAddress();
	do
	{
		flag=0;
		setPol();
		pol=getPol();
		flag=valPol(r,size,pol);
		if(flag==1)
		{
			cout<<"This Policy Already Exists!\n";
		}
	}while(flag==1);
	setLicense();
	setTele();
}
void Record::getAll()
{
	cout<<"D.O.B.:\t";
	dob.getDOB();
	cout<<"\nName:\t"<<getName();
	cout<<"\nBlood Group:\t"<<getBgp();
	cout<<"\nHeight:\t"<<getHeight();
	cout<<"\nWeight:\t"<<getWeight();
	cout<<"\nAddress:\t"<<getAddress();
	cout<<"\nPolicy no.:\t"<<getPol();
	cout<<"\nLicense ID:\t"<<getLicense();
	cout<<"\nTelephone:\t"<<getTele();
	cout<<"\n";
}
int Record::searchRec(Record* r[],int size)
{
	int choice;
	cout<<"Search by:\n\t1.Name\n\t2.License No.\n";
	cin>>choice;
	switch(choice)
	{
	case 1:
		char nquery[30];
		cout<<"\nEnter Name to be searched:\t";
		cin.ignore();
		cin.getline(nquery,30);
		for(int i=0;i<size;i++)
		{
			if((strcmp(nquery,r[i]->name))==0)
			{
				return i;
			}
		}
		break;
	case 2:
		int lquery;
		cout<<"\nEnter License ID to be searched:\t";
		cin>>lquery;
		for(int i=0;i<size;i++)
		{
			if(lquery==r[i]->license)
			{
				return i;
			}
		}
		break;
	default:
		cout<<"\nInvalid Input!\n";
		break;
	}
	return -1;
}
void Record::updateRec(Record* r[],int pos,int size)

{
	int choice,cont,flag,pol;
	do
	{
		cout<<"Update:\n\t1.Height\n\t2.Weight\n\t3.Telephone\n\t4.Address\n\t5.Insurance Policy No.\n\t6.Exit to Main Menu";
		cin>>choice;
		switch(choice)
		{
		case 1:
			r[pos]->setHeight();
			cout<<"\nPress 1 to continue else press 0:\t";
			cin>>cont;
			break;
		case 2:
			r[pos]->setWeight();
			cout<<"\nPress 1 for Update Menu else press 0:\t";
			cin>>cont;
			break;
		case 3:
			r[pos]->setTele();
			cout<<"\nPress 1 for Update Menu else press 0:\t";
			cin>>cont;
			break;
		case 4:
			r[pos]->setAddress();
			cout<<"\nPress 1 for Update Menu else press 0:\t";
			cin>>cont;
			break;
		case 5:
			r[pos]->setPol();
			pol=r[pos]->getPol();
			flag=r[pos]->valPol(r,pos,pol);
			if(flag==1)
			{
				cout<<"This Policy Already Exists!\n";
			}
			cout<<"\nPress 1 for Update Menu else press 0:\t";
			cin>>cont;
			break;
		case 6:
			cont=0;
			break;
		default:
			cout<<"Invalid Input!!";
			cout<<"\nPress 1 for Update Menu else press 0:\t";
			cin>>cont;
			break;
		}
	}while(cont==1);
}
void Record::deleteRec(Record* r[],int pos,int size)
{
	for(int i=pos;i<size;i++)
	{
		r[i+1]=r[i];
	}
}
int main()
{
		setvbuf( stdin, NULL, _IONBF, 0 );
        Record* rec[MAX];
        Record dummy;
        int i,cont,choice,pos,conf;
        static int recno;
        do
        {
                cout<<"------MENU------\n";
		cout<<"\n   1.Add record\n   2.Display records\n   3.Search a record\n   4.Update a record";
		cout<<"\n   5.Delete a record\n    6.Exit\n";
		cout<<"Enter your choice:\t";
		cin>>choice;
		switch(choice)
			{
		        case 1:
		                if(recno<MAX)
		                {
		                        rec[recno]=new Record;
		                        rec[recno]->setAll(rec,recno);
		                        recno++;
		                 }
		                else
		                        cout<<"Capacity is Full!";
		                cout<<"\nPress 1 to continue else press 0:\t";
				cin>>cont;
		                break;
		        case 2:
		                if(recno==0)
		                        cout<<"No Records Entered!";
		                 else
		                 {
		                        for(i=0;i<recno;i++)
		                        {
		                                rec[i]->getAll();
		                        }
		                 }
		                 cout<<"\nPress 1 to continue else press 0:\t";
				 cin>>cont;
		                 break;
		        case 3:
		        	if(recno==0)
		        		cout<<"No Records Entered!";
		        	else
		        	{
		        		pos=dummy.searchRec(rec,recno);
		        		if(pos!=-1)
		        		{
		        			cout<<"\nRecord Found!\n";
		        			rec[pos]->getAll();
		        		}
		        		else
		        			cout<<"\nRecord not Found!";
		        	}
		        	 cout<<"\nPress 1 to continue else press 0:\t";
		        	 cin>>cont;
		        	break;
		        case 4:
		        	if(recno==0)
		        		cout<<"No Records Entered!";
		        	else
		        	{
		        		pos=dummy.searchRec(rec,recno);
		        		if(pos!=-1)
		        		{
		        			cout<<"Record Found!\n";
		        			rec[pos]->getAll();
		        			cout<<"------Press 1 to confirm edit,else press 0------\n";
		        			cin>>conf;
		        			if(conf==1)
		        			{
		        				dummy.updateRec(rec,pos,recno);
		        				cout<<"Record Updated Successfully";
		        			}
		        			else
		        				cout<<"Updation Aborted!";
		        		}
		        		else
		        		{
		        			cout<<"Record not Found!";
		        		}
		        	}
		        	cout<<"\nPress 1 to continue else press 0:\t";
		        	cin>>cont;
		        	break;
		        case 5:
		        	if(recno==0)
		        		cout<<"No Records Entered!";
		        	else
		        	{
		        		pos=dummy.searchRec(rec,recno);
		        		if(pos!=-1)
		        		{
		        			cout<<"Record Found!\n";
		        			rec[pos]->getAll();
		        			cout<<"------Press 1 to confirm delete,else press 0------\n";
		        			cin>>conf;
		        			if(conf==1)
		        			{
		        				dummy.deleteRec(rec,pos,recno);
		        				recno--;
		        				cout<<"Record Deleted Successfully";
		        			}
		        			else
		        				cout<<"Deletion Aborted!";
		        		}
		        		else
		        		{
		        			cout<<"Record not Found!";
		        		}
		        	}
		        	cout<<"\nPress 1 to continue else press 0:\t";
		        	cin>>cont;
		        	break;
		        case 6:
		        	cont=0;
		        	break;
		        default:
		        	cout<<"Invalid Input!!";
		        	cout<<"\nPress 1 to continue else press 0:\t";
		        	cin>>cont;
		        	break;
			}
		}while(cont==1);
}


