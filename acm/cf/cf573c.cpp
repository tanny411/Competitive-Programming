#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll>v(m);
    for(ll i=0;i<m;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    auto it = v.begin();
    ll jao=k;
    ll cnt=0;
    ll flag=1;
    ll po=9;

    while(flag){
        // cout<<"jao: "<<jao<<endl;
        if(jao>n) jao=n,flag=0;

        auto in  = upper_bound(it,v.end(),jao);
        ll idx = in-it;
        // cout<<"idx: "<<idx<<endl;
 
        it=in;
        if(idx>0) jao+=idx,cnt++;
        else {
            ll so=in-v.begin();
            if(so==m) break;
            jao+=ceil((v[so]*1.0-jao)/k)*k;
        }
    }

    cout<<cnt<<endl;
    
    return 0;
}