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
vector<pair<ll,ll> >v;
vector<ll>vals;
ll tree[4*2001010];
void build(int node,int b,int e){
    if(b==e) tree[node]=v[b].sc;
    else {
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        tree[node]=max(tree[node*2],tree[node*2+1]);
    }
}
ll query(int node,int b,int e,int i,int j){
    if(i<=b && e<=j) return tree[node];
    else if(i>e || j<b) return 0ll;
    else {
        int m=(b+e)/2;
        ll l=query(node*2,b,m,i,j);
        ll r=query(node*2+1,m+1,e,i,j);
        return max(l,r);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    ll x;
    cin>>n>>m;
    vector<ll>a(n),b(m);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    cin>>x;
    for(int i=0;i<n;i++){
        ll sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            v.pb({sum,(j-i+1)});
        }
    }
    sort(v.begin(),v.end());
    int sz=v.size();
    build(1,0,sz-1);
    for(int i=0;i<sz;i++) vals.pb(v[i].fs);
    ll ans=0;
    for(int i=0;i<m;i++){
        ll sum=0;
        for(int j=i;j<m;j++){
            sum+=b[j];
            ll s=x/sum;
            int in=upper_bound(vals.begin(),vals.end(),s)-vals.begin();
            in--;
            if(in<0) continue;
            ans=max(ans,query(1,0,sz-1,0,in)*(j-i+1));
        }
    }
    cout<<ans<<endl;
    return 0;
}

