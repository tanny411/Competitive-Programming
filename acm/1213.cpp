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
ll bg(ll base, ll power, ll mod)
{
    if(power==0) return 1ll;
    else if(power==1) return base;
    ll x=bg(base,power/2,mod);
    x=(x*x)%mod;
    if(power&1) x=(x*base)%mod;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n,k,m;
        cin>>n>>k>>m;
        vector<ll>v(n);
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            sum=(sum+v[i])%m;
        }
        sum=(sum*k)%m;
        sum=(sum*bg(n,k-1,m))%m;
        ///sum*k*( n^(k-1) )
        cout<<"Case "<<test++<<": "<<sum<<endl;
    }
    return 0;
}

