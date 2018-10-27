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

#define mx 100005
using namespace std;

int flag[mx];
vector<int>prime;
int sz;

void sieve(){
    prime.pb(2);
    for(int i=3;i<mx;i+=2)
    {
        if(flag[i]==0){
            prime.pb(i);
            for(ll j=1ll*i*i;j<mx;j+=(i+i)) flag[j]=1;
        }
    }
}
ll NOD(ll n){
    ll cnt=1ll;
    for(int i=0;i<sz && prime[i]*prime[i]<=n;i++)
    {
        ll c=0;
        while(n%prime[i]==0) n/=prime[i],c++;
        cnt*=(1ll+c);
    }
    if(n>1) cnt*=2ll;
    return cnt;
}
int main()
{
    sieve();
    sz=prime.size();
    ios_base::sync_with_stdio(false);
    ll b;
    cin>>b;
    cout<<NOD(b)<<endl;
    return 0;
}

