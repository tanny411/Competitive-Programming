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
string s;
int dp[100][100];
int periodKoto(string pat,int m)
{
    vector<int>lps(m);
    lps[0]=0;
    int len=0;
    int i=1;
    while(i<m)
    {
        if(pat[len]==pat[i]) lps[i]=++len,i++;
        else if(len!=0) len=lps[len-1];
        else lps[i]=0,i++;
    }
    int k=m-lps[m-1];
    if(m%k==0) return k;
    else return m;
}
int rec(int i,int j)
{
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int len=j-i+1;
    int period=periodKoto(s.substr(i,len),len);
    if(period<len) return dp[i][j]=rec(i,i+period-1);
    int &ret=dp[i][j];
    ret=1<<30;
    for(int k=i;k<j;k++)
    {
        ret=min(ret,rec(i,k)+rec(k+1,j));
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    while(cin>>s && s!="*")
    {
        int n=s.length();
        memset(dp,-1,sizeof dp);
        cout<<rec(0,n-1)<<endl;
    }
    return 0;
}

