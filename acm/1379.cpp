#include<bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
using namespace std;
void dijkstra(vector<int> &dist,vector<vector<pii> > &gr,int s){
    dist[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> >pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u=pq.top().sc;
        int w=pq.top().fs;
        pq.pop();
        if(dist[u]<w) continue;
        for(int i=0;i<gr[u].size();i++){
            int v=gr[u][i].fs;
            int wt=gr[u][i].sc;
            if(dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
                pq.push({dist[v],v});
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        int n,m,s,d,p;
        cin>>n>>m>>s>>d>>p;
        vector<int>dist_s(n+1,1<<30),dist_d(n+1,1<<30);
        vector<vector<pii> >gr(n+1),rev(n+1);
        while(m--){
            int x,y,w;
            cin>>x>>y>>w;
            gr[x].pb({y,w});
            rev[y].pb({x,w});
        }
        dijkstra(dist_s,gr,s);
        dijkstra(dist_d,rev,d);
        //cout<<dist_s[1]<<" "<<dist_d[1]<<endl;
        int mx=-1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<gr[i].size();j++){
                int v=gr[i][j].fs;
                int w=gr[i][j].sc;
                if(dist_s[i]!=1<<30 && dist_d[v]!=1<<30 && dist_s[i]+dist_d[v]+w<=p) mx=max(mx,w);
            }
        }
        cout<<"Case "<<test<<": "<<mx<<endl;
    }
    return 0;
}
/**
2
9 15 1 9 100
1 3 13
1 2 30
2 3 15
3 2 76
2 4 53
3 5 29
5 4 61
4 5 23
4 7 11
6 8 42
6 7 30
5 7 7
2 6 49
8 9 77
7 9 5

5 9 2 3 141
3 2 49
2 4 3
5 2 48
2 5 24
4 5 25
5 3 41
1 3 40
5 3 38
2 5 12
ans:53 48
*/
