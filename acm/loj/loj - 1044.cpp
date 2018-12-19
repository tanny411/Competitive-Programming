#include<bits/stdc++.h>
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 100000007
#define ll long long
#define llu unsigned long long
using namespace std;

string str;
int len,dp[1010];

int pali(int i,int j)
{
    int x=(j-i)/2;
    for(int k=0;k<=x;k++,i++,j--)
    {
        if(str[i]!=str[j]) return 0;
    }
    return 1;
}

int rec(int start)
{
    if(start==len) return 0;
    if(dp[start]!=-1) return dp[start];
    dp[start]=INTMAX;
    for(int i=start;i<len;i++)
    {
        if(pali(start,i))
        {
            dp[start]=min(dp[start],rec(i+1)+1);
        }
    }
    return dp[start];
}

int main()
{
    int t,cas=1;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        cin>>str;
        len=str.length();
        for(int i=0;i<len;i++) dp[i]=-1;
        printf("Case %d: %d\n",cas++,rec(0));
        //cout<<rec(0)<<endl;
    }
    return 0;
}
