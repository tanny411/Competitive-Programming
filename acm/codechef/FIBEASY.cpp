#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int f[302];
    f[0]=0;f[1]=1;
    for(int i=2;i<300;i++){
        f[i]=(f[i-1]+f[i-2])%10;
    }
    cin>>t;
    while(t--){
        ll n,lg=0,uh=1;
        cin>>n;
        while(n>>=1){
            lg++;
        }
        // cout<<"lg="<<lg<<" ";
        for(int i=0;i<lg;i++){
            uh=(uh*2ll)%300;
        }
        cout<<f[uh-1]<<endl;
    }

    return 0;
}