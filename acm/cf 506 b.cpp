#include<bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second
#define CIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<int>gr[200002],flag(200006);

int dfs(int u,int d){
    flag[u]=1;
    int mx=d;
    for(int i=0;i<gr[u].size();i++){
        int v=gr[u][i];
        if(flag[v]==0) mx=max(mx,dfs(v,v-u+d));
    }
    //cout<<u<<" "<<mx<<endl;
    return mx;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    for(int i=0;i<n;i++){
        int in=upper_bound(v.begin(),v.end(),v[i]*2)-v.begin();
        in--;
        if(in>i) gr[i].push_back(in);
    }
    int mx=1;
    for(int i=0;i<n;i++){
        if(flag[i]==0) mx=max(mx,dfs(i,1));
    }
    cout<<mx<<endl;
    return 0;
}
