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
vector<pii>g[1005];
int dfs(int u,int p=-1)
{
    int ans=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].fs;
        if(v!=p) ans^=dfs(v,u)+g[u][i].sc;
    }
    return ans;
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) g[i].clear();
        for(int i=0;i<n-1;i++)
        {
            int x,y,w;
            scanf("%d%d%d",&x,&y,&w);
            g[x].pb(pii(y,w&1));
            g[y].pb(pii(x,w&1));
        }
        if(dfs(0)) printf("Case %d: Emily\n",cas++);
        else printf("Case %d: Jolly\n",cas++);
    }
    return 0;
}

/*
1
3
0 1 3
1 2 3
*/
//jolly
