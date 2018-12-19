#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>

using namespace std;

string ara1[550],ara2[550];
int n1,n2,dp[550][550];

int lcs(int i,int j)
{
    if(i==n1 || j==n2) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(ara1[i]==ara2[j]) return dp[i][j]=1+lcs(i+1,j+1);
    int r1,r2;
    r1=lcs(i+1,j);
    r2=lcs(i,j+1);
    return dp[i][j]=r1>r2?r1:r2;
}

int main()
{
    char a[1002],b[1002],word[30];
    int no=1,i,j;
    while(gets(a) && gets(b))
    {
        printf("%2d. ",no++);
        if(strlen(a)==0 || strlen(b)==0)
        {
            printf("Blank!\n");
            continue;
        }
        n1=0;
        for(i=0;a[i];i++)
        {
            j=0;
            while(isalpha(a[i]) || isdigit(a[i]))
            {
                word[j++]=a[i++];
            }
            if(j)
            {
                word[j]=0;
                i--;
                ara1[n1++]=word;
            }
        }
        n2=0;
        for(i=0;b[i];i++)
        {
            j=0;
            while(isalpha(b[i]) || isdigit(b[i]))
            {
                word[j++]=b[i++];
            }
            if(j)
            {
                word[j]=0;
                i--;
                ara2[n2++]=word;
            }
        }
        memset(dp,-1,sizeof(dp));
        printf("Length of longest match: %d\n",lcs(0,0));
    }

    return 0;
}
