#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int n,x,y,d, t;
    cin>>t;
    while(t--){
        cin>>n>>x>>y>>d;
        int moves=1<<30;
        if((abs(x-y))%d==0){
            moves = min(moves, abs(x-y)/d);
        }
        if((y-1)%d==0){
            moves=min(moves, (y-1)/d + int(ceil((x-1)/(1.0*d))));
        }
        if((n-y)%d==0){
            moves=min(moves, (n-y)/d + int(ceil((n-x)/(1.0*d))));
        }
        if(moves==1<<30) moves=-1;
        
        cout<<moves<<endl;
    }
    

    return 0;
}