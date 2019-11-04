#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        ll n,m,q;
        cin>>n>>m>>q;
        vector<bool>row(n+1,0),col(m+1,0);
        while(q--){
            int x,y;
            cin>>x>>y;
            row[x]=!row[x];
            col[y]=!col[y];
        }
        ll r=0,c=0;
        for(int i=1;i<n+1;i++) r+=row[i];
        for(int i=1;i<m+1;i++) c+=col[i];
        cout<<r*(m-c)+c*(n-r)<<endl;
    }

    return 0;
}