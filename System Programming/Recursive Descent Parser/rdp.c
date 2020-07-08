/*
    Grammar:
    S -> cAd
    A -> ab | bB
    B -> a | b
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char la;

int match(char t)
{
    if(la==t)
    {
        la=getchar();
        return 1;
    }
    else
    {
        return 0;
    }
}

int B()
{
    int chk=0;
    if(la=='a')
        chk=match('a');
    if(!chk)
        if(la=='b')
            chk=match('b');
    return chk;
}

int A()
{
    int chk=0;
    if(la=='a')
    {
        chk=match('a');
        if(chk)
            if(la=='b')
            {
                chk=match('b');
            }
    }
    else if(la=='b')
    {
        chk=match('b');
        if(chk)
            chk=B();
    }
    return chk;
}

int S()
{
    int chk=0;
    if(la=='c')
    {
        chk=match('c');
        if(chk)
            chk=A();
        if(chk)
            chk=match('d');
    }
   return chk;
}

int main()
{
    printf("The grammar is:\nS -> cAd\nA -> ab | bB\nB -> a | b\nEnter string:\n");
    la=getchar();
    int chk;
    chk=S();
    if(chk==1)
        printf("Parsing Successful\n");
    else
        printf("Invalid\n");
}