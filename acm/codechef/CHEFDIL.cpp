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
        int o=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1') o++;
        }
        if(o&1) cout<<"WIN\n";
        else cout<<"LOSE\n";
    }

    return 0;
}