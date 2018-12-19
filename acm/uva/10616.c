#include<stdio.h>
#include<string.h>
int n,ara[202],D,m,dp[201][11][21];

int sub(int x, int y)
{
 int tmp = (x-y)%D;
 if (tmp>=0) return(tmp);
 return(tmp+D);
}

int knap(int pos,int taken,int sum)
{
    if(taken==m)
    {
        if(sum%D==0) return 1;
        else return 0;
    }
    if(pos==n || taken>m) return 0;
    if(dp[pos][taken][sum]!=-1) return dp[pos][taken][sum];
    int r1,r2;
    r1=knap(pos+1,taken+1,sub(sum,ara[pos]) );
    r2=knap(pos+1,taken,sum);
    return dp[pos][taken][sum]=r1+r2;
}


int main()
{
    int q,i,set=1,query;
    while(scanf("%d %d",&n,&q)==2)
    {
        if(n==0 && q==0) break;
        printf("SET %d:\n",set++);
        for(i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
        }
        query=1;
        for(i=0;i<q;i++)
        {
            memset(dp,-1,sizeof(dp));
            scanf("%d %d",&D,&m);
            printf("QUERY %d: %d\n",query++,knap(0,0,0));
        }
    }
    return 0;
}
