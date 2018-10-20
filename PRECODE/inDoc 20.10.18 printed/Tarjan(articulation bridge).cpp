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
vector<int>gr[maxnode];
vector<int>disc(maxnode,-1),low(maxnode);
vector<pii>bridge;
int t=0;

void dfs(int p,int u)
{
    disc[u]=low[u]=++t;
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i];
        if(v==p) continue;
        else if(disc[v]==-1)
        {
            dfs(u,v);
            low[u]=min(low[u],low[v]);
            if(disc[u]<low[v]) bridge.pb(pii(u,v));
        }
        else low[u]=min(low[u],disc[v]);
    }
}

void ArticulationBridge(int n)
{
    /*
    Do necessary init and clear
    */
    for(int i=0; i<n+3; i++)
    {
        low[i]=0;
        disc[i]=-1;
    }
    bridge.clear();

    for(int i=0; i<n; i++)
    {
        t=0;
        if(disc[i]==-1) dfs(-1,i);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    /*
    Clear Graph
    */
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    ArticulationBridge(n);
    for(int i=0;i<bridge.size();i++)
    {
        cout<<bridge[i].fs<<" "<<bridge[i].sc<<endl;
    }
    return 0;
}
