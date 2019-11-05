#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    unordered_map<int,int>mp;
    int ans=0;
    while(k--){
        string s;
        cin>>s;
        if(s=="CLICK"){
            int x;
            cin>>x;
            if(mp[x]==0) mp[x]=1,ans++;
            else mp[x]=0,ans--;
        }
        else mp.clear(),ans=0;
        cout<<ans<<endl;
    }

    return 0;
}