#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

#define nd 100005

vector<int>gr[nd],tree(4*nd,1<<30);
int lvl[nd],p[nd],sz[nd],chain,ptr=0,chainHead[nd];
int chainNo[nd],posBase[nd],base[nd];

void dfs(int u)
{
    sz[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(lvl[v]==-1)
        {
            p[v]=u;
            lvl[v]=lvl[u]+1;
            dfs(v);
            sz[u]+=sz[v];
        }
    }
}

void hld(int u,int par)
{
    if(chainHead[chain]==-1)
    {
        chainHead[chain]=u;
    }
    ++ptr;
    posBase[u]=ptr;
    chainNo[u]=chain;
    base[ptr]=u;
    int mx=0,bc=-1;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=par) if(sz[v]>mx) mx=sz[v],bc=v;
    }
    if(bc!=-1)
    {
        hld(bc,u);
    }
    else return;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=par && v!=bc) chain++, hld(v,u);
    }
}

void update(int node,int b,int e,int i)
{
    if(b==e && b==i) {if(tree[node]==1<<30) tree[node]=base[b]; else tree[node]=1<<30; return;}
    if(b<=i && i<=e)
    {
        int m=(b+e)/2;
        if(i<=m) update(node*2,b,m,i);
        else update(node*2+1,m+1,e,i);
        if(tree[node*2]!=1<<30) tree[node]=tree[node*2];
        else tree[node]=tree[node*2+1];
    }
    return;
}

int query_seg(int node,int b,int e,int i,int j)
{
    if(b>=i && e<=j) return tree[node];
    if(j<b || i>e) return 1<<30;
    int m=(b+e)/2;
    int l=query_seg(node*2,b,m,i,j);
    int r=query_seg(node*2+1,m+1,e,i,j);
    if(l!=1<<30) return l;
    else return r;
}

int query(int x)
{
    int ans=-1;
    while(1)
    {
        if(chainNo[x]==chainNo[1])
        {
            int y=query_seg(1,1,ptr,posBase[1],posBase[x]);
            if(y!=1<<30) ans=y;
            return ans;
        }
        int y=query_seg(1,1,ptr,posBase[ chainHead[ chainNo[x] ] ],posBase[x]);
        if(y!=1<<30) ans=y;
        x=p[chainHead[chainNo[x]]];
        //cout<<"ouch\n";
    }
}

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    {
        lvl[i]=-1;
        chainHead[i]=-1;
    }
    lvl[1]=0;
    dfs(1);
    chain=1;
    hld(1,0);
    while(q--)
    {
        int d,x;
        scanf("%d%d",&d,&x);
        if(!d) update(1,1,ptr,posBase[x]);
        else printf("%d\n",query(x));
    }
    return 0;
}

