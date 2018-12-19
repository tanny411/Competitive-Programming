#include<stdio.h>
#include<string.h>
#define max(a,b) ( (a>b)?a:b )
#define lld long long

int coin[23],n;
lld dp[22][10000];

void cube ()
{
    int i;
    for(i=1;i<22;i++)
    {
        coin[i]=i*i*i;
    }
}



lld go(int i,int amount)
{
    if(amount==0) return 1;
    if(i==22) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];
    lld a1,a2;
    a1=go(i+1,amount);
    if(amount-coin[i]>=0)  a2=go(i,amount-coin[i]);
    else a2=0;
    dp[i][amount]=a1+a2;
    return dp[i][amount];
}

int main()
{
    cube();
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",go(1,n));
    }
    return 0;
}
