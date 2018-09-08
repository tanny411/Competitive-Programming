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
int dp[1000];
int rec(int i){
    if(dp[i]!=-1) return dp[i];
    dp[i]=0;
    int n=i;
    int temp=0;
    while(n){
        temp+=(n%10)*(n%10);
        n/=10;
    }
    return dp[i]=rec(temp);
}
int main()
{
    int t,test=1;
    cin>>t;
    memset(dp,-1,sizeof dp);
    dp[1]=1;
    while(t--)
    {
        int n,N;
        cin>>n;
        N=n;
        int temp=0;
        while(n){
            temp+=(n%10)*(n%10);
            n/=10;
        }
        n=temp;
        cout<<"Case #"<<test++<<": "<<N<<" is a"<<(rec(n)==1?" Happy number.":"n Unhappy number.")<<endl;
    }
    return 0;
}
