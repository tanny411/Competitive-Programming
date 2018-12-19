#include<stdio.h>
#include<string.h>

char ara1[101],ara2[101],dp[101][101];

int lcs(int i,int j)
{
    if(ara1[i]==0 || ara2[j]==0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ara1[i]==ara2[j]) return dp[i][j]=1+lcs(i+1,j+1);
    int r1,r2;
    r1=lcs(i,j+1);
    r2=lcs(i+1,j);
    return dp[i][j]=r1>r2?r1:r2;
}

int main()
{
    int no=1;
    while(gets(ara1) && ara1[0]!='#')
    {
        gets(ara2);
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: you can visit at most %d cities.\n",no++,lcs(0,0));
    }
    return 0;
}
