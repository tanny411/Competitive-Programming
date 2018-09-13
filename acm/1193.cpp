#include<bits/stdc++.h>
#define INTMAX 1<<30
#define mod 100000007
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,k,s;
        cin>>n>>k>>s;
        ll dp[2][s+1],sum[2][s+1];

        dp[0][0]=dp[1][0]=sum[0][0]=sum[1][0]=0;
        int in=1;
        for(int i=0;i<n;i++){
            in=1-in;
            for(int j=1;j<=s;j++)
            {
                if(i==0){
                    if(j<=k) dp[in][j]=j;
                    else dp[in][j]=0;
                }
                else{
                    dp[in][j]=((dp[in][j-1]+sum[1-in][j-1]-(j-k-1<0?0:sum[1-in][j-k-1])-(j-k-1<0?0:dp[1-in][j-k-1]*k))%mod + mod)%mod;
                }
                sum[in][j]=((sum[in][j-1]+dp[in][j])%mod + mod)%mod;
            }
        }
        cout<<"Case "<<test++<<": "<<dp[in][s]<<endl;
    }
}
/**
2 5 7 == 44

*/
