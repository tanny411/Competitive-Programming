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
        vector<ll>a(n),b(n);
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];
        ll mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,max(a[i]*20-b[i]*10,0ll));
        }
        cout<<mx<<endl;
    }

    return 0;
}