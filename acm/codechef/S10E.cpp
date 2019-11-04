#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;
    cin>>t;
    while(t--)
    {   
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        int mn=1<<30;
        int cnt=0;
        for(int j=0;j<5;j++){
            if(v[j]<mn) cnt++;
            mn=min(mn,v[j]);
        }
        for(int i=5;i<n;i++){
            mn=1<<30;
            for(int j=i-5;j<i;j++){
                mn=min(mn,v[j]);
            }
            if(v[i]<mn) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}