#include<stdio.h>
#include<string.h>

char ara1[1002],ara2[1002];
int dp[1002][1002];

int lcs(int i,int j)
{
    if(ara1[i]=='\0' || ara2[j]=='\0') return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ara1[i]==ara2[j])
    {
         dp[i][j]=1+lcs(i+1,j+1);
        return dp[i][j];
    }
    int r1,r2;
    r1=lcs(i+1,j);
    r2=lcs(i,j+1);
    dp[i][j]=r1>r2?r1:r2;
    return dp[i][j];
}

int main()
{

    while(gets(ara1))
    {
        gets(ara2);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",lcs(0,0));
    }
    return 0;
}
