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

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int  n;
        cin>>n;
        int fr1[n],fr2[n],ch1[n],ch2[n];///fruit eating times and floor changing times
        for(int i=0;i<n;i++) cin>>fr1[i];
        for(int i=0;i<n;i++) cin>>fr2[i];
        for(int i=0;i<n-1;i++) cin>>ch1[i];
        for(int i=0;i<n-1;i++) cin>>ch2[i];
        int dp1[n],dp2[n];
        dp1[0]=fr1[0];
        dp2[0]=fr2[0];
        for(int i=1;i<n;i++)
        {
            dp1[i]=fr1[i]+min(dp1[i-1],dp2[i-1]+ch2[i-1]);
            dp2[i]=fr2[i]+min(dp2[i-1],dp1[i-1]+ch1[i-1]);
        }
        cout<<"Case "<<cas++<<": "<<min(dp1[n-1],dp2[n-1])<<"\n";
    }
    return 0;
}

