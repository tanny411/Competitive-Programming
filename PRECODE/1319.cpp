#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define pll pair<ll,ll>

#define ll long long

#define fs first
#define sc second

using namespace std;

ll bg(ll base,ll power,ll mod)
{
    if(power==0) return 1ll;
    ll x=bg(base,power/2,mod);
    x=(x*x)%mod;
    if(power&1) x=(x*base)%mod;
    return x;
}
ll ncr(ll n,ll r,ll p)
{
    if(n<r) return 0ll;
    if(n==r) return 1ll;
    r=min(r,n-r);
    ll nu=1,de=1;
    for(ll i=n-r+1;i<=n;i++) nu=(nu*i)%p;
    for(ll i=1;i<=r;i++) de=(de*i)%p;
    return ((nu*bg(de,p-2,p))%p + p)%p; ///only for primes
}
ll lucas(ll n,ll r,ll p)///nCr % p //for p is prime or prime power
{
    if(r==0) return 1;
    return (ncr(n%p,r%p,p)*lucas(n/p,r/p,p))%p;
}
ll CRT(vector<pll>v,ll M)
{
    ll ret=0;
    for(int i=0;i<v.size();i++)
    {
        ll ai=v[i].fs;
        ll p=v[i].sc;
        ll Mi=M/p;
        ret+=ai*Mi*bg(Mi,p-2,p);
        ret%=M;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        vector<pll>v;
        ll x,p,M=1,n;
        cin>>n;
        while(n--)
        {
            cin>>p>>x;
            v.pb(pll(x,p));
            M*=p;
        }
        ll ans=CRT(v,M);
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

