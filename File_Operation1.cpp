#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

int main()
{
	fstream file;
	file.open("abc.txt",ios::out);
	file.close();
	char buffer[200];
	char name[30];
	char r_no[10];
	char n[]="Name:";
	char r[]="Roll No:";
	file.open("abc.txt",ios::in|ios::out);
	if(file.is_open())
	{
		
		cout<<"Enter name:\t";
		cin>>name;
		cout<<"Enter Roll No.:\t";
		cin>>r_no;
		file.write(n,strlen(n));
		file.write(name,strlen(name));
		file.write("\n",1);
		file.write(r,strlen(r));
		file.write(r_no,strlen(r_no));
		file.seekg(ios::beg);
		while(!file.eof())
		{
			file.getline(buffer,200);
			cout<<buffer<<endl;
		}
		cout<<"\n";
		file.close();
		return 0;
	}
	else
		cout<<"File not opened"<<endl;
	return 0;
	
	
}
