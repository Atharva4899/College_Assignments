#include<iostream>
#include<string.h>
#include<string>
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

class Personal
{
	protected:
	char name[20];
	long int ph_no;
	long int UID;
	date d;
	public:
	Personal()
	{
		strcpy(name,"");
		ph_no=0;
		UID=0;
	}
	Personal(char s[],long int mob,long int uid)
	{
		strcpy(name,s);
		ph_no=mob;
		UID=uid;
	}
	void setName()
	{
		int flag=0;
		cin.ignore();
			do
			{
				cout<<"Enter name:\t";
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
	char* getName()
	{
		return name;
	}
	void setPhone()
	{
		cout<<"Enter phone number:\t";
		cin>>ph_no;
	}
	long int getPhone()
	{
		return ph_no;
	}
	void setUID()
	{
		cout<<"Enter UID no.:\t";
		cin>>UID;
	}
	long int getUID()
	{
		return UID;
	}
};

class Professional
{
	protected:
	int yrs_exp;
	unsigned int salary;
	char post[20];
	public:
	Professional()
	{
		yrs_exp=0;
		salary=10000;
		strcpy(post,"");
	}
	Professional(int yr,unsigned int sal,char pst[])
	{
		yrs_exp=yr;
		salary=sal;
		strcpy(post,pst);
	}
	void setExp()
	{
		do
		{
			cout<<"Enter total Years of Experience:\t";
			cin>>yrs_exp;
			if(yrs_exp<0)
			{
				cout<<"Invalid Input!\n";
			}
		}while(yrs_exp<0);
	}
	int getExp()
	{
		return yrs_exp;
	}
	void setSal()
	{
		do
		{
			cout<<"Enter Salary:\t";
			cin>>salary;
			if(salary<=0)
			{
				cout<<"Invalid Salary\n";
			}
		}while(salary<=0);
	}
	unsigned int getSal()
	{
		return salary;
	}
	void setPost()
	{
		cout<<"Enter Post:\t";
		cin.ignore();
		cin.getline(post,20);
	}
	char* getPost()
	{
		return post;
	}
};

class Academic
{
	protected:
	int year_pass;
	char qualification[30];
	char university[30];
	public:
	Academic()
	{
		year_pass=2000;
		strcpy(qualification,"");
		strcpy(university,"");
	}
	Academic(int yr,char q[],char uni[])
	{
		year_pass=yr;
		strcpy(qualification,q);
		strcpy(university,uni);
	}
	void setYPass()
	{
		do
		{
			cout<<"Enter Year of Passing:\t";
			cin>>year_pass;
			if(year_pass<1900||year_pass>2021)
			{
				cout<<"Invalid Input\n";
			}
		}while(year_pass<1900||year_pass>2021);
	}
	int getYPass()
	{
		return year_pass;
	}
	void setQual()
	{
		cout<<"Enter Qualification:\t";
		cin.ignore();
		cin.getline(qualification,30);
	}
	char* getQual()
	{
		return qualification;
	}
	void setUni()
	{
		cout<<"Enter University:\t";
		//cin.ignore();
		cin.getline(university,30);
	}
	char* getUni()
	{
		return university;
	}
};

class BioData:public Personal,public Professional,public Academic
{
	public:
	BioData()
	{}
	BioData(char s[],long int mob,long int uid,int yr,unsigned int sal,char pst[],int year,char q[],char uni[]):
	Personal(s,mob,uid),Professional(yr,sal,pst),Academic(year,q,uni){};
	void setAll()
	{
		setName();
		setPhone();
		setUID();
		setExp();
		setSal();
		setPost();
		setYPass();
		setQual();
		setUni();
	}
	void getAll()
	{
		cout<<"Name is:\t"<<getName()<<endl;
		cout<<"Phone No. is:\t"<<getPhone()<<endl;
		cout<<"UID is:\t"<<getUID()<<endl;
		cout<<"Years of Experience:\t"<<getExp()<<endl;
		cout<<"Salary is:\t"<<getSal()<<endl;
		cout<<"Post is:\t"<<getPost()<<endl;
		cout<<"Year of Passing:\t"<<getYPass()<<endl;
		cout<<"Qualification is:\t"<<getQual()<<endl;
		cout<<"University of Passing:\t"<<getUni()<<endl;
		cout<<"\n\n";
	}
};

int main()
{
	int i,no;
	BioData* B[20];
	cout<<"How many records?\t";
	cin>>no;
	for(i=0;i<no;i++)
	{
		B[i]=new BioData();
		B[i]->setAll();
	}
	cout<<"\n\n";
	for(i=0;i<no;i++)
	{
		B[i]->getAll();
	}
	return 0;
}





