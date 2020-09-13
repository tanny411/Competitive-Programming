#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

vector<int> Centroid(const vector<vector<int>> &g) {
        int n = g.size();
        vector<int> centroid;
        vector<int> sz(n);
        function<void (int, int)> dfs = [&](int u, int prev) {
                sz[u] = 1;
                bool is_centroid = true;
                for (auto v : g[u]) if (v != prev) {
                        dfs(v, u);
                        sz[u] += sz[v];
                        if (sz[v] > n / 2) is_centroid = false;
                }
                if (n - sz[u] > n / 2) is_centroid = false;
                if (is_centroid) centroid.push_back(u);
        };
        dfs(0, -1);
        return centroid;
}

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>v(n);
        for(int i=1;i<n;i++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            v[x].pb(y);
            v[y].pb(x);
        }
        vector<int>cent = Centroid(v);
        if(cent.size()==1){
            int c = cent[0];
            cout<<v[c][0]+1<<" "<<c+1<<endl;
            cout<<v[c][0]+1<<" "<<c+1<<endl;
        }
        else{
            int c1 = cent[0];
            int c2 = cent[1];
            int x = v[c1][0];
            if(x==c2) x = v[c1][1];
            cout<<c1+1<<" "<<x+1<<endl;
            cout<<c2+1<<" "<<x+1<<endl;
        }
    }

    

    return 0;
}