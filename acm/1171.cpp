//Hopcraft
#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fs first
#define sc second
#define NIL 0
#define INF (1<<28)
#define MAX 40004
using namespace std;
int dx[]={-2,-2,2,2,1,1,-1,-1};
int dy[]={-1,1,-1,1,-2,2,-2,2};
int mp[201][201],st,n,m,k;
vector<int>gr[MAX];
int match[MAX], dist[MAX];
bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<st; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = gr[u].size();
            for(i=0; i<len; i++) {
                v = gr[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}
bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = gr[u].size();
        for(i=0; i<len; i++) {
            v = gr[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}
int hopcroft() {
    int matching = 0, i;
    memset(match,0,sizeof match);
    while(bfs())
        for(i=1; i<st; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}
bool inside(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;

        for(int i=0;i<=n*m;i++) gr[i].clear();
        memset(mp,0,sizeof mp);

        for(int i=0;i<k;i++)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            mp[x][y]=-1;
        }
        st=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mp[i][j]==0) mp[i][j]=st++;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]==-1) continue;
                for(int z=0;z<8;z++)
                {
                    int x=i+dx[z];
                    int y=j+dy[z];
                    if(inside(x,y) && mp[x][y]!=-1)
                    {
                        gr[mp[i][j]].pb(mp[x][y]);
                    }
                }
            }
        }
        cout<<"Case "<<test++<<": "<<(n*m)-k-hopcroft()<<endl;
    }
    return 0;
}

