#include<bits/stdc++.h>
using namespace std;

int cost_mat[10][10];
int n=4;

int dp[16][4];
int TRAV_ALL=(1<<n)-1;

int g(int mask,int pos)
{
    if(mask==TRAV_ALL)
        return cost_mat[pos][0];
        
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
        
    int mincost=9999;
    for(int city=0;city<n;city++)
    {
        if((mask&(1<<city))==0)
        {
            int cost1=cost_mat[pos][city]+g(mask|(1<<city),city);
            mincost=min(mincost,cost1);
        }
    }
    dp[pos][mask]=mincost;
    return mincost;
}

int main()
{
     cout<<"Enter distances:\n\n";
    
    for(int i=0;i<n;i++)
    {
        cout<<"From vertex "<<i<<"\n";
        for(int j=0;j<n;j++)
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
    
    for(int i=0;i<16;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[i][j]=-1;
        }
    }
    
    cout<<"Smallest route from vertex 0 is: "<<g(1,0)<<"\n";
    
    for(int i=0;i<16;i++)
    {
        cout<<"\n";
        for(int j=0;j<4;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
    }
    
    return 0;
}