#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int x;
    cin>>x;
    if(x&1) cout<<9<<" "<<x-9<<endl;
    else cout<<4<<" "<<x-4<<endl;
    return 0;
}