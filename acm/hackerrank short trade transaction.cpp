#include <bits/stdc++.h>

using namespace std;

int dp[102][102][102];

int short_trade(int prev,int rem, int m) {

    //cout<<prev<<" "<<rem<<" "<<m<<endl;
    if(m==0) return (rem==0);
    if(dp[prev][rem][m]!=-1) return dp[prev][rem][m];
    int ret=0;
    int de=max(0,min(rem,prev-1));
    for(int i=0;i<=de;i++){
        ret+=short_trade(i,rem-i,m-1);
    }
    return dp[prev][rem][m]=ret;
}

int main() {
    int t;
    cin >> t;
    memset(dp,-1,sizeof dp);
    for(int a0 = 0; a0 < t; a0++){
        int a;
        int m;
        cin >> a >> m;
        int x = short_trade(101,a, m);
        cout << x << endl;
    }
    return 0;
}
