#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define pii pair<int,int>
#define ppi pair<pii,int>

#define LL long long

#define fs first
#define sc second
using namespace std;

///
#define node 10003
#define ln 14

vector<pair<pii,int> >gr[node]; ///v,w,indexOfEdge
int table[node][ln],level[node],siz[node],indexx[node];
int chainNo[node],chainHead[node],chain,posBase[node],ptr,base[node];
int tree[4*node];

void dfs(int u)
{
    siz[u]=1;
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i].fs.fs;
        int w=gr[u][i].fs.sc;
        int in=gr[u][i].sc;
        if(level[v]==-1)
        {
            table[v][0]=u;
            level[v]=level[u]+1;
            indexx[in]=v;
            dfs(v);
            siz[u]+=siz[v];
        }
    }
}

int lca_query(int x,int y)
{
    if(level[x]<level[y]) swap(x,y);
    int lg;
    for(lg=1; (1<<lg)<=level[x]; lg++);
    lg--;
    for(int i=lg; i>=0; i--)
    {
        if(level[x]-(1<<i)>=level[y]) x=table[x][i];
    }
    if(x==y) return x;
    for(int i=lg; i>=0; i--)
    {
        if(table[x][i]!=table[y][i])
        {
            x=table[x][i];
            y=table[y][i];
        }
    }
    return table[x][0];
}

void hld(int u,int prev,int cost)
{
    if(chainHead[chain]==-1)
    {
        chainHead[chain]=u;
    }
    ptr++;
    chainNo[u]=chain;
    posBase[u]=ptr;
    base[ptr]=cost;
    int bc=-1,mx=-1,cs=-1;
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i].fs.fs;
        //cout<<"aysha  "<<u<<" "<<v<<endl;
        if(v!=prev && siz[v]>mx) mx=siz[v],bc=v,cs=gr[u][i].fs.sc;
    }
    if(bc!=-1) hld(bc,u,cs);
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i].fs.fs;
        if(v!=prev && v!=bc)
        {
            //cout<<"gese"<<u<<" "<<v<<" "<<bc<<endl;
            chain++;
            hld(v,u,gr[u][i].fs.sc);
        }
    }
    return;
}

void build(int nodes,int b,int e)
{
    if(b==e) tree[nodes]=base[b];
    else
    {
        int m=(b+e)/2;
        build(nodes*2,b,m);
        build(nodes*2+1,m+1,e);
        tree[nodes]=max(tree[nodes*2],tree[nodes*2+1]);
    }
}

int seg_query(int nodes,int b,int e,int i,int j)
{
    if(b>=i && j>=e) return tree[nodes];
    else if(i>e || j<b) return -1;
    int m=(b+e)/2;
    return max( seg_query(nodes*2,b,m,i,j), seg_query(nodes*2+1,m+1,e,i,j) );
}

void update(int nodes,int b,int e,int i,int val)
{
    if(b==e && e==i) {tree[nodes]=val;return;}
    int m=(b+e)/2;
    if(i<=m) update(nodes*2,b,m,i,val);
    else update(nodes*2+1,m+1,e,i,val);
    tree[nodes]=max(tree[nodes*2],tree[nodes*2+1]);
    return;
}

int queryUp(int x,int v)///v=lca
{
    if(x==v) return 0;
    int mx=-1;
    while(1)
    {
        if(chainNo[x]==chainNo[v])
        {
            if(x==v) return mx;
            return max(mx,seg_query(1,1,ptr,posBase[v]+1,posBase[x]));
        }
        mx=max(mx,seg_query(1,1,ptr,posBase[ chainHead[ chainNo[x] ] ],posBase[x]));
        x=table[chainHead[ chainNo[x] ] ][0];
    }
    return mx;
}


int query(int x,int y)
{
    int v= lca_query(x,y);
    return max(queryUp(x,v),queryUp(y,v));
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            gr[i].clear();
            chainHead[i]=-1;
            level[i]=-1;
            for(int j=0; j<ln; j++) table[i][j]=-1;
        }
        for(int i=1; i<n; i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            gr[x].pb({{y,w},i});
            gr[y].pb({{x,w},i});
        }

        /*for(int i=1;i<=n;i++)
        {
            cout<<i<<":";
            for(int j=0;j<gr[i].size();j++)
            {
                cout<<" "<<gr[i][j].fs.fs;
            }
            cout<<endl;
        }*/

        level[1]=0;
        dfs(1);

        for(int j=1; j<ln ; j++)
        {
            for(int i=1; i<=n; i++)
            {
                if(table[i][j-1]!=-1)
                {
                    table[i][j]=table[table[i][j-1]][j-1];
                }
            }
        }

        ptr=-1;
        chain=1;
        hld(1,0,0);
        //ptr--;
        //cout<<"ptr = "<<ptr<<endl;
        //for(int i=0;i<6;i++) cout<<" "<<base[i]; cout<<endl;
        //for(int i=1;i<=n;i++) cout<<" "<<posBase[i]; cout<<endl;
        //for(int i=1;i<=n;i++) cout<<" "<<chainNo[i]; cout<<endl;
        //cout<<"no of chains "<<chain<<endl;
        build(1,1,ptr);

        char s[10];
        while(scanf("%s",s))
        {
            if(strcmp(s,"DONE")==0) break;
            if(strcmp(s,"QUERY")==0)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%d\n",query(x,y));
            }
            else
            {
                int x,val;
                scanf("%d%d",&x,&val);
                x=posBase[ indexx[x] ];
                update(1,1,ptr,x,val);
            }
        }
    }
    return 0;
}

