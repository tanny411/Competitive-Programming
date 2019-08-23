#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll nn = n/k;
        if(nn%k==0) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}