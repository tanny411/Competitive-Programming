#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int hobena = 0;
    char ara[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>ara[i][j];
            if(j && ara[i][j]==ara[i][j-1]) hobena=1;
        }
    }
    if(hobena) cout<<"NO\n";
    else cout<<"YES\n";
    return 0;
}