#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define pdd pair<double,double>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int dp[105][105][105];
pdd ara[105];
int n;
bool left(pdd a,pdd b)
{
    if(a.fs==b.fs) return a.sc<b.sc;
    else return a.fs<b.fs;
}
bool cw(pdd o,pdd a,pdd b)
{
    return (a.fs-o.fs)*(b.sc-o.sc)>(b.fs-o.fs)*(a.sc-o.sc);
}
int rec(int from,int s,int f)
{
    //cout<<from<<" "<<s<<" "<<f<<endl;
    if(dp[from][s][f]!=-1) return dp[from][s][f];
    int mx=0;
    for(int i=0;i<n;i++){
        if(left(ara[from],ara[i]) && cw(ara[from],ara[f],ara[i]) && cw(ara[s],ara[f],ara[i])) mx=max(mx,rec(from,f,i)+1);
    }
    return dp[from][s][f]=mx;
}
int main()
{
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i].fs>>ara[i].sc;
    }
    int mx=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            //cout<<i<<" "<<j<<" "<<left(ara[i],ara[j])<<endl;
            if(left(ara[i],ara[j])) mx=max(mx,rec(i,i,j));
        }
    }
    cout<<mx+2<<endl;
    return 0;
}
