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
ll tree[400000];
void update(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j)
        tree[node]++;
    if(tree[node]!=0)
    {
        if(b!=e)
        {
            tree[node*2]+=tree[node];
            tree[node*2+1]+=tree[node];
            tree[node]=0;
        }
    }
    if(i<=b && e<=j)
        return ;
    if(b>j || i>e)
        return ;
    int m=(b+e)/2;
    update(node*2,b,m,i,j);
    update(node*2+1,m+1,e,i,j);
}
void prnt(int node,int b,int e)
{
    if(tree[node]!=0)
    {
        if(b!=e)
        {
            tree[node*2]+=tree[node];
            tree[node*2+1]+=tree[node];
            tree[node]=0;
        }
    }
    if(b==e)
    {
        if(b) cout<<" ";
        cout<<tree[node];
        return;
    }
    int m=(b+e)/2;
    prnt(node*2,b,m);
    prnt(node*2+1,m+1,e);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ll>v(n),cum(n);
        memset(tree,0,sizeof tree);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
            cum[i]=v[i];
            if(i) cum[i]+=cum[i-1];
        }

        for(int i=0;i<n;i++)
        {
            if(i)
            {
                ll x=cum[i-1]-v[i];
                int in=lower_bound(cum.begin(),cum.end(),x)-cum.begin();
                if(in<i) update(1,0,n-1,in,i-1);
            }
            if(i<n-1)
            {
                ll x=cum[i]+v[i];
                int in=upper_bound(cum.begin(),cum.end(),x)-cum.begin();
                if(in==n) in--;
                if(in>i) update(1,0,n-1,i+1,in);
            }
        }

        prnt(1,0,n-1);
        cout<<"\n";
    }
    return 0;
}
