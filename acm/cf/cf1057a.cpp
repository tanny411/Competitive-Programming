#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

vector<int> graph[200003];
int parent[200003];

void dfs(int u, int p){
    parent[u]=p;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        dfs(v, u);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++) {
        int x;
        cin>>x;
        graph[x].pb(i);
    }
    dfs(1, -1);
    vector<int>v;
    int node=n;
    while(node!=-1){
        v.push_back(node);
        node = parent[node];
    }
    for(int i=v.size()-1;i>=0;i--){
        cout<<v[i];
        if(i) cout<<" ";
    }
    return 0;
}