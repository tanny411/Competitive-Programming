// C++ program to calculate discrete logarithm
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll discreteLogarithm(ll a, ll b, ll m)
{
    ll n=(ll)sqrt (m+.0)+1;
    // Calculate a ^ n
    ll an=1;
    for (ll i=0;i<n;++i)
        an=(an*a)%m;

    map<ll, ll> value;

    // Store all values of a^(n*i) of LHS
    for (ll i=1, cur=an; i<=n; ++i)
    {
        if (!value.count(cur))
            value[cur]=i;
        cur=(cur*an)%m;
    }

    ll ret=1<<30;
    for (ll i=0, cur=b; i<=n; ++i)
    {
        // Calculate (a ^ j) * b and check
        // for collision
        if (value.count(cur))
        {
            ll ans = value[cur] * n - i;
            ret=min(ret,ans);
        }
        cur=(cur*a)%m;
    }
    return ret;
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<"Case "<<test++<<": "<<discreteLogarithm(a, b, 100000007)<<endl;
    }
}

