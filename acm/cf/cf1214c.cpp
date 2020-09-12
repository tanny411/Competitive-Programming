#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int n;
    string s;
    cin>>n>>s;
    int balance = 0;
    int mn = 1<<30;
    for(int i=0;i<n;i++){
        if(s[i]=='(') balance++;
        else balance--;
        mn = min(mn, balance);
    }
    if(balance==0 && mn>=-1 && mn<=0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}