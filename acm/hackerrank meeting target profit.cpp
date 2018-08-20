#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        ll left=0;
        while(n--){
            ll a,b;
            cin>>a>>b;
            b+=left;
            left=max(0,b-a);
        }
        cout<<(left!=0)<<endl;
    }
    return 0;
}
