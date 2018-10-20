/**
You are given a tree (an acyclic undirected connected graph) with N nodes.
The tree nodes are numbered from 1 to N. We define dist(a, b) as the number of edges on the path from node a to node b.

Each node has a color, white or black. All the nodes are black initially.

We will ask you to perform some instructions of the following form:

0 i : change the color of i-th node(from black to white, or from white to black).
1 v : ask for the minimum dist(u, v), node u must be white(u can be equal to v). Obviously, as long as node v is white, the result will always be 0.
**/
#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define inf 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second
#define nd 100003
#define ln 20
using namespace std;

vector<int>gr[100003];
int n,table[nd][ln],level[nd],par[nd],sz[nd],Siz,col[nd];///parent in centroid tree
bool is_centroid[nd];
multiset<pii>ans[nd];

void dfs1(int u,int p)
{
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=p){
            level[v]=level[u]+1;
            table[v][0]=u;
            dfs1(v,u);
        }
    }
}
void preprocess()
{
    memset(table,-1,sizeof table);
    level[0]=0;
    table[0][0]=0;
    dfs1(0,-1);
    ///lca precalc
    for(int j=1;(1<<j)<n;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(table[i][j-1]!=-1) table[i][j]=table[table[i][j-1]][j-1];
        }
    }
}
int lca(int x,int y)
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
        if(table[x][i]!=-1 && table[x][i]!=table[y][i]) {
            x=table[x][i];
            y=table[y][i];
        }
    }
    return table[x][0];
}
int dist(int x,int y)
{
    return level[x]+level[y]-2*level[lca(x,y)];
}
int dfs2(int u,int p){
    sz[u]=1;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=p && !is_centroid[v]){
            sz[u]+=dfs2(v,u);
        }
    }
    return sz[u];
}
int dfs3(int u,int p)///centroid finder
{
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=p && !is_centroid[v] && sz[v]>Siz/2){
            return dfs3(v,u);
        }
    }
    return u;
}
void decompose(int u,int p)
{
    Siz=dfs2(u,u);///calculate size
    int centroid=dfs3(u,u);
    is_centroid[centroid]=true;
    par[centroid]=(p==-1?centroid:p);
    for(int i=0;i<gr[centroid].size();i++)
    {
        int v=gr[centroid][i];
        if(!is_centroid[v]) decompose(v,centroid);
    }
}
void white_update(int u)
{
    col[u]=1;
    int x=u;
    while(1)
    {
        ans[x].insert(pii(dist(x,u),u));
        if(x==par[x]) break;
        x=par[x];
    }
}
void black_update(int u)
{
    col[u]=0;
    int x=u;
    while(1)
    {
        ans[x].erase(pii(dist(x,u),u));
        if(x==par[x]) break;
        x=par[x];
    }
}
int query(int u)
{
    int x=u;
    int ret=inf;
    while(1){
        if(!ans[x].empty())
            ret=min(ret,(*(ans[x].begin())).fs+dist(x,u));
        if(x==par[x]) break;
        x=par[x];
    }
    if(ret==inf) return -1;
    else return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int m;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    preprocess();
    decompose(0,-1);
    cin>>m;
    while(m--){
        int type,v;
        cin>>type>>v;
        v--;
        if(!type) {if(col[v]) black_update(v); else white_update(v);}
        else cout<<query(v)<<endl;
    }
    return 0;
}

