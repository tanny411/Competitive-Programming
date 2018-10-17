#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
ll bg(ll base, ll power,ll mod){
    if(power==1) return base;
    if(power==0) return 1ll;
    ll x=(bg(base,power/2,mod));
    x=(x*x)%mod;
    if(power&1) x=(x*base)%mod;
    return x;
}
ll inv(ll x)
{
    return bg(x,MOD-2,MOD);
}
int main()
{
    ios_base::sync_with_stdio(false);
    ll f[100005];
    f[0]=f[1]=1ll;
    for(ll i=2;i<100001;i++)
    {
        f[i]=(i*f[i-1])%MOD;
    }
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int,ll>mp;
        for(int i=0;i<n;i++) { int x; cin>>x; mp[x]++; }
        ll ans=1;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ll x=it->sc;
            if(x&1){
                auto next=it;
                next++;
                ans=(ans*x*(next->sc))%MOD;
                x--;
                next->sc--;
            }
            ans=(ans*f[x])%MOD;
            ans=(ans*inv(f[x/2]))%MOD;
            ans=(ans*inv(bg(2,x/2,MOD)))%MOD;
        }
        ///n is always n
        //if(cnt&1) ans=(ans*3)%MOD;
        cout<<ans<<endl;
    }
    return 0;
}

