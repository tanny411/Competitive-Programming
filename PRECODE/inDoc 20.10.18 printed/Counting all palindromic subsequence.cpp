#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
char s[100];
ll dp[61][61];
ll rec(int i,int j)
{
    if(i==j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ret;
    if(s[i]==s[j]) ret=1+rec(i+1,j)+rec(i,j-1);
    else ret=rec(i+1,j)+rec(i,j-1)-rec(i+1,j-1);
    return dp[i][j]=ret;
}
int main()
{
    int t;
    int cas=1;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        gets(s);
        printf("Case %d: %lld\n",cas++,rec(0,strlen(s)-1));
    }
    return 0;
}
