#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    // cout<<log10(1ll<<62)<<endl;
    int n,m;
    cin>>n>>m;
    vector<ll>dorm(n), lett(m);
    for(int i=0;i<n;i++) cin>>dorm[i];
    for(int i=0;i<m;i++) cin>>lett[i];
    ll present_dorm = 1;
    ll present_dorm_limit = dorm[0];
    ll subtract = 0;
    for(int i=0;i<m;i++){
        while(lett[i]>present_dorm_limit){
            present_dorm++;
            subtract = present_dorm_limit;
            present_dorm_limit += dorm[present_dorm-1];
        }
        cout<<present_dorm<<" "<<lett[i]-subtract<<endl;
    }

    return 0;
}