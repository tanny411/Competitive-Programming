#include<iostream>
#include<string.h>
//#include<stdio.h>
#include<cstdio>
#include<sstream>
#include<string>
using namespace std;
int n,ara[21],sum,dp[21][201];

int knap(int pos,int left)
{
    if(left==0) return 1;
    if(pos==n) return 0;
    if(dp[pos][left]!=-1) return dp[pos][left];
    int r1,r2=0;
    if(left-ara[pos]>=0) r2=knap(pos+1,left-ara[pos]);
    r1=knap(pos+1,left);
    dp[pos][left]=r1|r2;
    return dp[pos][left];
}

int main()
{
    int test,i,x;
    char str[1000];
    stringstream ss;
    scanf("%d",&test);
    while(test--)
    {
        scanf(" %[^\n]", str);
        ss << str;
        n=sum=0;
        while(ss >> ara[n])
        {
            sum+=ara[n];
            n++;
        }
        ss.clear();
        ss.str("");
        memset(dp,-1,sizeof(dp));
        if(sum&1)
        {
            printf("NO\n");
        }
        else
        {

            x=knap(0,sum/2);
            //printf("abc %d ara[0]=%d abc\n",x,ara[0]);
            if(x) printf("YES\n");
            else printf("NO\n");
        }
        //printf("abc %d abc\n",sum);
    }
    return 0;
}
