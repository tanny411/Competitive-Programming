#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define MOD 1000000007

#define ll long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
///----------DP (n^2) to find number of all possible increasing subsequence-------///
int n;
int ara[100002];
ll dp[100002];
ll all_is(int pos)
{
    if(pos>=n) return 0;
    if(dp[pos]!=-1) return dp[pos];
    ll ans=1;
    for(int i=pos+1;i<n;i++)
    {
        if(ara[i]>ara[pos]) ans=(ans+all_is(i))%MOD;
    }
    return dp[pos]=ans;
}

int main()
{
    int t;
    int cas=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&ara[i]);
            dp[i]=-1;
        }
        ///---------DP-----------///
        ll ans=0;
        for(int i=0;i<n;i++) ans=(ans+all_is(i))%MOD;
        printf("Case %d: %lld\n",cas++,ans);
        ///--------table (n^2) to find no. of all subs-----//
        ll table [100002];
        ///table[i] is no. of increasing sequences ending at i
        for(int i=0;i<n;i++) table[i]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(ara[j]<ara[i]) table[i]+=table[j];
            }
        }
        ans=0;
        for(int i=0;i<n;i++) ans+=table[i];
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}

