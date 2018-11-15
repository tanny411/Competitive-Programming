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

#define mx 100010
using namespace std;

vector<int>prime;
bitset<mx>flag;

void sieve()
{
    prime.pb(2);
    for(ll i=3;i<mx;i+=2)
    {
        if(flag[i]==0)
        {
            prime.pb(i);
            for(ll j=i*i;j<mx;j+=(i+i)) flag[j]=1;
        }
    }
}
ll bg(ll base, ll power, ll mod)
{
    if(power==0) return 1ll;
    if(power==1) return base%mod;
    ll x=bg(base,power/2,mod);
    x=(x*x)%mod;
    if(power&1) x=(x*base)%mod;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    int sz=prime.size();
    //cout<<sz<<endl;
    //for(int i=0;i<100;i++) cout<<" "<<prime[i]; cout<<endl;
    int tt,test=1;
    cin>>tt;
    while(tt--)
    {
        int n,t;
        cin>>n>>t;
        ///factorial factorization
        ll ans=1;
        for(int i=0;i<sz && prime[i]<=n;i++)
        {
            int nn=n;
            ll e=0;
            while(nn/prime[i]) nn/=prime[i],e+=nn;
            if(e>=t) ans=(ans*bg(prime[i],e/t,10000019))%10000019;
        }
        if(ans==1) ans=-1;
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

