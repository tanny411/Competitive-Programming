#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    int n,k;
    cin>>n>>k;
    int num = (240-k)/5;
    int out = 0;
    for(int i=1;i<=n;i++){
        if(num>=i) num-=i, out++;
        else break;
    }
    cout<<out<<endl;
    return 0;
}