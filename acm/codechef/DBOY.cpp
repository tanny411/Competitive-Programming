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
        vector<int>k(n),h(n);
        //k is coins/fuel places
        //h is distance/amount
        int mx=0;
        for(int i=0;i<n;i++) cin>>h[i],h[i]+=h[i],mx=max(mx,h[i]);
        vector<int>dp(mx+4,1<<30);
        for(int i=0;i<n;i++) cin>>k[i];
        sort(k.begin(),k.end());
        dp[0]=0;
        for(int i=1;i<=mx;i++){
            // cout<<i<<"--";
            for(int c=0;c<n;c++){
                if(i-k[c]<0) break;
                dp[i]=min(dp[i],dp[i-k[c]]+1);
                // cout<<" "<<dp[i-k[c]];
            }
            // cout<<"---"<<dp[i]<<"\n";
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=dp[h[i]];
            // cout<<h[i]<<" "<<dp[h[i]]<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}