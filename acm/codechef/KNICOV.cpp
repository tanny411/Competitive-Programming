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
        //put a row of knights
        if(n==1||m==1) cout<<m*n<<endl;
        else if(n==2||m==2){
            if(n<m) swap(n,m);
            int ans=(m/6)*4+((m%6)?(m%6==1?2:4):0);
            ans=min(ans,m);
            cout<<ans<<endl;
        }
        else{//n==3
            int ans=(m/5)*5;
            int d=m%5;
            if(d==1) ans+=3;
            else if(d<=3) ans+=4;
            else if(d==4) ans+=5;
            ans=min(ans,m);
            cout<<ans<<endl;
        }
    }

    return 0;
}