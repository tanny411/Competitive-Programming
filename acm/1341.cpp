#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

#define mx 1000010
vector<ll>prime;
bool flag[mx];
int sz;

void sieve()
{
    prime.pb(2);
    for(ll i=3;i<mx;i+=2)
    {
        if(flag[i]==false)
        {
            prime.pb(i);
            for(ll j=i*i;j<mx;j+=(i+i)) flag[j]=true;
        }
    }
    sz=prime.size();
    //cout<<sz<<endl;
    //for(int i=0;i<100;i++) cout<<" "<<prime[i]; cout<<endl;
}
ll NOD(ll n)
{
    ll ret=1;
    for(ll i=0;i<sz && prime[i]*prime[i]<=n;i++){
        ll cnt=1;
        while(n%prime[i]==0) n/=prime[i],cnt++;
        ret*=cnt;
    }
    if(n>1) ret*=2ll;
    ret/=2ll;
    return ret; ///wont include sqrt of perfect square, cuz otherwise the rectangle will be square
}
int main()
{
    sieve();
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n,a,sq;
        scanf("%lld%lld",&n,&a);
        if(a>=sqrt(n)) printf("Case %d: 0\n",test++);///when i cast sqrt to ll its giving WA, wtf? why?
        else{
            ll ex=0;
            for(int i=1;i<a;i++) if(n%i==0) ex++;
            printf("Case %d: %lld\n",test++,NOD(n)-ex);
        }
    }
    return 0;
}

