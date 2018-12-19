#include<stdio.h>
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    long long n,A,B,X,Y;
    scanf("%lld",&n);
    while(n--)
    {
        scanf("%lld %lld",&A,&B);
        X=(A+B);
        Y=(A-B);
        if(Y>-1 && X%2==0 && Y%2==0)
        {

            printf("%lld %lld\n",X/2,Y/2);
        }
        else printf("impossible\n");
    }
    return 0;
}
