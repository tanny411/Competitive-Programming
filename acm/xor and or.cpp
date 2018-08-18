#include<bits/stdc++.h>
using namespace std;

int main()
{
    string a ,b;
    cin>>a>>b;
    if(a.length()==b.length()){
        int A=0;
        int B=0;
        for(int i=0;i<a.length();i++){
            if(a[i]=='1') A=1;
            if(b[i]=='1') B=1;
        }
        if(a==b) cout<<"YES\n";
        else if(A==0 || B==0) cout<<"NO\n";
        else cout<<"YES\n";
    }
    else cout<<"NO\n";
    return 0;
}
