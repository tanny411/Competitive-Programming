#include<stdio.h>
#include<string.h>

int ara1[101],ara2[101],dp[101][101],n1,n2;

int lcs(int i,int j)
{
    if(i==n1 || j==n2) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ara1[i]==ara2[j]) {dp[i][j]=1+lcs(i+1,j+1);
    return dp[i][j];}
    int r1,r2;
    r1=lcs(i+1,j);
    r2=lcs(i,j+1);
    dp[i][j]=r1>r2?r1:r2;
    return dp[i][j];
}

int main()
{
    int i=1,j,k;
    while(scanf("%d %d",&n1,&n2)==2)
    {
        if(n1==0 && n2==0) break;
        for(j=0;j<n1;j++) scanf("%d",&ara1[j]);
        for(k=0;k<n2;k++) scanf("%d",&ara2[k]);

    memset(dp,-1,sizeof(dp));
    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",i++,lcs(0,0));
    }
    return 0;
}
