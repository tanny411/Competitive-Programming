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
#define nd 100005
///ios_base::sync_with_stdio(false);

using namespace std;
int val[nd],ed[nd],ans[nd];
vector<int>gr[nd];

set<int> dfs(int u,int take)
{
    set<int>us;
    us.insert(val[u]+take);
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        set<int>s=dfs(v,take+ed[v]);
        if(s.size()>us.size()) swap(s,us);
        for(auto x:s) us.insert(x);
    }
    ans[u]=us.size();
    return us;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    int start;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x)gr[x].pb(i);
        else start=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>ed[i];
    }
    dfs(start,0);
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
