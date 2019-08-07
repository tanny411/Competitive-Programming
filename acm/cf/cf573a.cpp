#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int x;
    cin>>x;
    if(x%4==1) cout<<"0 A";
    else if(x%4==3) cout<<"2 A";
    else if (x%4==2) cout<<"1 B";
    else cout<<"1 A";
    return 0;
}