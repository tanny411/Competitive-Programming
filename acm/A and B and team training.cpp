#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;

    int mx=0;
    for(int i=0;i<a;i++){
        int la=a-2*i;
        int lb=b-i;
        if(la<0 || lb<0) break;
        mx=max(mx,i+min(la,lb/2));
    }
    cout<<mx<<endl;
    return 0;
}
