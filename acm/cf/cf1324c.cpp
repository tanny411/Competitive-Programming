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
        int ini = -1;
        int mx = -1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='R'){
                mx = max(mx, i-ini);
                ini = i;
            }
        }
        mx = max(mx, int(s.length())-ini);
        cout<<mx<<endl;
    }

    return 0;
}