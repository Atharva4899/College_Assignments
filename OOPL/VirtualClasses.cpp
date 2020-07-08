#include<iostream>
#include<string.h>
using namespace std;

class Shape
{
        double x,y;
        public:
                virtual  void setData()=0;
                virtual double compute_area()=0;
};

class Triangle:public Shape
{
        double base,height,area;
        public:
                void setData()
                {
                        int flag;
                        do
                        {
                                flag=0;
                                cout<<"Enter Base and Height of the triangle:\t";
                                cin>>base>>height;
                                if(base<=0||height<=0)
                                {
                                        cout<<"\n\tInvalid Dimensions!\n"<<endl;
                                        flag=1;
                                }
                        }while(flag==1);
                }
                double compute_area()
                {
                      area = 0.5*base*height;
                      return area;
                }
};

class Rectangle:public Shape
{
        double length,breadth,area;
        public:
                void setData()
                {
                        
                        int flag;
                        do
                        {
                                flag=0;
                                cout<<"Enter Length and Breadth of the rectangle:\t";
                                cin>>length>>breadth;
                                if(length<=0||breadth<=0)
                                {
                                        cout<<"\n\tInvalid Dimensions!\n"<<endl;
                                        flag=1;
                                }
                        }while(flag==1);
                 }
                 double compute_area()
                 {
                        area=length*breadth;
                        return area;
                 }
                
};

int main()
{
        Shape *s=NULL;
        Triangle t;
        Rectangle r;
        int cont,choice;
        do
        {
                cout<<"MENU:\n\t1.Area of Triangle\n\t2.Area of Rectangle\n\t3.Exit\n\t";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                s=&t;
                                s->setData();
                                cout<<"\n\tArea of Triangle is:\t"<<s->compute_area()<<endl;
                                cout<<"\n---Press 1 to go to Menu, else press any key---\t";
                                cin>>cont;
                                break;
                        case 2:
                                s=&r;
                                s->setData();
                                cout<<"\n\tArea of Rectangle is:\t"<<s->compute_area()<<endl;
                                cout<<"\n---Press 1 to go to Menu, else press any key---\t";
                                cin>>cont;
                                break;
                       case 3:
                                cont=0;
                                cout<<"\n\t---Program Closed---\n";
                                break;
                       default:
                                cout<<"\n\t---Invalid Choice!---\n"<<endl;
                                cont=1;
                                break;                         
                }
        }while(cont==1);
        return 0;
}
