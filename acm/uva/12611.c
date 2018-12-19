#include<stdio.h>

int main()
{
    int test,i,r,l,w,l1,l2;
    scanf("%d",&test);
    for(i=1;i<=test;i++)
    {
        scanf("%d",&r);
        w=(r*3)/2;
        l1=-(45*r*5)/100;
        l2=(55*5*r)/100;
        printf("Case %d:\n%d %d\n%d %d\n%d %d\n%d %d\n",i, l1,w,l2,w,l2,-w,l1,-w );
    }
    return 0;
}
