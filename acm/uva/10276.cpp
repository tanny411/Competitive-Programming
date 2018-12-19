#include<stdio.h>
#include<math.h>
#include<string.h>

int ara[55],pos[55],n,MAX,dp[55];

int is_square(double x)
{
    double sq=sqrt(x);
    int s=sq;
    if(sq-s == 0) return 1;
    return 0;
}

int game(int x)
{
    int flag=1;
    for(int i=0;i<n;i++)
    {
        if(pos[i]==0)
        {
            dp[i]=x-1;
            flag=0;
            pos[i]++;
            ara[i]=x;
            game(x+1);
        }
        else if (is_square(x+ara[i]))
        {
            flag=0;
            pos[i]++;
            ara[i]=x;
            game(x+1);
        }
    }
    if(flag)
    {
        if(x-1>MAX) MAX=x-1;
    }
}

void lets_dp()
{
    n=50;
    game(1);
    dp[50]=MAX;
}

int main()
{
    lets_dp();
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
