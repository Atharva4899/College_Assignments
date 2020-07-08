#include<iostream>
using namespace std;
#define DivideByZero 10

class Division
{
        double x,y,result;
        public:
                void setData()
                {
                        cout<<"Enter dividend and divisor:\t";
                        cin>>x>>y;
                }
                void divide()
                {
                        if(y==0)
                        {
                                throw DivideByZero;
                        }
                        result = x/y;
                }
                void showRes()
                {
                        cout<<"\n\tResult is:\t"<<result<<endl;
                }
};

int main()
{
        Division d;
        int cont;
        do
        {
                d.setData();
                try
                {
                        d.divide();
                        d.showRes();
                }
                catch(int i)
                {
                        if(i==DivideByZero)
                        {
                                cerr<<"\n\t---Exception: Cannot divide by zero---\n";
                        }
                }
                 cout<<"\n---Press 1 to go to enter new values, else press any key---\t";
                 cin>>cont;                
        }while(cont==1);
        cout<<"\n\t---Program Closed---\n";
}
