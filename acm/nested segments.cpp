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

using namespace std;
int tree[1200000];

void update(int node,int b,int e,int i,int j,int val)
{
    if(i<=b && e<=j) tree[node]=val;
    if(tree[node]!=0)
    {
        if(b!=e)
        {
            tree[node*2]=tree[node];
            tree[node*2+1]=tree[node];
            tree[node]=0;
        }
    }
    if(i<=b && e<=j) return;
    if(e<i || b>j) return;
    int m=(b+e)/2;
    update(node*2,b,m,i,j,val);
    update(node*2+1,m+1,e,i,j,val);
}

int query(int node,int b,int e,int i)
{
    if(tree[node]!=0)
    {
        if(b!=e)
        {
            tree[node*2]=tree[node];
            tree[node*2+1]=tree[node];
            tree[node]=0;
        }
    }
    if(b==e && b==i) return tree[node];
    int m=(b+e)/2;
    if(i<=m) return query(node*2,b,m,i);
    else return query(node*2+1,m+1,e,i);
}
int main()
{
    int n;
    cin>>n;
    vector<pii>line(n);
    vector<int>len(n);
    map<int,int>mp;
    set<int>s;
    int cnt=1;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        line[i].fs=x;
        line[i].sc=y;
        len[i]=y-x+1;
        s.insert(x);
        s.insert(y);
    }
    int q;
    cin>>q;
    vector<int>Q(q);
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        Q[i]=x;
        s.insert(x);
    }
    int tot=s.size();
    for(auto i:s)
    {
        mp[i]=cnt++;
    }
    for(int i=0;i<n;i++)
    {
        update(1,1,tot,mp[line[i].fs],mp[line[i].sc],i+1);
    }
    for(int i=0;i<q;i++)
    {
        int x=query(1,1,tot,mp[Q[i]]);
        cout<<(x==0?-1:x)<<endl;
    }
    return 0;
}

