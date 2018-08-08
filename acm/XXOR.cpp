#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int tree[400000][35];
int ara[35];
vector<int>v;
void build(int node,int b,int e)
{
    if(b==e)
    {
        int x=v[b];
        int i=0;
        while(x)
        {
            if(x&1) tree[node][i]++;
            i++;
            x/=2;
        }
        return ;
    }
    int m=(b+e)/2;
    build(node*2,b,m);
    build(node*2+1,m+1,e);
    for(int i=0;i<31;i++) tree[node][i]=tree[node*2][i]+tree[node*2+1][i];
    return ;
}
void query(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j)
    {
        for(int in=0;in<31;in++) ara[in]+=tree[node][in];
        return ;
    }
    if(b>j || e<i) return ;
    int m=(b+e)/2;
    query(node*2,b,m,i,j);
    query(node*2+1,m+1,e,i,j);
    return;
}
int main()
{
    int n,q;
    cin>>n>>q;
    v=vector<int>(n);
    for(int i=0;i<n;i++) cin>>v[i];
    build(1,0,n-1);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        memset(ara,0,sizeof ara);
        query(1,0,n-1,l,r);
        ll ans=0;
        int L=(r-l+1)/2;
        for(int i=0;i<31;i++)
        {
            if(ara[i]<=L) ans+=(1<<i);
        }
        cout<<ans<<endl;
    }
    return 0;
}

