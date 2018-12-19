#include<stdio.h>
#include<math.h>

long long fibo[81];

int main()
{
    int i,n;
    fibo[1]=1;
    fibo[2]=2;
    for(i=3;i<82;i++)
    {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    while(scanf("%d",&n)==1 && n!=0)
    {
        printf("%lld\n",fibo[n]);
    }
    return 0;
}
