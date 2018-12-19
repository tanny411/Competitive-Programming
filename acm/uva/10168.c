#include<stdio.h>
#include<math.h>
#define Max 10000003

char ara[Max];

void sieve()
{
    int i,j,sq=sqrt(Max),k;
    for(i=4;i<Max;i+=2) ara[i]=1;
    for(i=3;i<=sq;i+=2)
    {
        if(!ara[i])
        {
            for(j=i*i,k=i+i;j<Max;j+=k)
            {
                ara[j]=1;
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    ara[0]=ara[1]=1;
    sieve();
    long i,n;
    ara[0]=ara[1]=1;
    while(scanf("%ld",&n)==1)
    {
        if(n<8)
        {
            printf("Impossible.\n");
            continue;
        }

        if(n&1) {printf("2 3 "); n-=5;}
        else {printf("2 2 "); n-=4;}
        //printf("2 2 "); n-=4;
        if(!ara[n-2]) {printf("2 %ld\n",n-2); continue;}

        for(i=3;i<n;i+=2)
        {
            if(!ara[i] && !ara[n-i]) {printf("%ld %ld\n",i,n-i);break;}
        }
        //if(i==n) printf("Impossible.\n");
    }
    return 0;
}
