#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

string ara1[101],ara2[101];
int n1,n2,dp[101][101],flag;

int lcs(int i,int j)
{
    if(i==n1 || j==n2) return 0;
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

void print(int i,int j)
{
    if(i==n1 || j==n2)
    {
        return;
    }
    if(ara1[i]==ara2[j])
    {
        if(flag)cout<<" ";
        flag=1;
        cout<<ara2[j] ;
        print(i+1,j+1);
    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) print(i+1,j);
        else print(i,j+1);
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    //char a[31];
    while(cin>>ara1[0])
    {
        //ara1[0]=a;
        memset(dp,-1,sizeof(dp));
        n1=1,n2=0;
        while(cin>>ara1[n1] && ara1[n1]!="#")
        {
            n1++;
        }
        while(cin>>ara2[n2] && ara2[n2]!="#")
        {
            n2++;
        }
        //cout<<lcs(0,0)<<endl;
        lcs(0,0);
        flag=0;
        print(0,0);
        cout<<endl;
    }
    return 0;
}
