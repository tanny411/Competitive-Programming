#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int n;
    cin>>n;
    string s;
    cin>>s;

    int o=0,z=0;
    for (int i=0;i<n;i++){
        if(s[i]=='1') o++;
        else z++;
    }
    if(z!=o) cout<<1<<endl<<s<<endl;
    else cout<<2<<endl<<s[0]<<" "<<s.substr(1,s.length()-1)<<endl;

    return 0;
}