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
string s;
int dp[105][105];

int run(int i,int j)
{
    if(i>=j) return 0;
    int &ret=dp[i][j];
    if(ret!=-1) return ret;
    if(s[i]==s[j]) ret=run(i+1,j-1);
    else ret=1+min( run(i+1,j),run(i,j-1) );
    return ret;
}

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<"Case "<<cas++<<": "<<run(0,s.length()-1)<<"\n";
    }
    return 0;
}

