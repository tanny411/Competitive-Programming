#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define md 1000000007
using namespace std;
unordered_map<int,int>mp;
vector<int>v;
vector<vector<ll>>dp;
int n,k;

ll rec(int pos,int koyta){
    if(pos==v.size()||koyta==k){
        if(koyta<=k) return 1;
        else return 0;
    }
    ll &ret=dp[pos][koyta];
    if(ret!=-1) return ret;
    ret=rec(pos+1,koyta);
    ret=(ret+(v[pos]*rec(pos+1,koyta+1))%md)%md;
    return ret;
}

int main(){
    int cas=1,t;

    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x]++;
    }
    for (auto i=mp.begin();i!=mp.end();i++) v.pb(i->second);
    dp=vector<vector<ll> >(v.size(),vector<ll>(k,-1));

    cout<<rec(0,0)<<endl;
    return 0;
}