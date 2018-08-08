#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
vector<int>gr[50002];
int L[50002],R[50002],lyl[50002],ab[50002],tr[4*50002],vis[50002];
int nd[50002];
int tt;
map<int,int>mp;
void update(int node,int b,int e,int i,int v)
{
    if(b==e && b==i)
    {
        tr[node]=v;
        return;
    }
    if(i>e || i<b) return;
    int m=(b+e)/2;
    update(node*2,b,m,i,v);
    update(node*2+1,m+1,e,i,v);
    tr[node]=max(tr[node*2],tr[node*2+1]);
}
int query(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j) return tr[node];
    else if(e<i || j<b) return -1;
    int m=(b+e)/2;
    return max(query(node*2,b,m,i,j),query(node*2+1,m+1,e,i,j));
}
void init(int n)
{
    memset(tr,-1,sizeof(tr));
    memset(vis,0,sizeof vis);
    for(int i=0; i<=n; i++) gr[i].clear();
    mp.clear();
}
bool cmp(int a,int b)
{
    return ab[a]>ab[b];
}
bool cmpp(pii a,pii b)
{
    return ab[a.fs]>ab[b.fs];
}
void dfs(int u)
{
    L[u]=tt;
    vis[u]=1;
    for(int i=0; i<gr[u].size(); i++)
    {
        int v=gr[u][i];
        if(!vis[v])
        {
            tt++;
         dfs(v);
        }
    }
    R[u]=tt;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        init(n);
        for(int i=1; i<n; i++)
        {
            int p,l,a;
            scanf("%d %d %d",&p,&l,&a);
            gr[p].pb(i);
            lyl[i]=l;
            ab[i]=a;
            nd[i-1]=i;
            mp[l]=i;
        }
        sort(nd,nd+n-1,cmp);
        tt=0;
        dfs(0);
        vector<pii>q;
        vector<int>ans(m);
        for(int i=0; i<m; i++)
        {
            int x;
            scanf("%d",&x);
            q.pb(pii(x,i));
        }
        sort(q.begin(),q.end(),cmpp);
        mp[-1]=-1;
        for(int i=0,j=0; i<m; i++)
        {
            while(j<n-1 && ab[nd[j]]>ab[q[i].fs])
            {
                update(1,1,n-1,L[nd[j]],lyl[nd[j]]);
                j++;
            }
            ans[q[i].sc]=mp[query(1,1,n-1,L[q[i].fs],R[q[i].fs])];
        }
        for(int i=0; i<m; i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
