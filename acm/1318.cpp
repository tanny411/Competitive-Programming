//https://codeforces.com/blog/entry/9697#comment-468229
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
int sz;
vector<int>prime,flag(mx),cnt;
void sieve()
{
    prime.pb(2);
    for(ll i=3;i<mx;i+=2)
    {
        if(!flag[i]) {
            prime.pb(i);
            for(ll j=i*i;j<mx;j+=(i+i)) flag[j]=1;
        }
    }
}
ll bg(ll base,ll power, ll m)
{
    if(power==0) return 1ll;
    if(power==1) return base%m;
    ll x=bg(base,power/2,m);
    x=(x*x)%m;
    if(power&1) x=(x*base)%m;
    return x;
}
void factorial_factorization(ll n, ll sign)
{
    for(int i=0;i<sz && prime[i]<=n;i++)
    {
        ll temp=n;
        while(temp) temp/=prime[i],cnt[i]+=sign*temp;
    }
}
ll C(ll n,ll r, ll m)
{
    //nCr % M and M is not prime: prime factorize nCr then for each power of prime p, do bigmod with M. now to prime factorize nCr,
    //{ prime powers of n! - prime powers of r! - prime powers of (n-r)! }
    ll ans=1;
    cnt=vector<int>(sz);
    factorial_factorization(n,1);
    factorial_factorization(r,-1);
    factorial_factorization(n-r,-1);
    for(int i=0;i<sz;i++)
    {
        ans=(ans*bg(prime[i],cnt[i],m))%m;
    }
    return ans;
}
int main()
{
    sieve();
    sz=prime.size();
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n,k,l,m;
        cin>>n>>k>>l>>m;
        if(m==0) cout<<"Case "<<test++<<": "<<bg(k,l,n)+1<<endl;
        else if(k==1) cout<<"Case "<<test++<<": 1\n";
        else{
            ll ans=1;
            if(k%2==0)
            {
                ans=bg(k,l-1,n);
                ans=(ans*(k/2ll))%n;
                ans=(ans*bg(k-1,m,n))%n;
            }
            else{
                ans=bg(k,l,n);
                ans=(ans*bg(k-1,m-1,n))%n;
                ans=(ans*(k/2ll))%n;//(k-1)/2
            }
            ans=(ans*C(l,m,n))%n;
            cout<<"Case "<<test++<<": "<<ans+1<<endl;
        }
    }
    return 0;
}

