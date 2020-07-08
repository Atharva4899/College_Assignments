#include<bits/stdc++.h>
using namespace std;

int TRAV_ALL;       //condition to check if all nodes are visited
int** cost_mat;     //store costs to each city
int** dp;           //memoization table
int size,s=0;       //size=total cities, s=start vertex

void init_dp()      //initialize memoization table [2^size][size]
{
    int n=pow(2,size);
    dp=new int*[n+1];
    
    for(int i=0;i<n+1;++i)
    {
        dp[i]=new int[size+1];
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<size;j++)
        {
            dp[i][j]=-1;
        }
    }
} 

void disp_mat()
{
    cout<<"\nThe cost adjacency matrix is:\n";
    for(int i=0;i<size;i++)
    {
        cout<<"\n";
        for(int j=0;j<size;j++)
        {
            cout<<cost_mat[i][j]<<"\t";
        }
    }
    cout<<"\n";
    
}

void init()
{
    //Get total cities
    do
    {
        cout<<"Enter total cities:\t";
        cin>>size;
        
        if(size<=0)
            cout<<"Invalid Input!\n\n";
    }while(size<=0);
    
    
    //dynamically allocate memnory
    
    cost_mat=new int*[size];
    for(int i=0;i<size;i++)
    {
        cost_mat[i]=new int[size];
    }
    
    TRAV_ALL=(1<<size)-1;
    
    //Take distances to each city
    
    cout<<"Enter distances:\n\n";
    
    for(int i=0;i<size;i++)
    {
        cout<<"From vertex "<<i<<"\n";
        for(int j=0;j<size;j++)
        {
            if(i==j)
                cost_mat[i][j]=0;
            else
            {
                cout<<"To vertex "<<j<<": ";
                cin>>cost_mat[i][j];
            }
        }
        cout<<"\n";
    }
    
    disp_mat();  
    
    //Get start vertex
    
     do
    {
        cout<<"\nEnter start vertex:\t";
        cin>>s;
        
        if(s>=size)
            cout<<"Invalid Input\n";
        
    }while(s>=size);
    
    init_dp();                      //initialize memoization table
                       //display cost matrix
}

int g(int mask,int pos)
{
    if(mask==TRAV_ALL)
        return cost_mat[pos][s];    //all cities visited, get distance to initial city
        
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];       //overlapping subproblem
        
    int mincost=9999;
    for(int city=0;city<size;city++)
    {
        if((mask&(1<<city))==0)     //if city not visited, explore subbranch
        {
            int cost1=cost_mat[pos][city]+g(mask|(1<<city),city);
            mincost=min(mincost,cost1);
        }
    }
    dp[pos][mask]=mincost;          //store value in memoization table
    return mincost;
}

int main()
{   
    init();             //create cost matrox and memoization table
    int mask=(1<<s);    //make start vertex as visited
    
    cout<<"\nShortest route from vertex "<<s<<" is: "<<g(mask,s)<<"\n";
    return 0;
}