#include<bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back
#define pii pair<int,int>
#define maxnode 100002
#define logmaxnode 20
using namespace std;
vector<int>val(maxnode),lvl(maxnode,-1),ans(maxnode);
vector<pii>gr[maxnode];
int table[maxnode][logmaxnode];
int n;
void dfs(int u){
    for(int i=0;i<gr[u].size();i++){
        int v=gr[u][i].fs;
        if(lvl[v]==-1){
            table[v][0]=u;
            lvl[v]=lvl[u]+1;
            dfs(v);
        }
    }
}
int dfs2(int u,int p)
{
    int huu=val[u];
    for(int i=0;i<gr[u].size();i++){
        int v=gr[u][i].fs;
        if(v!=p){
            int x=dfs2(v,u);
            ans[gr[u][i].sc]+=x;
            huu+=x;

        }
    }
    return huu;
}
void init_lca()
{

    for(int j=1; (1<<j)<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(table[i][j-1]!=-1) table[i][j]=table[table[i][j-1]][j-1];
        }
    }
}

int lca_query(int p,int q)
{
    if(lvl[q]>lvl[p]) swap(p,q);

    //int lg=log2(lvl[p]);
    int lg;
    for(lg=1; (1<<lg)<=lvl[p]; lg++);
    lg--;

    for(int i=lg; i>=0; i--)
    {
        if(lvl[p]-(1<<i)>=lvl[q])
        {
            p=table[p][i];
        }
    }

    if(p==q) return q;

    for(int i=lg; i>=0; i--)
    {
        if(table[p][i]!=-1 && table[p][i]!=table[q][i])
        {
            p=table[p][i];
            q=table[q][i];
        }
    }

    return table[p][0];
}
int main(){
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        gr[x].pb({y,i});
        gr[y].pb({x,i});
    }

    memset(table,-1, sizeof table);
    int start=0;
    lvl[start]=0;
    table[start][0]=start;

    dfs(start);
    init_lca();
    /*
    for(int i=0;i<n;i++){
        cout<<i<<": ";
        for(int j=0;j<eds[i].size();j++){
            cout<<" "<<eds[i][j];
        }
        cout<<endl;
    }*/
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        int lca=lca_query(x,y);
        val[x]++;
        val[y]++;
        val[lca]-=2;
        //cout<<"lca "<<lca<<endl;
    }
    dfs2(0,-1);
    for(int i=0;i<n-1;i++){
        if(i) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}
