///http://tiny-code.blogspot.com/2013/08/spoj-2916can-you-answer-these-queries-v.html
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
using namespace std;
vector<int>v;
struct data{
    int sum,maxsum,prefixsum,suffixsum;
    data(){}
    data(int a):sum(a),maxsum(a),prefixsum(a),suffixsum(a){}
    data(int a,int b,int c,int d):sum(a),maxsum(b),prefixsum(c),suffixsum(d){}
};
data tree[4*200007];
data milao(data l,data r)
{
    data ret;
    ret.sum=l.sum+r.sum;
    ret.prefixsum=max(l.prefixsum,l.sum+r.prefixsum);
    ret.suffixsum=max(r.suffixsum,l.suffixsum+r.sum);
    ret.maxsum=max(l.maxsum,r.maxsum);
    ret.maxsum=max(ret.maxsum,l.suffixsum+r.prefixsum);
    return ret;
}
void build(int node,int b,int e)
{
    if(b==e) tree[node]=data(v[b]);
    else{
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        tree[node]=milao(tree[node*2],tree[node*2+1]);
    }
}
data query(int node,int b,int e,int i,int j)
{
    if(i>j || j<b || i>e) return data(0,-1<<30,-1<<30,-1<<30); ///important:sum=0, other=-inf, cuz others max is taken, sums sum is taken
    if(i<=b && e<=j) return tree[node];
    int m=(b+e)/2;
    data l=query(node*2,b,m,i,j);
    data r=query(node*2+1,m+1,e,i,j);
    return milao(l,r);
}
int main()
{
    //ios_base::sync_with_stdio(false);
    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        v=vector<int>(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
        }
        build(1,0,n-1);
        int m;
        scanf("%d\n",&m);
        while(m--)
        {
            int x1,x2,y1,y2,ans;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            x1--;x2--;y1--;y2--;
            if(y1<x2){///no overlap
                ans=query(1,0,n-1,x1,y1).suffixsum+query(1,0,n-1,y1+1,x2-1).sum+query(1,0,n-1,x2,y2).prefixsum;
            }
            else {///overlap
                ans=query(1,0,n-1,x1,y1).suffixsum+query(1,0,n-1,y1+1,y2).prefixsum;
                ans=max(ans, query(1,0,n-1,x1,x2-1).suffixsum+query(1,0,n-1,x2,y2).prefixsum );
                ans=max(ans, query(1,0,n-1,x2,y1).maxsum );
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
