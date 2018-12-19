#include<stdio.h>

int main()
{
    long n,k,x,test,i,sum,reduce;
    scanf("%ld",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%ld %ld %ld",&n,&k,&x);
        sum=n*(n+1)/2;
        reduce=((x+k-1)*(x+k)/2)-((x-1)*x/2);
        printf("Case %ld: %ld\n",i,sum-reduce);
    }
    return 0;
}
