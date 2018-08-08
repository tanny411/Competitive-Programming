#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define ll unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
#define mx 100004
vector<ll>sub(mx),sum2(mx);
ll Sum;
vector<pii>gr[mx];
int n;
ll dfs(int u,int p)
{
    ll sum=0;
    sub[u]=1;
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i].fs;
        int w=gr[u][i].sc;
        if(v!=p)
        {
            ll x=dfs(v,u);
            sub[u]+=sub[v];
            sum+=x+1ll*w*sub[v];
        }
    }
    return sum;
}

void dfs2(int u,int p,int val)
{
    if(p!=-1) sum2[u]=sum2[p]- val*sub[u] +  (n-sub[u])*val;
    else sum2[u]=Sum;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i].fs;
        int w=gr[u][i].sc;
        if(v!=p)
        {
            dfs2(v,u,w);
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            gr[i].clear();
            sub[i]=0;
            sum2[i]=0;
        }
        for(int i=0; i<n-1; i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            gr[x].pb({y,z});
            gr[y].pb({x,z});
        }
        Sum=dfs(1,-1);
        dfs2(1,-1,-1);
        for(int i=1;i<=n;i++)
        {
            cout<<sum2[i]<<endl;
        }
    }
    return 0;
}
