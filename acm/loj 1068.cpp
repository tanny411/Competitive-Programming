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

///

using namespace std;
int dp[11][84][84];
ll k;
ll place[12];
vector<int>v;
ll rec(int ind,int tight,int num,int dig)
{
    if(ind==-1)
    {
        if(num==0 && dig==0) return 1;
        else return 0;
    }
    if(dp[ind][num][dig]!=-1 && tight==0) return dp[ind][num][dig];
    int lim=tight?v[ind]:9;
    ll ret=0;
    ll n=place[ind]%k;
    for(int i=0;i<=lim;i++)
    {
        int newtight=v[ind]==i?tight:0;
        ret+=rec(ind-1,newtight,(num+i*n)%k,(dig+i)%k );
    }
    if(tight==0)dp[ind][num][dig]=ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    place[0]=1;
    for(int i=1;i<12;i++) place[i]=place[i-1]*10;
    int t;
    cin>>t;
    int cas=1;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        ll a,b;
        cin>>a>>b>>k;
        if(k>83) {cout<<"Case "<<cas++<<": "<<0<<"\n"; continue;}
        v.clear();
        a--;
        if(a==0) v.pb(0);
        while(a)
        {
            v.pb(a%10);
            a/=10;
        }
        ll ans1=rec(v.size()-1,1,0,0);
        v.clear();
        while(b)
        {
            v.pb(b%10);
            b/=10;
        }
        //memset(dp,-1,sizeof dp);
        ll ans2=rec(v.size()-1,1,0,0);
        //cout<<"ans2="<<ans2<<endl;
        cout<<"Case "<<cas++<<": "<<ans2-ans1<<"\n";
    }
    return 0;
}

