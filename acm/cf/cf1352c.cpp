#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int up = k/(n-1);
        if((up*n - up)==k) up--;
        k -= (up*n - up);
        cout<<up*n+k<<endl;
    }

    return 0;
}