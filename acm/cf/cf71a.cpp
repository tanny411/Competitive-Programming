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
        if(s.length()>10){
            cout<<s[0]<<s.length()-2<<s.back()<<endl;
        }
        else{
            cout<<s<<endl;
        }
    }

    return 0;
}