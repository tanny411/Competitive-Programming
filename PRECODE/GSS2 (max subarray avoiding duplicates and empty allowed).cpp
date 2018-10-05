///https://www.quora.com/How-can-the-SPOJ-problem-GSS2-be-solved/answer/Brian-Bi?srid=29u8
///http://tiny-code.blogspot.com/2013/07/spoj-1557can-you-answer-these-queries-ii.html
///maximum sum of unique elements subarray in range /*No updates*/
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
#define nd 400004
using namespace std;
vector<ll>v;
ll cur[nd],lazy[nd],best[nd],bestLazy[nd];
bool cmp(ppi a,ppi b)
{
    return a.fs.sc<b.fs.sc;
}
void propagate(int node)
{
    for(int child=2*node;child<=node*2+1;child++){
        bestLazy[child]=max(bestLazy[child],lazy[child]+bestLazy[node]);
        lazy[child]+=lazy[node];
        best[child]=max(best[child],cur[child]+bestLazy[node]);
        cur[child]+=lazy[node];
    }
    lazy[node]=bestLazy[node]=0ll;
}
void update(int node,int b,int e,int i,int j,int val)
{
    if(j<b || i>e) return;
    if(i<=b && e<=j){
        lazy[node]+=val;
        cur[node]+=val;
        bestLazy[node]=max(bestLazy[node],lazy[node]);///for children
        best[node]=max(best[node],cur[node]);///for self
        return;
    }
    ///self work is already done, so we can return without propagating
    ///propagate
    if(b!=e){
        propagate(node);
    }
    int m=(b+e)/2;
    update(node*2,b,m,i,j,val);
    update(node*2+1,m+1,e,i,j,val);
    ///merge
    cur[node]=max(cur[node*2],cur[node*2+1]);
    //best[node]=max(best[node],cur[node]);
    //both correct, use whichever makes more sense
    best[node]=max(best[node*2],best[node*2+1]);
}
ll query(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j) return best[node];
    else if(j<b || i>e) return 0ll;
    else{
        propagate(node);
        int m=(b+e)/2;
        return max(query(node*2,b,m,i,j),query(node*2+1,m+1,e,i,j));
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    v=vector<ll>(n);
    for(int i=0;i<n;i++) scanf("%lld",&v[i]);
    int nq;
    scanf("%d",&nq);
    vector<ppi>q(nq);
    ll ans[nq];
    for(int i=0;i<nq;i++) {scanf("%d%d",&q[i].fs.fs,&q[i].fs.sc); q[i].sc=i;}
    sort(q.begin(),q.end(),cmp);
    map<int,int>mp;///using array will be better O(1)
    for(int i=0,start=0;i<nq;i++)
    {
        int x=q[i].fs.fs;
        int y=q[i].fs.sc;
        x--;
        y--;
        while(start<=y){
            //cout<<start<<" ";
            update(1,0,n-1,mp[v[start]],start,v[start]);
            mp[v[start]]=start+1;
            start++;
        }
        ans[q[i].sc]=query(1,0,n-1,x,y);
    }
    for(int i=0;i<nq;i++) printf("%lld\n",ans[i]);
    return 0;
}

