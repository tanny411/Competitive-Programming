#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
vector<int>ara;
int k;
ll nCr(ll n,ll r){
    r=min(r,n-r);
    ll ret=1;
    ll den=1;
    for(ll i=1;i<=r;i++,n--){
        ret*=n;
        den*=i;
        if(ret%den==0) ret/=den,den=1;
    }
    return ret/den;
}
int main(){
    int cas=1,t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n>>k;
        ara=vector<int>(n);
        for(int i=0;i<n;i++){
            cin>>ara[i];
        }
        sort(ara.begin(),ara.end());
        int cnt=0;
        int first=-1;
        for(int i=0;i<n;i++) {
            if(ara[i]==ara[k-1]){
                cnt++;
                if(first==-1) first=i;
            }
            else if(i>=k) break;
        }
        int need=k-first;
        cout<<nCr(cnt,need)<<endl;
    }

    return 0;
}