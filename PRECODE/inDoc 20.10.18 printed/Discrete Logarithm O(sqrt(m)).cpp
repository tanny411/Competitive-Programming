// C++ program to calculate discrete logarithm
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll discreteLogarithm(ll a, ll b, ll m)
{
    if(b==1) return 0;
    ll n=(ll)sqrt (m+.0)+1;
    // Calculate a ^ n
    ll an=1;
    for (ll i=0;i<n;++i)
        an=(an*a)%m;

    unordered_map<ll, ll> value;

    // Store all values of a^(n*i) of LHS
    for (ll i=1, cur=an; i<=n; ++i)
    {
        if (!value.count(cur))
            value[cur]=i;
        cur=(cur*an)%m;
    }

    for (ll i=0, cur=b; i<=n; ++i)
    {
        // Calculate (a ^ j) * b and check
        // for collision
        if (value.count(cur))
        {
            ll ans = value[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur=(cur*a)%m;
    }
    return -1;
}

// Driver code
int main()
{
    ll a = 3, b = 9, m = 100000007;
    cout << discreteLogarithm(a, b, m) << endl;

    a = 2, b = 100, m = 100000007;
    cout << discreteLogarithm(a, b, m);
}
