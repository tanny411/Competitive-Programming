#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
ll mx=INT_MAX;
string s;
int n;
ll dp[500];
ll rec(int pos){
    if(pos==n) return 0;
    if(dp[pos]!=-1) return dp[pos];
    //cout<<"now?\n";
    if(s[pos]=='0') return dp[pos]=rec(pos+1);
    //cout<<"aise\n";
    ll ret=0;
    ll temp=0;
    for(int i=pos;i<n;i++){
        if(temp*10+s[i]-'0'<=mx){
            temp=temp*10+s[i]-'0';
            ret=max(ret,temp+rec(i+1));
            //cout<<ret<<endl;
        }
        else break;
    }
    return dp[pos]=ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        memset(dp,-1,sizeof dp);
        cout<<rec(0)<<endl;
    }
    return 0;
}
