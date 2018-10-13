#include<bits/stdc++.h>
#define pb push_back
#define Pb pop_back
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define ll long long
#define fs first
#define sc second
///update in range --> turn every element x into sqrt(x) in this range
///query sum of range
using namespace std;
vector<ll>v;
ll tree[400000];
void build(int node,int b,int e)
{
    if(b==e) tree[node]=v[b];
    else{
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
ll query(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j) return tree[node];
    else if(j<b || e<i) return 0ll;
    int m=(b+e)/2;
    return query(node*2,b,m,i,j)+query(node*2+1,m+1,e,i,j);
}
void lazyProp(int node,int b,int e)
{
    if(tree[node]==(e-b+1)) return;
    if(b==e) tree[node]=(ll)sqrt(1.0*tree[node]);
    else{
        int m=(b+e)/2;
        lazyProp(node*2,b,m);
        lazyProp(node*2+1,m+1,e);
        tree[node]=tree[node*2]+tree[node*2+1];
    }
}
void update(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j) {lazyProp(node,b,e); return;}
    else if(j<b || e<i) return;
    int m=(b+e)/2;
    update(node*2,b,m,i,j);
    update(node*2+1,m+1,e,i,j);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int main()
{
    int n,test=1;
    while(scanf("%d",&n)!=EOF)
    {
        v=vector<ll>(n);
        for(int i=0;i<n;i++) scanf("%lld",&v[i]);
        build(1,0,n-1);
        int m;
        scanf("%d",&m);
        printf("Case #%d:\n",test++);
        while(m--)
        {
            int type,x,y;
            scanf("%d%d%d",&type,&x,&y);
            if(x>y) swap(x,y);
            if(!type) update(1,0,n-1,x-1,y-1);
            else printf("%lld\n",query(1,0,n-1,x-1,y-1));
        }
        printf("\n");
    }
    return 0;
}

