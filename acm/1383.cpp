#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<ll,ll>
#define pdd pair<double,double>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
ll n,s,d,k;
vector<pii>v;
int okay(ll mid){
    vector<pii>in;
    for(int i=0;i<n;i++){
        ll h=v[i].sc-k+mid;
        if(h>d) return 0;
        ll dis=sqrt(d*d-h*h);
        in.pb(pii(v[i].fs-dis,v[i].fs+dis));
    }
    //sort(in.begin(),in.end());
    ll snipers=1;
    ll en=in[0].sc;
    for(int i=1;i<n;i++)
    {
        if(in[i].fs>en) {
            snipers++;
            en=in[i].sc;
        }
        else en=min(en,in[i].sc);
    }
    return (snipers<=s);
}

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>k>>n>>s>>d;
        v=vector<pii>(n);
        for(int i=0;i<n;i++) {
            cin>>v[i].fs>>v[i].sc;
        }
        sort(v.begin(),v.end());
        ll lo=0,hi=d,ans=-1;
        while(lo<=hi){
            ll mid=(lo+hi)/2;
            if(okay(mid)){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        if(ans==-1) cout<<"Case "<<test++<<": impossible"<<endl;
        else cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
