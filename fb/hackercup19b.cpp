#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    freopen ("leapfrog_ch_2.txt","r",stdin);
    freopen ("myfile2.txt","w",stdout);
    int cas=1,t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int dot=0,B=0,l=s.length();
        for(int i=1;i<l;i++){
            if(s[i]=='.') dot++;
            else B++;
        }
        int ok=0;
        if(B>0 && dot>0) {
            if(l<=3) ok=1;
            else if(B>1) ok=1;
        }
        if(ok) cout<<"Case #"<<cas++<<": Y\n";
        else cout<<"Case #"<<cas++<<": N\n";
    }
    // fclose (stdout);
    return 0;
}