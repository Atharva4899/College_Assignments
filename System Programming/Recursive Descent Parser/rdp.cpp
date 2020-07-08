#include<bits/stdc++.h>
using namespace std;

class rdp
{
    string str; //input string
    char la;    //look ahead
    int lc;     //index of current character
    
    public:
    rdp();
    void S();
    void A();
    void B();
    void match(char t);
};

rdp::rdp()
{
    cout<<"The grammar is:\n\nS -> cAd\nA -> ab | bB\nB -> a | b\n\nEnter string:\n";
    cin>>str;
    la=str[0];
    str.append("$");
    lc=0;
}

void rdp::match(char t)
{
    
    if(la==t)
    {
        lc++;
        la=str[lc];
    }
    else
    {
        throw la;
    }
}

void rdp::B()
{
    if(la=='a')
    {
        cout<<"\nB -> a";
        match('a');
    }
    else if(la=='b')
    {
        cout<<"\nB -> b";
        match('b');
    } 
    else
        throw la;
}

void rdp::A()
{
    if(la=='a')
    {
        cout<<"\nA -> ab";
        match('a');
        match('b');
    }
    else if(la=='b')
    {
        cout<<"\nA -> bB";
        match('b');
        B();
    }
    else
        throw la;
}

void rdp::S()
{
    if(la=='c')
    {
        cout<<"\nS -> cAd";
        match('c');
        A();
        match('d');
        match('$');
    }
    else
        throw la;
}

int main()
{
    rdp r;                                  //get input from user and initialize variables. string is ended by '$' automatically
    try
    {
        r.S();                              //initial state
        cout<<"\n\nParsing Successful\n";
    }
    catch(char c)                           //parsing unsuccessful
    {
        if(c!='\0' && c!='$')
            cout<<"\n\nInvalid character encountered: "<<c<<"\nParsing unsuccesful\n\n";
        else
            cout<<"\n\nUnexpected Termination of string\nParsing unsuccesful\n\n";
    }
    return 0;
}