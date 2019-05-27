#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int n,m;
    cin>>n>>m;
    int o1=0,e1=0,o2=0,e2=0;
    while(n--){
        int x;
        cin>>x;
        if(x&1) o1++;
        else e1++;
    }
    while(m--){
        int x;
        cin>>x;
        if(x&1) o2++;
        else e2++;
    }
    cout<<min(o1,e2)+min(o2,e1)<<endl;
    return 0;
}