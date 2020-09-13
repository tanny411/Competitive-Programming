#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.rbegin(), v.rend());
        
        ll prod = v[0]*v[1]*v[2]*v[3]*v[4];

        ll val = v[0]*v[1]*v[2]*v[n-1]*v[n-2];
        prod = max(prod, val);

        val = v[0]*v[n-1]*v[n-2]*v[n-3]*v[n-4];
        prod = max(prod, val);

        cout<<prod<<endl;
    }

    return 0;
}