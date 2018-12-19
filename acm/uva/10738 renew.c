#include<stdio.h>
#include<math.h>
int pt=0,prime[1003],flag[1005],M[1000002],mu[1000002];

void sieve()
{
    int i,j,sq=32;
    prime[pt++]=2;
    for(i=4;i<1003;i+=2) flag[i]=1;
    for(i=3;i<=sq;i+=2)
    {
        if(!flag[i])
        {
            prime[pt++]=i;
            for(j=i*i;j<1003;j+=i+i)
            {
                flag[j]=1;
            }
        }
    }
    for(;i<1003;i+=2)
    {
        if(!flag[i]) prime[pt++]=i;
    }
}

void merten()
{
    int i,j,n,count;
    mu[1]=M[1]=1;
    for(i=2; i<1000001; i++)
    {
        n=i;
        count=0;
        for( j=0;j<pt && prime[j]*prime[j]<=n  ;j++ )
        {
            if(n%prime[j]==0)
            {
                n/=prime[j];
                count++;
                if( n%prime[j]==0 )
                {
                    count=-100;
                    break;
                }
            }
        }
        if(n!=1) count++;///cuz i checked primes jus within 1000, the number can just 1 more prime greater than its root;
        if(count<0) mu[i]=0;
        else if(count&1) mu[i]=-1;
        else mu[i]=1;
        M[i]=mu[i]+M[i-1];
    }
}

int main()
{
    sieve();
    merten();
    int n;
    //printf("%d\n",pt);///pt=168
    while(scanf("%d",&n)==1 && n)
    {
        printf("%8d%8d%8d\n",n,mu[n],M[n]);
    }

    return 0;
}
