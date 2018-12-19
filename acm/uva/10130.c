#include<stdio.h>
#include<string.h>
///0-1 knapsack

int cost[1002],weight[1002],dp[1002][35],n,cap;

int max(int a,int b)
{
    return (a>b)?a:b ;
}

int func(int i,int w)
{
    if(i==n) return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    int profit1,profit2;
    profit1=func(i+1,w);
    if(w+weight[i]<=cap) profit2=cost[i]+func(i+1,w+weight[i]);
    else profit2=0;
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int test,i,people,total;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&cost[i],&weight[i]);
        }
        total=0;
        scanf("%d",&people);
        while(people--)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d",&cap);
            total+=func(0,0);
        }
        printf("%d\n",total);
    }
    return 0;
}
