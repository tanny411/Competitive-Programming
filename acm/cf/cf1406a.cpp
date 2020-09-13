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
        vector<int>v(n), fl(1000);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(), v.end());
        int out=0;
        for(int i=0;i<n;i++){
            fl[v[i]]++;
        }
        int one=1, two=1;
        for(int i=0;i<=100;i++){
            if(!one && !two) break;
            if(one && fl[i]==0) out+=i, one=0;
            if(two && fl[i]<=1) out+=i, two=0;
        }
        cout<<out<<endl;
    }

    return 0;
}