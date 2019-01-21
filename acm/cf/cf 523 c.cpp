#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define mod 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<LL>dp(1000000);
    for(int i=n-1;i>=0;i--)
    {
        int sq=sqrt(v[i]);
        for(int j=1;j<=sq && j<=n;j++)
        {
            if(v[i]%j==0)
            {
                dp[j]=(dp[j]+1+dp[j+1])%mod;
                int x=v[i]/j;
                if(x<=n && x!=j)
                {
                    dp[x]=(dp[x]+1+dp[x+1])%mod;
                }
            }
        }
    }
    cout<<dp[1]<<endl;
    return 0;
}

