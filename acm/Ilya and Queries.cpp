#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n,q,l,r;
    cin>>s;
    n=s.length();
    vector<int>v(n+1);
    for(int i=0;i<n-1;i++){
        v[i+1]=v[i]+(s[i]==s[i+1]);
        //cout<<v[i+1]<<" ";
    }
    //cout<<endl;
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<v[r-1]-v[l-1]<<endl;
    }
    return 0;
}
