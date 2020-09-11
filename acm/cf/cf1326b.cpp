#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int n;
    cin>>n;
    int x = 0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(i) cout<<" ";
        cout<<a+x;
        x = max(x, a+x);
    }

    return 0;
}