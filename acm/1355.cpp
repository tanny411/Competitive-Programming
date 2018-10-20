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
///u--v with weight w means w edges between u and v
///so if w>1 there is loop and we use fusion principle
///if w&1 one edge u--v
///else no edge, consider u and v fused
vector<pii>gr[1005];
int dfs(int u,int p)
{
    int ret=0;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i].fs;
        int w=gr[u][i].sc;
        if(v==p) continue;
        int x=dfs(v,u);
        if(w==1) ret^=(x+1);
        else if(w&1) ret^=(x^1);
        else ret^=x;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++) gr[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            gr[u].pb(pii(v,w));
            gr[v].pb(pii(u,w));
        }
        cout<<"Case "<<test++<<": "<<(!dfs(0,-1)?"Jolly":"Emily")<<endl;
    }
    return 0;
}

