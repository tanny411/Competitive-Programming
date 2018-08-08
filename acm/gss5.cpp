#include<bits/stdc++.h>
using namespace std;
vector<int>v;
struct data
{
    int mx=0,sum=0,pr=0,sf=0;
};
data tree[40000];
data mergeit(data a,data b)
{
    data n;
    n.sum=a.sum+b.sum;
    n.pr=max(a.pr,a.sum+b.pr);
    n.sf=max(b.sum+a.sf,b.sf);
    n.mx=max(max(a.mx,b.mx),a.sf+b.pr);
    return n;
}
void build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].mx=tree[node].sum=tree[node].pr=tree[node].sf=v[b];
        return;
    }
    else
    {
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        tree[node]=mergeit(tree[node*2],tree[node*2+1]);
        return;
    }
}
data query(int node,int b,int e,int i,int j)
{
    if(i>j || e<i || j<b)
    {
        data a;
        a.sum=0;
        a.mx=a.pr=a.sf=INT_MIN;
        return a;
    }
    else if(i<=b && e<=j)
    {
        return tree[node];
    }
    else
    {
        int m=(b+e)/2;
        return mergeit(query(node*2,b,m,i,j),query(node*2+1,m+1,e,i,j));
    }
}
int main()
{
    int n,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        v.clear();
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            v.push_back(x);
        }
        build(1,0,n-1);
        //cout<<tree[1].mx<<" "<<tree[1].sum<<" "<<tree[1].pr<<" "<<tree[1].sf<<endl;
        scanf("%d",&m);
        while(m--)
        {
            int x1,x2,y1,y2;
            x1--;x2--;y1--;y2--;
            scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
            int ans;
            if(x2<y1)
            {
                ans=query(1,0,n-1,x1,x2).sf+query(1,0,n-1,x2+1,y1-1).sum+query(1,0,n-1,y1,y2).pr;
            }
            else
            {
                ans=query(1,0,n-1,y1,x2).mx;
                ans=max(ans,query(1,0,n-1,x1,y1).sf+query(1,0,n-1,y1+1,y2).pr);
                ans=max(ans,query(1,0,n-1,x1,x2).sf+query(1,0,n-1,x2+1,y2).pr);
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
