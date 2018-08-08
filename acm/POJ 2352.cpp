#include<cstdio>
#include<vector>

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
#define mx 32000
int tree[4*32000];
void update(int node,int b,int e,int x)
{
    if(b==e && b==x) {tree[node]++; return;}
    else if(b<=x && x<=e)
    {
        int m=(b+e)/2;
        update(node*2,b,m,x);
        update(node*2+1,m+1,e,x);
        tree[node]=tree[node*2]+tree[node*2+1];
        return;
    }
    else return;

}
int query(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j) return tree[node];
    else if(i>e || j<b) return 0;
    else
    {
        int m=(b+e)/2;
        return query(node*2,b,m,i,j)+query(node*2+1,m+1,e,i,j);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[query(1,0,mx,0,x)]++;
        update(1,0,mx,x);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",v[i]);
    }
    return 0;
}

