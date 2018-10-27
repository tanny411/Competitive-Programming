#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define inf 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
int n;
vector<int>steep;
int dp[1003][13][53][7];
int rec(int pos,int K,int E,int prev)
{
    if(K<0) return -inf;
    if(pos==n)
    {
        return 0;
    }
    int &ret=dp[pos][K][E][prev];
    if(ret!=-1) return ret;
    int a,b,c,d;
    a=b=c=d=0;
    if(E>=3) a=min(11,steep[pos])+rec(pos+1,prev==3?K:K-1,E-3,3);
    if(E>=2) b=min(8,steep[pos])+rec(pos+1,prev==2?K:K-1,E-2,2);
    if(E>=1) c=min(4,steep[pos])+rec(pos+1,prev==1?K:K-1,E-1,1);
    if(E>=0) d=rec(pos+1,prev==0?K:K-1,E,0);
    ret=max(max(a,b),max(c,d));
    return ret=max(0,ret);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int k,e;
        cin>>n>>k>>e;
        steep.clear();
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int i=0;i<n;i++) {int x;cin>>x;steep.pb(x);sum+=x;}
        int x=rec(0,k,e,0);
        x=max(0,x);
        cout<<"Case #"<<test++<<": "<<sum-x<<endl;
    }
    return 0;
}

