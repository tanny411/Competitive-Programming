#include<bits/stdc++.h>
using namespace std;

int prime[101],n;

void sieve()
{
    int sq=10,max=100,i,j;
    prime[0]=prime[1]=1;
    for(i=4;i<max;i+=2) prime[i]=1;
    for(i=3;i<=sq;i+=2)
    {
        if(!prime[i])
        {
            for(j=i*i;j<max;j+=i) prime[j]=1;
        }
    }
}

int flag[20],ara[20];

void Do(int in)
{
    if(in==n)
    {
        if(prime[1+ara[n-1]]) return;
        printf("%d",ara[0]);
        for(int i=1;i<n;i++) printf(" %d",ara[i]);
        printf("\n");
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(!flag[i])
        {
            if(!prime[i+ara[in-1]])
            {
                ara[in]=i;
                flag[i]=1;
                Do(in+1);
                flag[i]=0;
            }
        }
    }
}

int main()
{
    sieve();
    int t=1;
    while(scanf("%d",&n)==1)
    {
        if(t!=1) printf("\n");
        printf("Case %d:\n",t++);
        ara[0]=1;
        memset(flag,0,sizeof(flag));
       // flag[1]=1;
        Do(1);
        //printf("Done\n");
    }
    return 0;
}
