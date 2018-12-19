#include<stdio.h>
#include<string.h>

int set(int mask,int pos)
{
    return mask=mask|(1<<pos);
}
int check(int mask,int pos)
{
    return mask=mask&(1<<pos);
}
int reset(int mask,int pos)
{
    return mask=mask&(~(1<<pos));
}
int dp[1<<12+2];

int call(int mask)
{
    if(dp[mask]!=-1) {return dp[mask];}
    int i,x,r1,r2,mn,min=1<<30,flag=0;
    for(i=0;i<12;i++)
    {
        if(check(mask,i)){
        r1=r2=1<<30;
        if(i<10 && check(mask,i+1) && !check(mask,i+2))
        {
            x=mask;
            x=reset(x,i);
            x=reset(x,i+1);
            x=set(x,i+2);
            r1=call(x);
            flag=1;
        }
        if(i>1 && check(mask,i-1) && !check(mask,i-2))
        {

            x=mask;
            x=reset(x,i);
            x=reset(x,i-1);
            x=set(x,i-2);
            r2=call(x);
            flag=1;
        }
        mn=r1<r2?r1:r2;
        min=min<mn?min:mn;
        }
    }
    if(!flag)
    {
        int sum=0;
        for(i=0;i<12;i++)
        {
            if(check(mask,i)) sum++;
        }
        return sum;
    }
    return dp[mask]=min;
}

int main()
{
    int t,i,mask;
    char ara[15];
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        gets(ara);
        memset(dp,-1,sizeof(dp));
        mask=0;
        for(i=0;i<12;i++)
        {
            if(ara[i]=='o') mask=set(mask,i);
        }
        printf("%d\n",call(mask));
    }
    return 0;
}
