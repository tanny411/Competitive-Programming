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
vector<int>vis;
int t=0;

void dfs(int p,int u)
{
    disc[u]=low[u]=++t;
    vis.pb(u);
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

int ArticulationBridge(int n)
{
    int cnt=0;
    for(int i=0; i<n+3; i++)
    {
        low[i]=0;
        disc[i]=-1;
    }

    for(int i=0; i<n; i++)
    {
        t=0;
        if(disc[i]==-1) {
            bridge.clear();
            vis.clear();
            dfs(-1,i);
            int sz=vis.size();
            if(sz%2==0)
            {
                for(int j=0;j<bridge.size();j++){
                    int oy=1;
                    for(int i=0;i<sz;i++)
                    {
                        int x=gr[vis[i]].size();
                        if(vis[i]==bridge[j].fs || vis[i]==bridge[j].sc) x--;
                        if(x!=(sz/2)-1) {oy=0; break;}
                    }
                    if(oy) cnt++;
                }
            }
        }
    }
    return cnt;
}

int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        for(int i=0;i<=n;i++) gr[i].clear();

        while(m--)
        {
            int x,y;
            cin>>x>>y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        int x=ArticulationBridge(n);
        cout<<"Case #"<<test++<<": "<<x<<endl;
    }
    return 0;
}
