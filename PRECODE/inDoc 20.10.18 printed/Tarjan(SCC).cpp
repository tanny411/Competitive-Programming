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
using namespace std;

#define maxnode 1000
vector<int>gr[maxnode],disc(maxnode),low(maxnode),scc(maxnode),stk(maxnode);///all nodes in an scc will be marked similar value;
int t=0,sccno=0;
stack<int>s;

void dfs_scc(int p,int u)
{
    disc[u]=low[u]=++t;
    s.push(u);
    stk[u]=1;

    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(disc[v]==-1)
        {
            dfs_scc(u,v);
            low[u]=min(low[u],low[v]);
        }
        else if(stk[v]==1) low[u]=min(low[u],disc[v]);///if back-edge
    }
    if(low[u]==disc[u])
    {
        ++sccno;
        while(1)
        {
            int x=s.top();
            s.pop();
            scc[x]=sccno;
            stk[u]=2;///cross-edge now
            if(x==u) break;
        }
    }
}

void SCC(int n)
{
    /*
    Do necessary init and clear
    */
    for(int i=0;i<n+3;i++)
    {
        scc[i]=stk[i]=low[i]=0;
        disc[i]=-1;
    }

    sccno=0;
    for(int i=0;i<n;i++)
    {
        t=0;
        if(disc[i]==-1) dfs_scc(-1,i);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
    }
    SCC(n);
    for(int i=1;i<=sccno;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(scc[j]==i) cout<<" "<<j;
        }
        cout<<endl;
    }
}
