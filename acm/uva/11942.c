#include<stdio.h>
int main()
{
   int n,i,ara[10],grt,less,skip;
   scanf("%d",&n);
   printf("Lumberjacks:\n");
    while(n--)
    {
        grt=0;
        less=0;
        skip=0;
        scanf("%d %d",&ara[0],&ara[1]);
        if(ara[1]>ara[0]) grt=1;
        else less=1;
        for(i=2;i<10;i++)
        {
            scanf("%d",&ara[i]);
            if(skip) continue;
            if(less && ara[i]>ara[i-1]) skip=1;
            if(grt && ara[i]<ara[i-1]) skip=1;

        }
        if(skip) printf("Unordered\n");
        else printf("Ordered\n");


    }

    return 0;
}
