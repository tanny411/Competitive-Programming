#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end());
    if(v[n-1]<v[n-2]+v[n-3]) {
        cout<<"YES\n";
        swap(v[n-1],v[n-2]);
        for(int i=0;i<n;i++) cout<<v[i]<<" ";
    }
    else cout<<"NO\n";

    return 0;
}