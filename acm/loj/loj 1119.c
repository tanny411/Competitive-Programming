#include<stdio.h>
#include<string.h>

int min(int a,int b)
{
    if(a<b) return a;
    else return b;
}

int dp[(1<<15)+2],ara[15][15];

int set(int n,int pos)
{
    return n=n|(1<<pos);
}
int check(int n,int pos)
{
    return n=n&(1<<pos);
}

int n;

int call(int mask)
{

    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int mn=1<<28,i,j,price;
    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            price=ara[i][i];
            for(j=0;j<n;j++)
            {
                if(j!=i && check(mask,j)!=0)
                {
                    price+=ara[i][j];
                }
            }
            int ret=price+call(set(mask,i));
            mn=min(mn,ret);
        }
    }
    return dp[mask]=mn;
}

int main( )
{
    int test,i,j,k;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                scanf("%d",&ara[j][k]);
            }
        }
        printf("Case %d: %d\n",i,call(0));
    }
    return 0;
}
