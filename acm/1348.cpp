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

using namespace std;
vector<int>v(30002),gr[30002];
int level[30002],table[30002][17],tree[4*30000],sz[30002];
int n;
int chainHead[30002],chain,ptr,chainNo[30002],base[30002],baseNo[30002];

void dfs(int u)
{
    sz[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(level[v]==-1)
        {
            level[v]=level[u]+1;
            table[v][0]=u;
            dfs(v);
            sz[u]+=sz[v];
        }
    }
}
void lca_pre()
{
    for(int j=1;(1<<j)<17;j++)
    {
        for(int i=0;i<n;i++){
            if(table[i][j-1]!=-1) table[i][j]=table[table[i][j-1]][j-1];
        }
    }
}
void hld(int u,int prev){
    if(chainHead[chain]==-1) chainHead[chain]=u;
    chainNo[u]=chain;
    base[ptr]=v[u];
    baseNo[u]=ptr++;
    int mx=-1,bc=-1;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=prev && sz[v]>mx) mx=sz[v],bc=v;
    }
    if(bc!=-1) hld(bc,u);
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v==prev ||  v==bc) continue;
        chain++;
        hld(v,u);
    }
}
int lca_query(int x,int y)
{
    if(level[x]<level[y]) swap(x,y);
    int lg=1;
    for(;(1<<lg)<=level[x];lg++);
    lg--;
    for(int i=lg;i>=0;i--)
    {
        if(level[x]-(1<<i)>=level[y]) x=table[x][i];
    }
    if(x==y) return x;
    for(int i=lg;i>=0;i--)
    {
        if(table[x][i]!=table[y][i]) x=table[x][i],y=table[y][i];
    }
    return table[x][0];
}
int seg_query(int node,int b,int e,int i,int j)
{
    if(b==e && b==i) return tree[node];
    if(j<b || i>e) return 0;
    int m=(b+e)/2;
    return seg_query(node*2,b,m,i,j)+seg_query(node*2+1,m+1,e,i,j);
}
int hld_query(int x,int v)
{
    int sum=0;
    while(1){
        if(chainNo[x]==chainNo[v]){
            sum+=seg_query(1,0,ptr,baseNo[v],baseNo[x]);
            return sum;
        }
        sum+=seg_query(1,0,ptr,baseNo[chainHead[chainNo[x]]],baseNo[v]);
        x=table[chainHead[chainNo[x]]][0];
    }
}
void build(int node,int b,int e)
{
    if(b==e) {tree[node]=base[b]; return;}
    int m=(b+e)/2;
    build(node*2,b,m);
    build(node*2+1,m+1,e);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int x,int y)
{
    int v=lca_query(x,y);
    return hld_query(x,v)+hld_query(y,v);
}
void update(int node,int b,int e,int i,int val)
{
    if(b==e && b==i) {tree[node]=val; return;}
    int m=(b+e)/2;
    if(i<=m) update(node*2,b,m,i,val);
    else update(node*2+1,m+1,e,i,val);
    tree[node]=tree[node*2]+tree[node*2+1];
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++) gr[i].clear();
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        memset(level,-1,sizeof level);
        memset(table,-1,sizeof table);
        memset(chainHead,-1,sizeof chainHead);
        level[0]=0;
        dfs(0);
        lca_pre();
        chain=1;
        ptr=0;
        hld(0,-1);
        build(1,0,ptr);
        ptr--;
        int q;
        cin>>q;
        cout<<"Case "<<test++<<":\n";
        while(q--)
        {
            int type,node,to;
            cin>>type>>node>>to;
            if(type){
                update(1,0,ptr,baseNo[node],to);
            }
            else{
                cout<<query(node,to)<<endl;
            }
        }
    }
    return 0;
}

