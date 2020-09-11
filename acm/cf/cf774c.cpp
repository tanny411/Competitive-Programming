#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int n;
    cin>>n;
    if(n&1){
        cout<<7;
        n-=3;
    }
    while(n){
        cout<<1;
        n-=2;
    }
    return 0;
}