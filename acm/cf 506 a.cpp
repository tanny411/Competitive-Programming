#include<bits/stdc++.h>
#define pii pair<int,int>
#define fs first
#define sc second
#define CIN ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int lps[100];
void computeLPS(string pat,int m)
{
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i]) lps[i]=++len,i++;
        else if(len!=0) len=lps[len-1];
        else lps[i]=0,i++;
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    computeLPS(s,n);
    int x=lps[n-1];
    if(x==0){
        while(k--) cout<<s;
    }
    else {
        for(int i=0;i<x;i++) cout<<s[i];
        while(k--) for(int i=x;i<n;i++) cout<<s[i];
    }
    return 0;
}
