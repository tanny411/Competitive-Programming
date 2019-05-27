#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    
    int t,cas=1;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        char x;
        cin>>s>>x;
        ll tot=n*(n+1)/2;
        int p=-1;
        for(int i=0;i<n;i++){
            if(s[i]==x){
                ll len=i-p-1;
                p=i;
                tot-=max(0ll,len*(len+1)/2);
            }
        }
        ll len=n-p-1;
        tot-=max(0ll,len*(len+1)/2);
        cout<<tot<<endl;
    }

    return 0;
}