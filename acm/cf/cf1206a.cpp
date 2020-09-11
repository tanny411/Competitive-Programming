#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define fs first
#define sc second
using namespace std;

int main(){
    int n;
    cin>>n;
    ll pos=0, neg=0, nzero=0, npos=0, nneg=0;
    for (int i=0;i<n;i++){
        ll a;
        cin>>a;
        if (a==0) nzero++;
        else if(a>0) pos+=a-1, npos++;
        else  neg+= -(a+1), nneg++;
    }
    ll ans = pos+neg;
    // cout<<pos<<" "<<neg<<endl;
    if (nzero>0) ans+=nzero; //if nneg is odd, make one 0 -1, else all are 1
    else if(nneg&1) ans+=2; //turn one -1 into 1
    cout<<ans<<endl;
    return 0;
}