#include<bits/stdc++.h>
#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pb push_back
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    const int mx=1000000000;
    for(int test=1;test<=t;test++)
    {
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        vector<vector<int> >dist(n,vector<int>(d+2,mx));
        vector<ppi>gr[n+3];
        while(m--){
            int x,y,w;
            cin>>x>>y>>w;
            gr[x].pb({{y,w},0});
        }
        while(k--){
            int x,y,w;
            cin>>x>>y>>w;
            gr[x].pb({{y,w},1});
        }
        priority_queue<pip,vector<pip>,greater<pip> >pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});///{weight,{node,#of proposed roads taken}}
        while(!pq.empty()){
            int u=pq.top().sc.fs;
            int r=pq.top().sc.sc;
            int wt=pq.top().fs;
            pq.pop();
            if(dist[u][r]<wt) continue;
            //cout<<u<<endl;
            for(int i=0;i<gr[u].size();i++){
                int v=gr[u][i].fs.fs;
                int w=gr[u][i].fs.sc;
                int tp=gr[u][i].sc;
                if(r+tp<=d && dist[v][r+tp]>dist[u][r]+w){
                    dist[v][r+tp]=dist[u][r]+w;
                    pq.push({dist[v][r+tp],{v,r+tp}});
                }
            }
        }
        int ans=mx;
        for(int i=0;i<=d;i++){
            ans=min(ans,dist[n-1][i]);
        }
        cout<<"Case "<<test<<": ";
        if(ans==mx) cout<<"Impossible\n";
        else cout<<ans<<endl;
    }
    return 0;
}
/**
1

7 5 4 1
0 1 10
1 2 5
3 4 12
4 5 14
4 6 2
0 6 100
0 2 5
2 3 7
5 6 9

ans:36;
*/
