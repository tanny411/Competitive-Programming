#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int dp[100010], n;
vector<int>v;

//It's not LIS though, its longest increasing(non-decreasing) SUBSEGMENT
//NOT subsequence

int LIS(int pos){
    if(dp[pos]!=-1) return dp[pos];
    dp[pos]=1;
    if(v[pos+1]>=v[pos]) {
        dp[pos] = LIS(pos+1)+1; 
    }
    return dp[pos];
}

int main(){
    cin>>n;
    v = vector<int>(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        dp[i]=-1;
    }
    dp[n-1] = 1;
    int mx = 0;
    for (int i=0;i<n;i++){
        int lis = LIS(i);
        mx = max(mx, lis);
        // cout<<lis<<endl;
    }
    cout<<mx<<endl;
    return 0;
}