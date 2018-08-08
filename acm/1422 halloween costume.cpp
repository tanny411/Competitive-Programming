#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///

using namespace std;
int dp[104][104],v[104];
int rec(int b,int e)
{
    if(b==e) return 1;
    if(b>e) return 0;
    if(dp[b][e]!=-1) return dp[b][e];
    int ret=1+rec(b+1,e);
    for(int i=b+1;i<=e;i++)
    {
        if(v[b]==v[i]) ret=min(ret,rec(b+1,i)+rec(i+1,e));
    }
    return dp[b][e]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<cas++<<": "<<rec(0,n-1)<<"\n";
    }
    return 0;
}

