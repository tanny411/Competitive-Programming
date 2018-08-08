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
vector<int>v;
ll dp[33][2][33];

ll rec(int ind,int tight,int prev,int sofar)
{
    if(ind==-1) return sofar;
    if(dp[ind][prev][sofar]!=-1 && tight==0) return dp[ind][prev][sofar];
    int lim=tight?v[ind]:1;
    ll ret=0;
    int sf;
    for(int i=0;i<=lim;i++)
    {
        int newtight=v[ind]==i?tight:0;
        if(i==1 && prev==1) sf=sofar+1;
        else sf=sofar;
        ret+=rec(ind-1,newtight,i,sf);
    }
    if(tight==0) dp[ind][prev][sofar]=ret;
    return ret;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        v.clear();
        while(n)
        {
            v.pb(n%2);
            n/=2;
        }
        cout<<"Case "<<cas++<<": "<<rec(v.size()-1,1,0,0)<<"\n";
    }
    return 0;
}

