#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
//WA
int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int ans;
        //put a row of knights
        if(n==1||m==1) ans=m*n;
        else if(n==2||m==2){
            ans=4*(m/6);
            m%=6;
            if(m==0);
            else if(m==1) ans+=2;
            else ans+=4;
        }
        else{//n==3
            if(m==3) ans=4;
            else ans=m;  
        }
        cout<<ans<<endl;
    }

    return 0;
}