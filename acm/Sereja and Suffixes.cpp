#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    vector<int>v(n+2);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    set<int>s;
    for(int i=n;i>=1;i--){
        s.insert(v[i]);
        v[i]=s.size();
    }
    while(q--){
        int l;
        cin>>l;
        cout<<v[l]<<endl;
    }
    return 0;
}
