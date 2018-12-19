#include<stdio.h>
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n>10)
        {
            printf("%d %d\n",10,n-10);
        }
        else printf("%d %d\n",0,n);
    }
    return 0;
}
