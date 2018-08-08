#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define mod 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int ind;
vector<int>ara;

ll dp[103][1005],ncr[50002][1002];

ll rec(int pos,int k)
{
    if(k==0) return 1ll;
    if(pos>=ind) return 0ll;
    if(dp[pos][k]!=-1) return dp[pos][k];
    int lim=min(k,ara[pos]-ara[pos-1]);
    ll ret=0;
    for(int i=0;i<=lim;i++)
    {
        ret=(ret+ (ncr[ara[pos-1]+i-1][i]*rec(pos+1,k-i))%mod )%mod;
    }
    return dp[pos][k]=ret;
}

int main()
{

    ncr[0][0]=1;
    for(int i=1;i<=50000;i++)
    {
        int l=min(i,1000);
        for(int j=0;j<=l;j++)
        {
            ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
        }
    }

    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        ara.clear();
        int x=1;
        for(int i=1;i<n;i++)
        {
            if(v[i]==v[i-1])
            {
                x++;
            }
            else
            {
                ara.pb(x);
                x=1;
            }
        }
        ara.pb(x);
        ind=ara.size();
        for(int i=1;i<ind;i++)
        {
            ara[i]+=ara[i-1];
            //cout<<" "<<ara[i];
        }
        //cout<<endl;
        memset(dp,-1,sizeof dp);

        cout<<"Case "<<cas++<<": "<<rec(1,k)<<endl;
    }
    return 0;
}

