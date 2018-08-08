#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

///Edmond-Karp
///loj 1177

vector<int>gr[1000],parent(1000);
ll cap[1000][1000];
int n;
void clr(int z)
{
    z+=2;
    for(int i=0; i<=2*z; i++) gr[i].clear();
    for(int i=0; i<=2*z; i++)
    {
        for(int j=0; j<=2*z; j++)
        {
            cap[i][j]=0;
        }
    }
}

ll bfs(int s,int d)
{
    vector<ll>capacity(2*n+3);
    queue<int>q;
    q.push(s);
    capacity[s]=1<<30;
    parent[s]=-2;///visited
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<gr[u].size();i++)
        {
            int v=gr[u][i];
            if(cap[u][v]>0 && parent[v]==-1)
            {
                capacity[v]=min(capacity[u],cap[u][v]);
                parent[v]=u;
                if(v==d) return capacity[v];
                q.push(v);
            }
        }
    }
    return 0;
}

ll maxflow(int s,int d)
{
    ll flow=0;
    while(1)
    {
        for(int i=0;i<=2*n+3;i++) parent[i]=-1;
        int fl=bfs(s,d);
        if(fl==0) return flow;
        flow+=(ll)fl;
        int v=d;
        while(parent[v]!=-2)
        {
            int u=parent[v];
            cap[u][v]-=fl;
            cap[v][u]+=fl;
            v=u;
        }
    }
}

int main()
{
    ///nodes and edges both have weights
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>n>>m;
        clr(n);
        ///1 is source, n is destination
        ///the nodes in between have weights
        for(int i=2; i<n; i++)
        {
            int w;
            cin>>w;
            cap[i][i+n]=w;
            gr[i].pb(i+n);
            gr[i+n].pb(i);
        }

        cap[1][1+n]=1<<30;
        gr[1].pb(1+n);
        gr[1+n].pb(1);

        cap[n][n+n]=1<<30;
        gr[n].pb(n+n);
        gr[n+n].pb(n);

        for(int i=0;i<m;i++)
        {
            int x,y,w;
            cin>>x>>y>>w;

            cap[x+n][y]=w;
            cap[y+n][x]=w;

            gr[x+n].pb(y);
            gr[y].pb(x+n);
            gr[y+n].pb(x);
            gr[x].pb(y+n);
        }
        cout<<"Case "<<cas++<<": "<<maxflow(1,n+n)<<endl;
        /*for(int i=1;i<=2*n;i++)
        {
            cout<<i<<" :"<<endl;
            for(int j=0;j<gr[i].size();j++)
            {
                cout<<" "<<gr[i][j];
            }
            cout<<endl;
        }*/
    }
    return 0;
}
