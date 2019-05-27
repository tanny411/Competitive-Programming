#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){

    ll x;
    cin>>x;

    int t=0;
    vector<int>v;
    while(1){
        
        int last=-1,pos=0;
        ll tx=x;
        while(tx){
            if(tx&1);
            else last=pos;
            pos++;
            tx/=2;
        }
        
        if(last==-1) break;
        
        if(t&1) {x++; t++; continue;}

        ll two=2;
        v.pb(last+1);
        while(last--) two*=2;
        two--;

        x^=two;
        t++;
        // cout<<x<<endl;
    }
    cout<<t<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}