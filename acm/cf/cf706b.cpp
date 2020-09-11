#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0;i<n;i++) cin>>prices[i];
    sort(prices.begin(), prices.end());
    int m;
    cin>>m;
    while(m--){
        int x;
        cin>>x;
        int ix = upper_bound(prices.begin(), prices.end(), x) - prices.begin();
        cout<<ix<<endl;
    }
    return 0;
}