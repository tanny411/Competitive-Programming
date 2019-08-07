#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int one=0;
        for(int i=0;i<b.length();i++){
            if(b[i]=='1') one=i;
        }
        one=b.length()-one;
        int ans=0;
        for(int i=a.length()-one;i>=0;i--){
            if(a[i]=='1') break;
            ans++;
        }
        cout<<ans<<endl;
    }

    return 0;
}