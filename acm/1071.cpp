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

int n,m,ara[104][104],dp[104][104][104];
int rec(int r1,int c1,int r2,int c2)
{
    if(r1>=n || r2>=n || c1>=m || c2>=m || (r1==r2 && c1==c2) ) return 0;
    if(dp[r1][c1][r2]!=-1) return dp[r1][c1][r2];
    int ret=0;
    ret=max(ret,rec(r1+1,c1,r2+1,c2));
    ret=max(ret,rec(r1+1,c1,r2,c2+1));
    ret=max(ret,rec(r1,c1+1,r2+1,c2));
    ret=max(ret,rec(r1,c1+1,r2,c2+1));
    ret+=ara[r1][c1]+ara[r2][c2];
    return dp[r1][c1][r2]=ret;
}
int main()
{
    int t,test=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>ara[i][j];
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<test++<<": "<<rec(1,0,0,1)+ara[0][0]+ara[n-1][m-1]<<endl;
    }
    return 0;
}
