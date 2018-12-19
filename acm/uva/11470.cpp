#include<bits/stdc++.h>

int main()
{
    int n,i,j,k,ara[12][12],test=1,sum,x;
    while(scanf("%d",&n)==1 && n)
    {
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&ara[i][j]);
        }
    }
    printf("Case %d:",test++);
    for(x=0;x<n;x++,n--)
    {
        if(x==n-1)
        {
            printf(" %d",ara[x][x]);
            continue;
        }
        sum=0;
        for(i=x;i<n;i++)
        {
            sum+=ara[x][i]+ara[n-1][i];
        }
        for(i=x+1;i<n-1;i++)
        {

            sum+=ara[i][x]+ara[i][n-1];
        }
        printf(" %d",sum);
    }
    printf("\n");
    }
    return 0;
}
