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
        string s;
        cin>>n>>s;
        int ase=0;
        for(int i=0;i<n;i++){
            if(s[i]=='8' && n-i>=11){
                ase=1;
                break;
            }
        }
        if(ase) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}