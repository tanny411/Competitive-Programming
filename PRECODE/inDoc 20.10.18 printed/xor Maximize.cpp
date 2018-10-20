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
ll bits(ll n)
{
    ll cnt=0;
    while(n){
        cnt++;
        n/=2;
    }
    return cnt;
}
void gaussian(vector<ll> &v,int n)
{
    ll x=1ll<<62;
    for(int i=0;i<n && x;i++){
        if(!(x&v[i])){
            int f=0;
            for(int j=i+1;j<n;j++) if(x&v[j]) { swap(v[i],v[j]); f=1; break; }
            if(f==0){
                x>>=1;
                i--;
                continue;
            }
        }
        for(int j=0;j<n;j++) if(i!=j && x&v[j]) v[j]^=v[i];
        x>>=1;
        //cout<<i<<" --> "; for(int i=0;i<n;i++) cout<<" "<<v[i]; cout<<endl;
    }
}
int main()
{
    ///choosing a subset so that its xor is maximum
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        //sort(v.rbegin(),v.rend());
        //dorkar nai, 63rd bit theke chalay dilei hobe
        gaussian(v,n);
        ll mx=0;
        for(int i=0;i<n;i++) mx^=v[i];
        cout<<"Case "<<test++<<": "<<mx<<endl;
    }
    return 0;
}
