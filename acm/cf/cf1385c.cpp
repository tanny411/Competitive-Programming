#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        //the idea id to take non-decreasing sequence from right
        //and then from right take the non-increasing sequence
        //so if we consider picking from left and right ends,
        //we will always end up with a non-decreasing sequence
        int n;
        cin>>n;
        vector<int>v = vector<int>(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int in=n-2;
        int cnt=1;
        while(in>=0 && v[in]>=v[in+1]){
            in--;
            cnt++;
        }
        if(in>=0) cnt++, in--;
        while(in>=0 && v[in]<=v[in+1]){
            in--;
            cnt++;
        }
        cout<<n-cnt<<endl;
    }

    return 0;
}