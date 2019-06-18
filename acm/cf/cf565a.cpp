#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int t=0,th=0,f=0;
        while(n%2==0) n/=2, t++;
        while(n%3==0) n/=3, th++;
        while(n%5==0) n/=5, f++;
        t+=th;
        t+=2*f;
        if(n!=1) cout<<-1<<endl;
        else cout<<t+th+f<<endl;
    }
    return 0;
}