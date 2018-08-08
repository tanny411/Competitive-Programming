#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007


#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int tree[400009];
int q[100009];
int pre[100009];

void update(int node,int b,int e,int i,int j,int val)
{
    if(i<=b && e<=j) tree[node]=val;
    if(tree[node]!=-1 && b!=e)
    {
        tree[node*2]=tree[node];
        tree[node*2+1]=tree[node];
        tree[node]=-1;
    }
    if(i<=b && e<=j) return;
    if(e<i || b>j) return;
    int m=(b+e)/2;
    update(node*2,b,m,i,j,val);
    update(node*2+1,m+1,e,i,j,val);
}

void updateAll(int node,int b,int e)
{
    if(tree[node]!=-1 && b!=e)
    {
        tree[node*2]=tree[node];
        tree[node*2+1]=tree[node];
        tree[node]=-1;
    }
    if(b==e)
    {
        q[b]=tree[node];
        return;
    }
    int m=(b+e)/2;
    updateAll(node*2,b,m);
    updateAll(node*2+1,m+1,e);
}


int main()
{
    memset(tree,-1,sizeof tree);
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int segstart=0;
    for(int i=1;i<n;)
    {
        while(i<n && v[i]>=v[i-1])
        {
            i++;
        }
        while(i<n && v[i]<=v[i-1])
        {
            i++;
        }
        update(1,0,n-1,segstart,i-1,segstart);
        segstart=i;
        int x=i;
        while(x>0 && v[x]>=v[x-1]) x--;
        pre[i]=x;
    }
    updateAll(1,0,n-1);
    /*
    for(int i=0;i<n;i++) cout<<" "<<q[i];
    cout<<endl;
    for(int i=0;i<n;i++) cout<<" "<<pre[i];
    cout<<endl;
    */
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y) cout<<"Yes\n";
        else if(q[x-1]==q[y-1]) cout<<"Yes\n";
        else if(x-1>=pre[ q[y-1] ]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}

