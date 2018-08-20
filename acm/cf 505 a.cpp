#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(26);
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        v[s[i]-'a']++;
    }
    int mx=0;
    for(int i=0;i<26;i++){
        mx=max(mx,v[i]);
    }
    if(mx>=2 || n==1) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
