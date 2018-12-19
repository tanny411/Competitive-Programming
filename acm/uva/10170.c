#include<stdio.h>
int main()
{
    long long p,d,day;
    while(scanf("%lld %lld",&p,&d)==2)
    {
        day=p;
        while(day<d)
        {
            p++;
            day+=p;
        }
        printf("%lld\n",p);
    }
    return 0;
}
