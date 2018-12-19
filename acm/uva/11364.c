#include<cstdio>

int main()
{
    int t,n,ara[100],i,max,min;
    scanf("%d",&t);
    while(t--)
    {
        max=-1000;
        min=1000;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
            if(ara[i]>max) max=ara[i];
            if(ara[i]<min) min=ara[i];
        }
        printf("%d\n",(max-min)*2);
    }
    return 0;
}
