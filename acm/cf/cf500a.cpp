#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
int n,d;
vector<int>graph[30003];
int flag[30003];

void dfs(int u){
    if(flag[u]) return;
    if(flag[d]) return;
    flag[u]=1;
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!flag[v]) dfs(v);
    }
}

int main(){
    cin>>n>>d;
    for(int i=1;i<n;i++){
        int a;
        cin>>a;
        graph[i].pb(i+a);
    }
    dfs(1);
    if(flag[d]) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}