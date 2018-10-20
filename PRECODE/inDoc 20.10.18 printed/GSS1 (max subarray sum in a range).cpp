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
vector<ll>v;
struct data
{
    ll sum,mxsum,prefixsum,suffixsum;
} tree[4*50000];
data mergeit(data l,data r)
{
    data n;
    n.sum=l.sum+r.sum;
    n.prefixsum=max(l.prefixsum,r.prefixsum+l.sum);
    n.suffixsum=max(r.suffixsum,l.suffixsum+r.sum);
    n.mxsum=max(max(l.mxsum,r.mxsum),l.suffixsum+r.prefixsum);
    return n;
}
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum=tree[node].mxsum=tree[node].prefixsum=tree[node].suffixsum=v[e];
    }
    else
    {
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        tree[node]=mergeit(tree[node*2],tree[node*2+1]);
    }
}
data query(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j) return tree[node];
    else if(e<i || j<b)
    {
        data n;
        n.sum=n.mxsum=n.prefixsum=n.suffixsum=INT_MIN;
        return n;
    }
    else
    {
        int m=(b+e)/2;
        return mergeit(query(node*2,b,m,i,j),query(node*2+1,m+1,e,i,j));
    }
}
void update(int node,int b,int e,int i,int val)
{
    if(b==e && b==i)
    {
        tree[node].sum=tree[node].mxsum=tree[node].prefixsum=tree[node].suffixsum=v[e];
    }
    else
    {
        int m=(b+e)/2;
        if(i<=m)update(node*2,b,m,i,val);
        else update(node*2+1,m+1,e,i,val);
        tree[node]=mergeit(tree[node*2],tree[node*2+1]);
    }
}
int main()
{
    int n,q;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int x;
        scanf("%d",&x);
        v.pb(x);
    }
    build(1,0,n-1);
    scanf("%d",&q);
    for(int i=0;i<q;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%lld\n",query(1,0,n-1,x-1,y-1).mxsum);
    }
    return 0;
}

