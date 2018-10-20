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
#define nd 100005
using namespace std;
vector<int>gr[nd],col(nd),cnt(nd),siz(nd),st(nd),fn(nd),ver(nd);
vector<LL>ans(nd);
int t,n;
int mex=0;
LL ANS=0;
void dfssiz(int u,int p)
{
    t++;
    ver[t]=u;
    st[u]=t;
    siz[u]=1;
    for(int i=0; i<gr[u].size(); i++)
    {
        if(gr[u][i]!=p)
        {
            dfssiz(gr[u][i],u);
            siz[u]+=siz[gr[u][i]];
        }
    }
    fn[u]=t;
}
void dfs(int u,int p,int keep)
{
    int mx=-1,bigchild=-1;

    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i];
        if(v==p) continue;
        if(mx<siz[v])
        {
            mx=siz[v];
            bigchild=v;
        }
    }

    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i];
        if(v==p || v==bigchild) continue;
        dfs(v,u,0);
    }

    if(bigchild!=-1)dfs(bigchild,u,1);

    int temp=mex;
    cnt[col[u]]++;
    mex=max(mex,cnt[col[u]]);
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i];
        if(v==p || v==bigchild) continue;
        for(int j=st[v]; j<=fn[v]; j++)
        {
            cnt[ col[ ver[j] ] ]++;
            mex=max(mex,cnt[ col[ ver[j] ] ]);
        }
    }
    if(mex!=temp) ANS=0;
    set<int>stk;
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i];
        if(v==p || v==bigchild) continue;
        for(int j=st[v]; j<=fn[v]; j++)
        {
            if(cnt[ col[ ver[j] ] ]==mex) stk.insert(col[ ver[j] ]);
        }
    }
    if(cnt[col[u]]==mex) stk.insert(col[u]);
    for(auto i=stk.begin();i!=stk.end();i++)
    {
        ANS+=0ll+(*i);
    }
    ans[u]=ANS;
    if(keep==0) {mex=0;ANS=0;}
    if(keep==0)
        for(int i=st[u]; i<=fn[u]; i++)
        {
            cnt[ col[ ver[i] ] ]--;
        }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>col[i];
    }
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    t=0;
    dfssiz(1,-1);
    dfs(1,-1,0);
    for(int i=1; i<=n; i++)
    {
        if(i>1) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}

