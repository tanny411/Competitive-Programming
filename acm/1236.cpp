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
#define mx 10000003

using namespace std;

bitset<mx>flag;

vector<int>prime;

void sieve()
{
    prime.pb(2);
    for(int i=3;i<mx;i+=2)
    {
        if(!flag[i])
        {
            prime.pb(i);
            for(ll j=1ll*i*i;j<mx;j+=(i+i)) flag[j]=1;
        }
    }
}

int main()
{
    sieve();
    int sz=prime.size();
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans=1;
        for(int i=0;i<sz && prime[i]*prime[i]<=n;i++){
            ll cnt=1;
            while(n%prime[i]==0) n/=prime[i],cnt++;
            cnt=2*cnt-1; ///p^e --> cnt=2*(e+1)-1; (e,e) occurs twice
            ans*=cnt;
        }
        if(n>1) ans*=3;
        cout<<"Case "<<test++<<": "<<ans/2ll+1<<endl;///(n,n) occurs only once
    }
    return 0;
}

