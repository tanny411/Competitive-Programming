#include<bits/stdc++.h>
#define pb push_back
#define md 1000000007
#define ll long long
#define fs first
#define sc second

using namespace std;
vector<int>prime;
void sieve(int n)
{
    vector<int>flag(n);
    prime.pb(2);
    for(int i=3;i<n;i+=2)
    {
        if(flag[i]==0)
        {
            prime.pb(i);
            for(int j=i*i;j<n;j+=(i+i)) flag[j]=1;
        }
    }
}
ll dp[505][505];///k,p
int main()
{
    ios_base::sync_with_stdio(false);

    sieve(4000);
    dp[0][0]=1;

    for(int i=1;i<=500;i++)//k
    {
        for(int j=1;j<=i;j++)//p
        {
            dp[i][j]=dp[i-1][j-1]*(prime[j-1]-1);
            if(i>j) dp[i][j]+=dp[i-1][j]*prime[j-1];
            dp[i][j]%=md;
            if(dp[i][j]<0) dp[i][j]+=md;
        }
    }

    int t,test=1;
    cin>>t;
    while(t--){
        int k,p;
        cin>>k>>p;
        cout<<"Case "<<test++<<": "<<dp[k][p]<<endl;
    }
    return 0;
}

