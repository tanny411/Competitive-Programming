#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define ll long long

#define mx 1000006
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
    ll cnt=1;
    for(int i=0;i<sz && prime[i]*prime[i]<=n;i++)
    {
        ll c=0;
        while(n%prime[i]==0) n/=prime[i],c++;
        cnt*=(1+c);
    }
    if(n>1) cnt*=2;
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    sz=prime.size();
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll p;
        cin>>p;
        cout<<"Case "<<test++<<": "<<NOD(p)-1<<endl;
    }
    return 0;
}


