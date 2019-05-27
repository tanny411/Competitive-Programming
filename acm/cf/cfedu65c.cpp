#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
int root[500003];
int p(int x){
    if(root[x]==x) return x;
    else return root[x]=p(root[x]);
}
int main(){
    int n,m;
    cin>>n>>m;
    int numppl[m+3];
    vector<int>v[m+3];
    int mp[n+3];
    memset(mp, 0 , sizeof mp);
    for(int i=1;i<=m;i++) root[i]=i;
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        numppl[i]=k;
        while(k--){
            int x;
            cin>>x;
            v[i].pb(x);
            if(mp[x]==0) mp[x]=i;
            else {
                int a=p(mp[x]);
                int b=p(i);
                root[a]=b;
            }
        }
    }
    set<int>par[m+3];
    for(int i=1;i<=m;i++){
        int a=p(i);
        for(int j=0;j<numppl[i];j++){
            par[a].insert(v[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        int gr=mp[i];
        int a=p(gr);
        cout<<max((int)par[a].size(),1)<<" ";
    }
    return 0;
}