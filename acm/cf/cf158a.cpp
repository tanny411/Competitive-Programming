#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int n,k;
    cin>>n>>k;
    k--;
    vector<int> vec = vector<int>(n);
    int out = 0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        if((i<=k || vec[i]>=vec[k]) && vec[i]>0) out++;
    }
    cout<<out<<endl;

    return 0;
}