#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll dp[26][155];
ll rec(int n,int x)
{
    if(n==0) return x==0;
    ll &ret=dp[n][x];
    if(ret!=-1) return ret;
    //cout<<n<<" "<<x<<" "<<ret<<endl;
    ret=0;
    for(int i=1;i<=6;i++) ret+=rec(n-1,max(0,x-i));
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        int n,x;
        cin>>n>>x;
        ll ans=rec(n,x);
        ll p=1;
        for(int i=0;i<n;i++) p*=6ll;
        if(ans%p==0) cout<<"Case "<<test++<<": "<<ans/p<<endl;
        else{
            ll g=__gcd(ans,p);
            cout<<"Case "<<test++<<": "<<ans/g<<"/"<<p/g<<endl;
        }
//        for(int i=0;i<=n;i++)
//        {
//            for(int j=0;j<=x;j++) cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
    }
    return 0;
}
