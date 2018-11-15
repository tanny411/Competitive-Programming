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

using namespace std;
int dp[10009];
int rec(int n)
{
    if(n<=0) return 0;
    if(n==1) return 1;
    if(dp[n]!=-1) return dp[n];
    set<int>s;
    for(int i=1;i<=n;i++)
    {
        s.insert(rec(i-2)^rec(n-i-1));
    }
    int ret=0;
    while(s.find(ret)!=s.end()) ret++;
    return dp[n]=ret;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int prev=0;
    for(int i=1;i<=100;i++)
    {
        rec(i);
    }
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        if(n<=100) {if(dp[n]) ans=1;}
        else{
            n-=38;
            n%=34;
            //cout<<"aise "<<n<<endl;
            if(n==4 || n==16 || n==20 || n==24 || n==0) ans=0;
            else ans=1;
        }
        cout<<"Case #"<<test++<<": "<<(ans?"UDIN":"UCOK")<<endl;
    }
    return 0;
}
