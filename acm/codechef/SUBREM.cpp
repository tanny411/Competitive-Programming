#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
vector<int>gr[100010];
vector<ll>a(100010);
ll X;

ll dfs(int u,int p=-1){
    for(int i=0;i<gr[u].size();i++){
        int v=gr[u][i];
        if(v==p) continue;
        a[u]+=dfs(v,u);
    }
    return max(-X,a[u]);
}

int main(){
    ios_base::sync_with_stdio(0);
    int cas=1,t;
    cin>>t;
    while(t--){
        int n;
        cin>>n>>X;
        for(int i=1;i<=n;i++) cin>>a[i] , gr[i].clear();
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            gr[x].pb(y);
            gr[y].pb(x);
        }
        cout<<dfs(1)<<endl;
    }

    return 0;
}