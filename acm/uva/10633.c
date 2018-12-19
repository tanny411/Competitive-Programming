#include<stdio.h>

int main()
{
    unsigned long long n,x;
    while(scanf("%lld",&n)==1 && n)
    {
        x=(n*10)/9;
        if(n%9==0)
        {
            printf("%lld %lld\n",x-1,x);
        }
        else printf("%lld\n",x);
    }
    return 0;
}
