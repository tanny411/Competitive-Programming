#include<stdio.h>
#define max 1000000

int dp[max+1],ara[max];

void sieve()
{
    int i,j,r=1000;
    ara[1]=0;
    ara[2]=0;

    for(i=4;i<=max;i+=2) ara[i]=1;

    for(i=3;i<=r;i+=2)
    {
        if(!ara[i])
        {
            for(j=i*i;j<=max;j+=i+i)
            {
                ara[j]=1;
            }
        }
    }
}

void oka()
{
    int i,count=2,p,m;
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    dp[3]=2;

    for(i=5;i<=max;i+=2)
    {
        dp[i-1]=count;
        if(!ara[i])
        {
        p=0;
        m=i;
        while(m>0)
    {
        p+=m%10;
        m/=10;
    }
        if(!ara[p])
        count++;
        }
        dp[i]=count;
    }
    dp[max]=count;
}

int main()
{
    sieve();
    oka();
    int t,a,b,i,count;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("%d\n",dp[b]-dp[a-1]);
    }
    return 0;
}
