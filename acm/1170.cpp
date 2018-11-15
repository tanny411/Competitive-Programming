#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define mod 100000007

#define ll long long

#define fs first
#define sc second

using namespace std;
set<ll>s;
vector<ll>v;
ll fact[2000009];
ll bg(ll base,ll power, ll m)
{
    if(power==0) return  1ll;
    else if(power==1) return base%m;
    else{
        ll x=bg(base,power/2,m);
        x=(x*x)%m;
        if(power&1) x=(x*base)%m;
        return x;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    for(ll i=2;i<=100000;i++)
    {
        for(ll j=i*i;j<=10000000000;j*=i)
        {
            //because there might be duplicates, e.g if a number is a power of 6
            //it is also a power of 2 and 3
            s.insert(j);
        }
    }
    cout<<s.size()<<endl;
    for(auto it=s.begin();it!=s.end();it++) v.pb(*it);
    fact[0]=fact[1]=1;
    for(ll i=2;i<=2000000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        int in=upper_bound(v.begin(),v.end(),a-1)-v.begin()-1;
        int fin=upper_bound(v.begin(),v.end(),b)-v.begin()-1;
        //cout<<"range "<<fin-in<<endl;
        in=fin-in;
        ll ans=0;
        //catalan
        if(in) ans=((fact[in+in]*bg(fact[in],mod-2,mod))%mod*bg(fact[in+1],mod-2,mod))%mod;
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

