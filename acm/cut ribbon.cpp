#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int mx=0;
    for(int i=0;i<=n;i++){
        int templen=n-a*i;
        if(templen<0) break;
        for(int j=0;j<=n;j++){
            int thentemp=templen-b*j;
            if(thentemp<0) break;
            if(thentemp%c==0) mx=max(mx,i+j+thentemp/c);
        }
    }
    cout<<mx<<endl;
    return 0;
}
