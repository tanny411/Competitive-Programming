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
int ara[200];
int dp[110][110];
int rec(int i,int j,int sum)
{
    if(i>j) return 0;
    if(i==j) return ara[i];
    if(dp[i][j]!=-1) return dp[i][j];
    int ret=sum;
    int cum=0;
    for(int k=i;k<j;k++)
    {
        cum+=ara[k];
        ret=max(ret,cum-rec(k+1,j,sum-cum));
        ret=max(ret,sum-cum-rec(i,k,cum));
    }
    return dp[i][j]=ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    int n;
    while(cin>>n && n)
    {
        memset(dp,-1,sizeof dp);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>ara[i];
            sum+=ara[i];
        }
        cout<<rec(0,n-1,sum)<<endl;
    }
    return 0;
}

