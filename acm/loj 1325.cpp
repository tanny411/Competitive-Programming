#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define m 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
ll bigmod(ll base,ll power)
{
    if(power==0) return 1ll;
    else if (power==1) return base;
    ll x=bigmod(base,power/2);
    x=(x*x)%m;
    if(power&1) x=(x*base)%m;
    return x;
}
int main()
{
    ll n=ceil(sqrt(m));
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        ll k,r;
        scanf("%lld %lld",&k,&r);
        ll cur=bigmod(k,n);
        ll an=cur;
        unordered_map<ll,int>val;
        val[cur]=1;
        for(int i=2;i<=n;i++)
        {
            cur=(cur*an)%m;
            val[cur]=i;
        }
        cur=k;
        int ans=-1;
        for(int i=0;i<=n;i++)
        {
            if(val[cur]!=0)
            {
                ans=n*val[cur]-i;
                if(ans<m) break;
                else ans=-1;
            }
            cur=(cur*k)%m;
        }
        printf("Case %d: %lld\n",cas++,ans);
    }
    return 0;
}

