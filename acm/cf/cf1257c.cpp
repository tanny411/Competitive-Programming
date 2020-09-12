#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        map<int,vector<int> >mp;
        int n;
        cin>>n;
        int mn=1<<30;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(!mp[x].empty()){
                int y = mp[x].back();
                mn = min(mn, i-y+1);
            }
            mp[x].push_back(i);
        }
        if(mn==1<<30) mn=-1;
        cout<<mn<<endl;
    }

    return 0;
}