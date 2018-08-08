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

#define maxnode 10000+7
vector<int>gr[maxnode];
vector<int>arti(maxnode),low(maxnode),disc(maxnode,-1);///true if is an articulation point
int t=0;

void dfs(int p,int u)
{
    disc[u]=low[u]=++t;
    int child=0;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v==p) continue;
        if(disc[v]==-1)
        {
            dfs(u,v);
            low[u]=min(low[u],low[v]);
            if(p!=-1 && disc[u]<=low[v]) arti[u]=1;
            child++;
        }
        else
        {
            low[u]=min(low[u],disc[v]);
        }
    }
    if(p==-1 && child>1) arti[u]=1;
}

void ArticulationPoint(int n)
{
    /*
    Do necessary init and clear
    */
    for(int i=0;i<n+3;i++)
    {
        arti[i]=low[i]=0;
        disc[i]=-1;
    }

    for(int i=0;i<n;i++)
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

    ArticulationPoint(n);
    for(int i=0;i<n;i++) if(arti[i]) cout<<" "<<i;
    return 0;
}

