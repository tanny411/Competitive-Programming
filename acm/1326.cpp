#include<bits/stdc++.h>

#define pb push_back
#define pii pair<int,int>
#define mod 10056

#define LL long long

#define fs first
#define sc second

using namespace std;
int ncr[1002][1002];
int dp[1002];
int main()
{
    ios_base::sync_with_stdio(false);

    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1) ncr[i][j]=i;
            else ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mod;
        }
    }
    dp[0]=1;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i]=(dp[i]+ncr[i][j]*dp[i-j])%mod;
        }
    }
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<"Case "<<test++<<": "<<dp[n]<<endl;
    }
    return 0;
}

