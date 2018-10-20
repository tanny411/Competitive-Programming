#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

pii extendedEuclid(ll a,ll b)
{
    if(b==0) return pii(1,0);
    else
    {
        pii d=extendedEuclid(b,a%b);
        return pii(d.sc,d.fs-d.sc*(a/b));
    }
}
ll modularInverse(ll a,ll n)
{
    pii ret=extendedEuclid(a,n);
    return ((ret.fs%n)+n)%n;
}
int main()
{
    return 0;
}

