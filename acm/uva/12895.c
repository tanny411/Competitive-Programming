#include<stdio.h>
#include<math.h>
///pow function doesnt work properly
///but works in ideone
int main()
{
    long long n,p,m,test,ara[100],i,j,x;
    scanf("%lld",&test);
    while(test--)
    {
        scanf("%lld",&n);
        p=n;i=0;
        while(p>0)
        {
            ara[i]=p%10;
            p/=10;
            i++;
        }
        p=i;
        m=0;
        for(i=0;i<p;i++)
        {
           m+=(long long)pow(ara[i],p);
        }

        if(m==n) printf("Armstrong\n");
        else printf("Not Armstrong\n");
    }
    return 0;
}
