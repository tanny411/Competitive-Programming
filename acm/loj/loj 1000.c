#include<stdio.h>

int main()
{
    int t,a,b,i=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&a,&b);
        printf("Case %d: %d\n",i++,a+b);
    }
    return 0;
}
