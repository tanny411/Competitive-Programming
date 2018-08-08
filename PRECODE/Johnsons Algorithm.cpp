#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int n,m;
vector<pii>gr[1000];
int h[1000];
int bellman_ford(int s)
{
    for(int i=0; i<=n; i++) h[i]=0;
    int x=n-1;
    while(x--)
    {
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<gr[i].size(); j++)
            {
                int v=gr[i][j].fs;
                if(h[v]>h[i]+gr[i][j].sc) h[v]=h[i]+gr[i][j].sc;
            }
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<gr[i].size(); j++)
        {
            int v=gr[i][j].fs;
            if(h[v]>h[i]+gr[i][j].sc) return 0;
        }
    }
    return 1;
}
void reweight()
{
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<gr[i].size(); j++)
        {
            gr[i][j].sc+=h[i]-h[gr[i][j].fs];
        }
    }
}
int dist[1000][1000];
void dijkstra(int s)
{
    int vis[n+2];
    memset(vis,0,sizeof vis);
    for(int i=1; i<=n; i++) dist[s][i]=1<<30;
    dist[s][s]=0;
    priority_queue<pii,vector<pii>,greater<pii> >q;
    q.push(pii(0,s));
    while(!q.empty())
    {
        int u=q.top().sc;
        q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(int i=0; i<gr[u].size(); i++)
        {
            int v=gr[u][i].fs;
            if(dist[s][v]>dist[s][u]+gr[u][i].sc)
            {
                dist[s][v]=dist[s][u]+gr[u][i].sc;
                q.push(pii(dist[s][v],v));
            }
        }
    }

}
int main()
{
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {
        if(cas>1) cout<<endl;
        cin>>n>>m;
        for(int i=0; i<=n; i++) gr[i].clear();
        while(m--)
        {
            int x,y,z;
            cin>>x>>y>>z;
            gr[x].pb(pii(y,z));
        }
        ///adding dummy node
        for(int i=1; i<=n; i++) gr[0].pb(pii(i,0));
        if(!bellman_ford(0)) cout<<"graph "<<cas++<<" no\n";
        else
        {
            cout<<"graph "<<cas++<<" yes\n\n";
            reweight();
            for(int i=1; i<=n; i++) dijkstra(i);
        for(int i=1;i<=n;i++)
        {
            cout<<h[i]<<" ";
        }
        cout<<h[0]<<endl<<endl;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]!=1<<30) dist[i][j]+=h[j]-h[i];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j>1) cout<<" ";
                if(dist[i][j]==1<<30) cout<<"#";
                else cout<<dist[i][j];
            }
            cout<<endl;
        }
        }

    }
    return 0;
}

