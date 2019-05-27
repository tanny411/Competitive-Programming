#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) { cin>>v[i]; v[i]=abs(v[i]);}
    sort(v.begin(),v.end());
    ll ans=0;
    for(int i=0;i<n;i++){
        int in=upper_bound(v.begin(),v.end(),2*v[i])-v.begin()-1;
        ans+=(ll)max(in-i,0);
    }
    cout<<ans<<endl;
    return 0;
}