#include<bits/stdc++.h>
#define pb push_back

using namespace std;
vector<int>ex(102),pr(102);
int dp[102][1002];
int W,n;
int knapsack(int pos,int rem)
{
    //cout<<pos<<" "<<rem<<endl;
    if(pos==n){
        return (rem>=0)?0:-10000000;
    }
    if(rem==0) return 0;
    if(dp[pos][rem]!=-1) return dp[pos][rem];
    int ret=0;
    if(rem-ex[pos]>=0) ret=pr[pos]+knapsack(pos+1,rem-ex[pos]);
    ret=max(ret,knapsack(pos+1,rem));
    return dp[pos][rem]=ret;
}
int main()
{
    int t,test=1;
    cin>>t;
    while(t--){
        cin>>n>>W;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++) cin>>ex[i]>>pr[i];
        cout<<max(0,knapsack(0,W))<<endl;
    }
    return 0;
}



