/*
ID: aysha.k1
LANG: C++11
TASK: subset
*/
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

LL dp[40][700];
int n;
LL rec(int i,int sum)
{
    if(sum==0) return 1;
    if(i>n) return 0;
    if(dp[i][sum]!=-1) return dp[i][sum];
    else return dp[i][sum]=rec(i+1,sum-i)+rec(i+1,sum);
}

int main()
{

    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    memset(dp,-1,sizeof dp);
    cin>>n;
    int sum=(n*(n+1))/2;
    if(sum%2) cout<<0<<endl;
    else {sum/=2;cout<<rec(1,sum)/2<<endl;}
    return 0;
}

