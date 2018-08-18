#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,k;
    cin>>n>>k;
    int beg=1;
    while(beg<=n){
        if(k&1) {
            cout<<beg<<endl;
            return 0;
        }
        k/=2;
        beg++;
    }
return 0;}
