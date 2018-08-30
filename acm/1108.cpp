#include<bits/stdc++.h>
#define fs first
#define sc second
#define pb push_back
using namespace std;
vector<int>gr[1003],flag,dist;

void dfs(int u){
    if(flag[u]) return ;
    flag[u]=1;
    for(int i=0;i<gr[u].size();i++){
        if(!flag[gr[u][i]]) dfs(gr[u][i]);
    }
}

int main()
{
    const int mx=100000;
    int t;
    cin>>t;
    int test=1;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++){
            gr[i].clear();
        }
        flag=vector<int>(n+3);
        dist=vector<int>(n+3);///initialized with 0 to find all cycles simultaneously
        vector<pair< pair< int,int>,int > >edge;
        for(int i=0;i<m;i++){
            int x,y,w;
            cin>>y>>x>>w;
            gr[x].pb(y);
            edge.pb({{x,y},w});
        }

        ///bellman ford
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cost=edge[j].sc;
                int u=edge[j].fs.fs;
                int v=edge[j].fs.sc;
                if(i<n-1){
                    if(dist[v]>dist[u]+cost) dist[v]=dist[u]+cost;
                }
                else{
                    if(dist[v]>dist[u]+cost) dfs(u),dfs(v);
                }
            }
        }
        cout<<"Case "<<test++<<":";
        int cnt=0;
        for(int i=0;i<n;i++){
            if(flag[i]) cout<<" "<<i,cnt++;
        }
        if(cnt==0) cout<<" impossible";
        cout<<endl;
    }
    return 0;
}
