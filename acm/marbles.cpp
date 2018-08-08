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

///ios_base::sync_with_stdio(false);

using namespace std;

double dp[505][505];

double rec(int r,int b)
{
    if(b<=0) return 0;
    if(r==0) return 1.0;
    if(dp[r][b]!=-1) return dp[r][b];
    double ret=(r/(1.0*(r+b)))*rec(r-1,b-1)+(b/(1.0*(r+b)))*rec(r,b-2);
    return dp[r][b]=ret;
}
void mem()
{
    for(int i=0;i<501;i++)
    {
        for(int j=0;j<501;j++) dp[i][j]=-1;
    }
}
int main()
{
    mem();
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int r,b;
        cin>>r>>b;
        cout<<"Case "<<cas++<<": "<<setprecision(10)<<rec(r,b)<<"\n";
    }
    return 0;
}

