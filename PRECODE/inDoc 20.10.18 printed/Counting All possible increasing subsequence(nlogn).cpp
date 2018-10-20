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
ll tree[400000];
ll query (int node,int b, int e,int i,int j)
{
    if(i<=b and e<=j) return tree[node];
    else if(i>e || j<b) return 0;
    else
    {
        int m=(b+e)/2;
        int lc=node*2;
        int rc=lc+1;
        return query(lc,b,m,i,j)+query(rc,m+1,e,i,j);
    }
}
void update (int node,int b, int e,int val,int i)
{
    if(b==e && b==i) tree[node]=val;
    else if(i>=b and i<=e)
    {
        int m=(b+e)/2;
        int lc=node*2;
        int rc=lc+1;
        update(lc,b,m,val,i);
        update(rc,m+1,e,val,i);
        tree[node]=tree[lc]+tree[rc];
    }
}
bool cmp(pii a,pii b)
{
    if(a.fs==b.fs) return a.sc>b.sc; ///(for strictly increasing)
    else return a.fs<b.fs;
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        memset(tree,0,sizeof tree);
        vector<pii>ara(n+1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&ara[i].fs);
            ara[i].sc=i;
        }
        ll ans=0;
        ll a=0;
        sort(ara.begin(),ara.end(),cmp);
        for(int i=1;i<=n;i++)
        {
            a=query(1,1,n,1,ara[i].sc);
            update(1,1,n,(a+1)%md,ara[i].sc);
        }
        printf("Case %d: %lld\n",cas++,tree[1]%md);
    }
    return 0;
}
