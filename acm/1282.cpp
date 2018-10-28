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
ll bg(ll base,ll power,ll m)
{
    if(power==0) return 1ll;
    if(power==1) return base%m;///base%m deya lagse
    ll x=bg(base,power/2,m);
    x=(x*x)%m;
    if(power&1) x=(x*base)%m;
    return x;
}
int main()
{
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n,k;
        scanf("%lld%lld",&n,&k);
        double f=1.0*k*log10(1.0*n);
        f-=(ll)f;
        f=pow(10.0,f);
        ll first=f*100;
        ll last=bg(n,k,1000ll);
        printf("Case %d: %lld %03lld\n",test++,first,last);
    }
    return 0;
}

