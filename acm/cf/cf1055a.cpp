#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
int n,d;
vector<int> graph[1003];
int a[1003], b[1003], flag[1003];

void dfs(int u){
    if(flag[u]) return;
    flag[u]=1;
    if(flag[d-1]) return;
    for(int i=0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(!flag[v]) dfs(v);
    }
}


int main(){
    cin>>n>>d;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    int first=n;
    for(int i=0;i<n;i++) if(a[i]) {first=i; break;}
    for(int i=first+1; i<n; i++){
        if(a[i]){
            graph[first].pb(i);
            first=i;
        }
    }

    first=-1;
    for(int i=n-1;i>=0;i--) if(b[i]) {first=i; break;}
    for(int i=first-1;i>=0;i--){
        if(b[i]){
            graph[first].pb(i);
            first=i;
        }
    }
    dfs(0);
    if(flag[d-1]) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}