#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int rec(int a, int b){
    if(a==0 || b==0) return 0;
    if(b>a) swap(a,b);
    //always a>=b
    int x = a/b;
    // cout<<"x: "<<x<<endl;
    return x + rec(b, a%b);
}

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<rec(a,b)<<endl;
    }
    

    return 0;
}