#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll discreteLogarithm(ll a, ll b, ll m)
{
    if(b==1) return 0ll;
    ll n=(ll)sqrt(m+.0)+1;
    ll an=1;
    for (ll i=0;i<n;++i)
        an=(an*a)%m;
    map<ll, ll> value;
    for (ll i=1, cur=an; i<=n; ++i)
    {
        if (value.find(cur)==value.end())
            value[cur]=i;
        cur=(cur*an)%m;
    }

    for (ll i=0, cur=b; i<=n; ++i)
    {
        if (value.find(cur)!=value.end())
        {
            ll ans = value[cur]*n-i;
            if(ans<0) continue;
            return ans;
        }
        cur=(cur*a)%m;
    }
    return 0;
}
int main()
{
    int t,test=1;
    int a,b,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&a,&b,&m);
        printf("%lld\n",discreteLogarithm(a, b, m));
    }
}
