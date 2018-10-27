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
int Gcd(int a, int b) {
	while(b) b^=a^=b^=a%=b;
	return a;
}
vector<ll>prime;
void sieve(int n)
{
    vector<int>flag(n+4);
    prime.pb(2);
    for(int i=3;i<n;i+=2)
    {
        if(flag[i]==0)
        {
            prime.pb(i);
            for(ll j=1ll*i*i;j<n;j+=(i+i))flag[j]=1;
        }
    }
}
int main()
{
    //ios_base::sync_with_stdio(false);
    sieve(46345);
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%lld",&n);
        int gcd=0;
        int sign=0;
        if(n<0) n=-n,sign=1;
        int rt=(int)sqrt(n);
        for(int i=0;i<prime.size() && prime[i]<=rt;i++)
        {
            if(n%prime[i]==0)
            {
                int cnt=0;
                while(n%prime[i]==0) n/=prime[i],cnt++;
                gcd=Gcd(gcd,cnt);
                if(cnt==1) break;
                rt=(int)sqrt(n);
            }
        }
        if(n>1) gcd=1;
        if(sign) {while(!(gcd&1)) gcd>>=1;}
        printf("Case %d: %d\n",test++,gcd);
    }
    return 0;
}

