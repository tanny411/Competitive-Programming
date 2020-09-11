#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fs first
#define sc second
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int> v = vector<int>(12);
    for(int i=0;i<12;i++){
        cin>>v[i];
    }
    sort(v.rbegin(), v.rend());
    int out = 0;
    for(int i=0;i<12;i++){
        if(k<=0) break;
        k-=v[i];
        out++;
    }
    if(k>0) cout<<-1<<endl;
    else cout<<out<<endl;
    return 0;
}