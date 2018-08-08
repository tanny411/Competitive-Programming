/*
ID: aysha.k1
LANG: C++11
TASK: numtri
*/
#include<bits/stdc++.h>
using namespace std;
int n,ara[1002][1002],mx=-1<<30;
int dp[1002][1002];
int rec(int x,int y)
{
    if(x==n) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    return dp[x][y]=max(rec(x+1,y),rec(x+1,y+1))+ara[x][y];
}

int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cin>>ara[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
    return 0;
}
