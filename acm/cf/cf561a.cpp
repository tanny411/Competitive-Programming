#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int n;
    cin>>n;
    vector<int>mp(30);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        mp[s[0]-'a']++;
    }
    int x=0;
    for(int i=0;i<26;i++){
        int y=mp[i]/2;
        int z=y+mp[i]%2;
        x+=y*(y-1)/2 + z*(z-1)/2;
    }
    cout<<x<<endl;
    return 0;
}