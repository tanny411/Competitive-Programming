#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.rbegin(),v.rend());
    int mx=-1;
    for(int i=1;i<n;i++){
        mx=max(mx,v[i]%v[0]);
    }
    cout<<mx<<endl;
    return 0;
}