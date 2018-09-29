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
int en;
vector<pii>v[20];
double dp[15][1<<15];
int rec(int u,int mask)
{
    if(mask==en) {
        dp[u][mask]=0;
        return 1;
    }
    double& ret=dp[u][mask];
    if(ret>-1) return ret>0;///jawa jay kina dekhbo
    ret=5.0;
    int cnt=0;
    for(int i=0;i<v[u].size();i++)
    {
        int next=v[u][i].fs;
        int tempMask=mask|(1<<next);
        if(!(mask&(1<<next)) && rec(next,tempMask))///jawa gele and unvisited hoile jabo
        {
            ret+=v[u][i].sc+dp[next][tempMask];
            cnt++;
        }
    }
    if(cnt==0) {
        dp[u][mask]=0;
        return 0;
    }
    else{
        dp[u][mask]/=(1.0*cnt);
        return 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        ///purification
        for(int i=0;i<n;i++){
            v[i].clear();
            for(int j=0;j<(1<<n);j++) dp[i][j]=-1;
        }
        en=(1<<n)-1;
        while(m--)
        {
            int x,y,w;
            cin>>x>>y>>w;
            v[x].pb(pii(y,w));
            v[y].pb(pii(x,w));
        }
        rec(0,1);
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<dp[0][1]<<endl;
    }
    return 0;
}

