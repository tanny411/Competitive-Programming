#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define sc second
#define fs first
using namespace std;
//NOPE
int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>d(n),c(n);
        vector<pii>p(n);
        for(int i=0;i<n;i++) cin>>d[i];
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++) p[i]=pii(d[i],c[i]);
        sort(p.begin(),p.end());
        ll ans=0;
        map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            if(mp.find(p[i].sc)==mp.end()){
                mp[p[i].sc]=1;
                ans+=2*p[i].fs;
            }
        }
        ans-=p[n-1].sc;
        cout<<"Case #"<<cas++<<": "<<ans<<endl;
    }
    return 0;
}