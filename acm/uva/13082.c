#include<stdio.h>

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,i;
    long n,ara[100000],value,j;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&ara[j]);
        }
        value=1;
        for(j=0;j<n;j++)
        {
            if(ara[j]==value)
            {
                value++;
            }

        }
        printf("Case %d: %ld\n",i,n-value+1);///karon value er maan 1 beshi hoye ase!
    }

    return 0;
}
