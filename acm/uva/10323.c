#include<stdio.h>
int main()
{
    int n;
    long long ara[14];
    ara[1]=1;
    for(n=2;n<14;n++)
    {
        ara[n]=n*ara[n-1];
    }

    while(scanf("%d",&n)==1)
    {
        if(n<0)
        {
            n*=-1;
            if(n&1) printf("Overflow!\n");
            else printf("Underflow!\n");
        }
        else if(n<8) printf("Underflow!\n");
        else if(n>13) printf("Overflow!\n");
        else printf("%lld\n",ara[n]);
    }
    return 0;
}
