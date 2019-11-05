#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s[0]=='0') {cout<<"NO\n";continue;}
        int ans=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='0') ans++;
            else {
                if(ans<=2) ans=0;
                else break;
            }
        }
        if(ans>2) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}