#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    freopen ("leapfrog_ch_.txt","r",stdin);
    freopen ("myfile.txt","w",stdout);
    int cas=1,t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int dot=0,B=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='.') dot++;
            else B++;
        }
        if(B>=dot && B>0 && dot>0) cout<<"Case #"<<cas++<<": Y\n";
        else cout<<"Case #"<<cas++<<": N\n";
    }
    // fclose (stdout);
    return 0;
}