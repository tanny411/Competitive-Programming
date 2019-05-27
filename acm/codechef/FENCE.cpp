#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fs first
#define sc second
using namespace std;
map<pii,int>mp;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int n,m;
int dfs(int r,int c){
    // cout<<"ashche "<<r<<" "<<c<<endl;
    if(mp.find(pii(r,c))==mp.end()) return 1;
    if(mp[pii(r,c)]==0) return 0;
    mp[pii(r,c)]=0;
    int fence=0;
    for (int i=0;i<4;i++){
        int x=r+dx[i];
        int y=c+dy[i];
        // if(x<=0 || y<=0 || x>n || y>m) fence++;
        // else 
        fence+=dfs(x,y);
    }
    return fence;
}
int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        mp.clear();
        int k,node=1;
        cin>>n>>m>>k;
        for(int i=0;i<k;i++){
            int r,c;
            cin>>r>>c;
            mp[pii(r,c)]=1;
        }
        int fence=0;
        for(auto i=mp.begin();i!=mp.end();i++){
            int r=(i->fs).fs;
            int c=(i->fs).sc;
            int v=i->sc;
            if(v==0) continue;
            fence+=dfs(r,c);
        }
        cout<<fence<<endl;
    }

    return 0;
}