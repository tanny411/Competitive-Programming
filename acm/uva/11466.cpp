#include<stdio.h>
#include<math.h>
#define maxi 10000000
#define sq 3163
char flag[maxi+5];
int prime[700000],pt=0;

void sieve()
{
    int i,j,k;
    prime[pt++]=2;
    for(i=4;i<maxi;i+=2) flag[i]=1;
    for(i=3;i<=sq;i+=2)
    {
        if(!flag[i])
        {
            prime[pt++]=i;
            for(j=i*i,k=i+i;j<maxi;j+=k)
            {
                flag[j]=1;
            }
        }
    }
    for( ; i<maxi ; i+=2)
    {
        if (!flag[i]) prime[pt++]=i;
    }
}

int main()
{
    sieve();
    long long x,i,last,counti;
    while(scanf("%lld",&x)==1 && x)
    {
        if(x<0) x*=-1;
        if(x<maxi)
        {
            if(!flag[x]) { printf("-1\n"); continue; }
        }
        counti=0;
        for(i=0 ; i<pt && prime[i]*prime[i]<=x ;i++)
        {
            if( x%prime[i]==0 ){
            counti++;
            while(x%prime[i]==0)
            {
                x/=prime[i];
            }
            last=prime[i];
            }
        }
        if (counti==0)  printf("-1\n");
        else if(counti==1 && x==1) printf("-1\n");
        else  if(x!=1) printf("%lld\n",x);
        else printf("%lld\n",last);
    }
    return 0;
}
