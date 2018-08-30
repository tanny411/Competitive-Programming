#include<bits/stdc++.h>
using namespace std;
vector<int>v,dist,gr[203],flag;

void dfs(int u){
    if(flag[u]) return ;
    flag[u]=1;
    for(int i=0;i<gr[u].size();i++){
        if(!flag[gr[u][i]]) dfs(gr[u][i]);
    }
    return;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int t,test=1;
    const int mx=100000;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        v=vector<int>(n+1,0);
        flag=vector<int>(n+1,0);
        dist=vector<int>(n+1,mx);
        vector< pair <int, pair <int,int> > >edge;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            gr[i].clear();
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            gr[x].push_back(y);
            edge.push_back({(v[y]-v[x])*(v[y]-v[x])*(v[y]-v[x]),{x,y}});
        }
        dist[1]=0;
        for(int i=0;i<n-1;i++){
            for(int i=0;i<m;i++){
                int cost=edge[i].first;
                int u=edge[i].second.first;
                int v=edge[i].second.second;
                if(dist[u]!=mx && dist[v]>dist[u]+cost) dist[v]=dist[u]+cost;
            }
        }
        for(int i=0;i<m;i++){
            int cost=edge[i].first;
            int u=edge[i].second.first;
            int v=edge[i].second.second;
            if(dist[v]>dist[u]+cost) {
                //dfs(v);
                //dfs(u);
                flag[u]=flag[v]=1;
            }
        }
//        cout<<"distances"<<endl;
//        for(int i=1;i<=n;i++){
//            cout<<i<<" "<<dist[i]<<endl;
//        }
        int q;
        cin>>q;
        cout<<"Case "<<test++<<":\n";
        while(q--){
            int x;
            cin>>x;
            if(dist[x]<3 || dist[x]==mx || flag[x]) cout<<"?\n";
            else cout<<dist[x]<<endl;
        }
    }
    return 0;
}
/**
2

5
6 7 8 9 10
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5

2
10 10
1
1 2
1
2
*/
/**
1

4
10 12 15 14
2
1 2
3 4
4
1
2
3
4
*/
/**
1

5
1 17 9 17 15
3
1 2
3 2
5 4
4
2
3
4
5
*/
/**
15
1 8 7 7 3 9 10 6 1 9 8 3 6 4 6
27
1 13
1 14
1 1
1 2
1 12
1 15
1 3
1 4
1 8
1 10
1 7
2 1
2 14
6 15
6 14
6 3
11 2
11 9
11 4
7 6
9 3
9 14
14 3
8 15
5 8
13 3
15 15
6
1
11
12
11
7
3
ans:
?
?
8
?
729
54
*/
