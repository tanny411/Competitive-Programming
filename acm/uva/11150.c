#include<stdio.h>


int main()
{
    int n,mod,total;
    while(scanf("%d",&n)==1)
    {
        total=n;
        while(n>=3)
        {
            mod=n%3;
            n/=3;
            total+=n;
            n+=mod;
        }
        if(n==2) printf("%d\n",total+1);
        else printf("%d\n",total);
    }
    return 0;
}
