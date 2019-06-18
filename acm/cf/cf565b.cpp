#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fs first
#define sc second
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v;
        int ans=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x%3==0) ans++;
            else v.pb(x);
        }
        sort(v.begin(),v.end());
        vector<int>cpy=v,fl(v.size());
        for(int i=0;i<v.size();i++){
            if(fl[i]) continue;
            int x = ceil(v[i]/3.0) * 3 - v[i];
            int y=lower_bound(cpy.begin(), cpy.end(), x)-cpy.begin();
            if(y>=0 && y<cpy.size() && cpy[y]==x){
                ans++;
                cpy.erase(cpy.begin()+i);
                cpy.erase(cpy.begin()+y);
                fl[i]=fl[y]=1;
            }
        }
        v=cpy;
        fl=vector<int>(v.size());
        vector< pair<int,pii> >tw;
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                tw.pb({v[i]+v[j],{i,j}});
            }
        }
        for(int i=0;i<tw.size();i++){
            if(fl[tw[i].sc.fs] || fl[tw[i].sc.sc]) continue;
            int x = ceil(tw[i].fs/3.0) * 3 - tw[i].fs;
            int y=lower_bound(v.begin(), v.end(), x)-v.begin();
            if(y>=0 && y<v.size() && v[y]==x){
                if(y==tw[i].sc.fs || y==tw[i].sc.sc){
                    y++;
                    if(y>=n || v[y]!=x) continue;
                    if(y==tw[i].sc.fs || y==tw[i].sc.sc ){
                        y++;
                        if(y>=n || v[y]!=x) continue;
                    }
                }
                ans++;
                v.erase(v.begin()+y);
                fl[tw[i].sc.fs]=fl[tw[i].sc.sc]=fl[y]=1;
            }         
        }
        cout<<ans<<endl;
    }
    return 0;
}