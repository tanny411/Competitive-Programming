#include<bits/stdc++.h>
#define pb push_back
#define fs first
#define sc second
using namespace std;
const int blksiz=175;
int tree[175][40010];
/*
void update(int blk,int node,int b,int e,int in,int val)
{
    if(b==e && b==in)
    {
        tree[blk][node]+=val;
        return;
    }
    int m=(b+e)/2;
    if(in<=m) update(blk,node*2,b,m,in,val);
    else update(blk,node*2+1,m+1,e,in,val);
    tree[blk][node]=tree[blk][node*2]+tree[blk][node*2+1];
}
int query(int blk,int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j)
    {
        return tree[blk][node];
    }
    else if(j<b || e<i) return 0;
    int m=(b+e)/2;
    return query(blk,node*2,b,m,i,j)+query(blk,node*2+1,m+1,e,i,j);
}
*/
int query(int blk,int ind)
{
    int sum=0;
    while(ind<=10000)
    {
        sum+=tree[blk][ind];
        ind=ind + (ind & -ind);
    }
    return sum;
}
void update(int blk,int ind,int val)
{
    while(ind>0)
    {
        tree[blk][ind]+=val;
        ind=ind - (ind & -ind);
    }
}

int main()
{
    memset(tree,0,sizeof tree);
    int n;
    scanf("%d",&n);
    vector<int>v(n+3);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v[i]);
        //update(i/blksiz,1,1,10000,v[i],1);
        update(i/blksiz,v[i],1);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int p;
        scanf("%d",&p);
        if(p)
        {
            int i,j,k;
            scanf("%d%d%d",&i,&j,&k);
            int ans=0;
            if(i>j)  swap(i,j);
            while(i<=j && i%blksiz!=0) {ans+=(v[i]>k)?1:0; i++;}
            while(i<=j && j%blksiz!=(blksiz-1) ) {ans+=(v[j]>k)?1:0; j--;}
            if(i<j)
            {
                int bb=i/blksiz;
                int eb=j/blksiz;
                for(int blk=bb;blk<=eb;blk++)
                {
                    //ans+=query(blk,1,1,10000,k+1,10000);
                    ans+=query(blk,k+1);
                }
            }
            printf("%d\n",ans);
        }
        else
        {
            int i,val;
            scanf("%d%d",&i,&val);
//            update(i/blksiz,1,1,10000,v[i],-1);
//            update(i/blksiz,1,1,10000,val,1);
            update(i/blksiz,v[i],-1);
            update(i/blksiz,val,1);
            v[i]=val;
        }
    }
    return 0;
}
