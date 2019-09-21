#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

///WA
int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll od=n/2;
        ll ans=-1;
        if(n==1) ans=m<=1;
        else if(n==2){
            if(m==1) ans=1;
            else if(m==2 || m==3) ans=2;
            else ans=-1;
        }
        else if(m<n-1) ans=-1;
        else if(m<=n+1) ans=2;
        else if(m<=n+n) ans=3;
        else if(m>(n*(n+1))/2) ans=-1;
        else if(!n&1) ans=ceil((2.0*m)/n - 1.0);
        else ans = ceil((m-n-n)/(od*1.0)) + 3;
        cout<<ans<<endl;
    }

    return 0;
}