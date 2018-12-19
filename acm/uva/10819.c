#include<stdio.h>
#include<string.h>

int cap,n,weight[102],cost[102],dp[102][10500];

int knap(int i,int w)
{
    if(w>cap && cap<1800) return -20000;
    if(w>(cap+200)) return -20000;
    if(i==n)
    {
        if(w>cap && w<=2000) return -20000;
        else return 0;
    }
    if(dp[i][w]!=-1) return dp[i][w];
    int r1,r2;
    r1=cost[i]+knap(i+1,w+weight[i]);
    r2=knap(i+1,w);
    dp[i][w]=r1>r2?r1:r2;
    return dp[i][w];
}

int main()
{
    int i;
    while(scanf("%d %d",&cap,&n)==2)
    {
        memset(dp,-1,sizeof(dp));
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&weight[i],&cost[i]);
        }
        printf("%d\n",knap(0,0));
    }
    return 0;
}
