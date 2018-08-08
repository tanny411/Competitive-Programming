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

vector<pii>ara;
int tree[400000];

struct data
{
    int k,i,j,in;
};

bool cmp(data a,data b)
{
    return a.k < b.k;
}

void update(int node,int b,int e,int val,int in)
{
    if(b==e && b==in) {tree[node]=1; return;}
    else if(b<=in and in<=e)
    {
        int m=(b+e)/2;
        int lc=2*node;
        int rc=lc+1;
        update(lc,b,m,val,in);
        update(rc,m+1,e,val,in);
        tree[node]=tree[lc]+tree[rc];
        return;
    }
}
int query(int node,int b,int e,int i,int j)
{
    if(i<=b and e<=j) return tree[node];
    else if(i>e or j<b) return 0;
    else
    {
        int m=(b+e)/2;
        int lc=2*node;
        int rc=lc+1;
        return query(lc,b,m,i,j)+query(rc,m+1,e,i,j);
    }
}
int main()
{
    int t,cas=1;
    scanf("%d",&t);
    while(t--)
    {
        ara.clear();
        memset(tree,0,sizeof(tree));
        int n,q;
        scanf("%d %d",&n,&q);
        for(int i=0; i<n; i++)
        {
            int x;
            scanf("%d",&x);
            ara.pb({x,i});
        }
        sort(ara.begin(),ara.end());
        vector<data>v(q);
        for(int i=0; i<q; i++)
        {
            scanf("%d %d %d",&v[i].i,&v[i].j,&v[i].k);
            if(v[i].j<v[i].i) swap(v[i].i,v[i].j);
            v[i].in=i;
        }
        sort(v.begin(),v.end(),cmp);
        vector<int>ans(q);
        for(int i=0,pos=0; i<q; i++)
        {
            while(pos<n and ara[pos].fs<=v[i].k)
            {
                update(1,0,n-1,ara[pos].fs,ara[pos].sc);
                pos++;
            }
            ans[v[i].in]=query(1,0,n-1,v[i].i,v[i].j);
        }
        printf("Case %d:\n",cas++);
        for(int i=0; i<q; i++)
        {
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}


