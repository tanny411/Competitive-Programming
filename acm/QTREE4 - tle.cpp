///tried to modify on Qtree5, TLE tho

/**
You are given a tree (an acyclic undirected connected graph) with N nodes,
and nodes numbered 1,2,3...,N. Each --edge has an integer value assigned to it-- (note that the value can be negative).
Each node has a color, white or black. We define dist(a, b) as the sum of the value of the edges on the path from node a to node b.

All the nodes are white initially.

We will ask you to perform some instructions of the following form:

C a : change the color of node a.(from black to white or from white to black)
A : ask for the maximum dist(a, b), both of node a and node b must be white(a can be equal to b).
Obviously, as long as there is a white node, the result will alway be non negative.
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

vector<int>gr[nd],wt[nd];
int n,table[nd][ln],level[nd],par[nd],sz[nd],Siz,col[nd],disAra[nd];///parent in centroid tree
bool is_centroid[nd];
multiset<pii>ans[nd];

void dfs1(int u,int p)
{
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=p){
            level[v]=level[u]+1;
            disAra[v]=disAra[u]+wt[u][i];
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
    disAra[0]=0;
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
    return disAra[x]+disAra[y]-2*disAra[lca(x,y)];
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
pii query(int u)
{
    int x=u;
    int ret=-inf;
    int node=-1;
    while(1){
        if(!ans[x].empty())
        {
            int val=(*(ans[x].rbegin())).fs+dist(x,u);
            if(ret<val) {
                //ret=val;
                int tempNode=(*(ans[x].rbegin())).sc;
                if(tempNode==u) {
                    if(ans[x].size()>1){
                        val=(*(--ans[x].rbegin())).fs+dist(x,u);
                        tempNode=(*(--ans[x].rbegin())).sc;
                        if(ret<val){
                            ret=val;
                            node=tempNode;
                        }
                    }
                }
                else{
                    ret=val;
                    node=tempNode;
                }
            }
        }
        if(x==par[x]) break;
        x=par[x];
    }
    return pii(ret,node);
}
int _query()
{
    pii x=query(0);
    if(x.sc==-1 && col[0]) return 0;
    if(x.sc==-1) return -1;
    //cout<<"nodes are "<<x.sc<<"("<<x.fs<<") ";
    x=query(x.sc);
    if(x.sc==-1) return 0;
    //cout<<x.sc<<endl;
    return x.fs;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int m;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        gr[x].pb(y);
        gr[y].pb(x);
        wt[x].pb(w);
        wt[y].pb(w);
    }
    preprocess();
    decompose(0,-1);
    for(int i=0;i<n;i++) white_update(i);
//    cout<<"print multiset : ";
//    for(int i=0;i<n;i++)
//    {
//        cout<<"\n"<<i;
//        for(auto j=ans[i].begin();j!=ans[i].end();j++) cout<<" ("<<(*j).fs<<" from "<<(*j).sc<<")";
//    }
//    cout<<"why man "<<query(2).sc<<endl;
    cin>>m;
    while(m--){
        char ch;
        int v;
        cin>>ch;
        if(ch=='C'){
            cin>>v;
            v--;
            if(col[v]) black_update(v);
            else white_update(v);
        }
        else {
            int ans=_query();
            if(ans==-1) cout<<"They have disappeared."<<endl;
            else cout<<ans<<endl;
        }
    }
    return 0;
}


