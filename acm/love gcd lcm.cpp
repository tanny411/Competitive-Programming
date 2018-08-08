#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define md 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

#define mx 300000

vector<pii>primefact[mx+2];

void sieve()
{
    for(int i=2; i<=mx; i+=2)
    {
        int x=i;
        int cnt=0;
        while(x%2==0)
        {
            x/=2;
            cnt++;
        }
        primefact[i].pb(pii(2,cnt));
    }
    for(int i=3; i<=mx; i+=2)
    {
        if(primefact[i].empty())
        {
            for(int j=i; j<=mx; j+=i)
            {
                int x=j;
                int cnt=0;
                while(x%i==0)
                {
                    x/=i;
                    cnt++;
                }
                primefact[j].pb(pii(i,cnt));
            }
        }
    }
}
vector<int>v,treemx,treemn,lazy;
void build(int node,int b,int e)
{
    if(b==e) treemx[node]=treemn[node]=v[b];
    else
    {
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        treemx[node]=max(treemx[node*2],treemx[node*2+1]);
        treemn[node]=min(treemn[node*2],treemn[node*2+1]);
    }
}
void update(int node,int b,int e,int i,int j,int val)
{
    if(i<=b && e<=j)
    {
        lazy[node]+=val;
    }
    if(lazy[node]!=0)
    {
        treemn[node]+=lazy[node];
        treemx[node]+=lazy[node];
        if(b!=e)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(i<=b && e<=j) return;
    if(j<b || e<i) return;
    int m=(b+e)/2;
    update(node*2,b,m,i,j,val);
    update(node*2+1,m+1,e,i,j,val);
    treemx[node]=max(treemx[node*2],treemx[node*2+1]);
    treemn[node]=min(treemn[node*2],treemn[node*2+1]);
}

pii query(int node,int b,int e,int i,int j)
{
    if(lazy[node]!=0)
    {
        treemn[node]+=lazy[node];
        treemx[node]+=lazy[node];
        if(b!=e)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(j<b || e<i) return pii(0,1<<30);
    if(i<=b && e<=j) return pii(treemx[node],treemn[node]);
    int m=(b+e)/2;
    pii x=query(node*2,b,m,i,j);
    pii y=query(node*2+1,m+1,e,i,j);
    return pii(max(x.fs,y.fs),min(x.sc,y.sc));
}

int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    /*for(int i=0;i<21;i++)
    {
        cout<<"\n"<<i<<":";
        for(int j=0;j<primefact[i].size();j++)
        {
            cout<<" ("<<primefact[i][j].fs<<" "<<primefact[i][j].sc<<")";
        }
    }*/
    vector<ll>B(mx+3,1);
    unordered_map<int,int>mp;
    for(int i=2;i<=mx;i++)
    {
        ll ans=B[i-1];
        for(int j=0;j<primefact[i].size();j++)
        {
            int p=primefact[i][j].fs;
            int cnt=primefact[i][j].sc;
            if(cnt>mp[p])
            {
                int brr=cnt-mp[p];
                mp[p]=cnt;
                while(brr--)
                {
                    ans=(ans*p)%md;
                }
            }
        }
        B[i]=ans;
    }
    B[0]=0;
    //for(int i=0;i<21;i++) cout<<" "<<B[i]; cout<<endl;
    int n,m;
    cin>>n>>m;
    v=vector<int>(n);
    treemx=vector<int>(4*n);
    treemn=vector<int>(4*n);
    lazy=vector<int>(4*n);
    for(int i=0;i<n;i++) cin>>v[i];
    build(1,0,n-1);
    while(m--)
    {
        int type;
        cin>>type;
        if(type==0)
        {
            int i,j,p;
            cin>>i>>j>>p;
            update(1,0,n-1,i,j,p);
        }
        else
        {
            int i,j;
            cin>>i>>j;
            pii an=query(1,0,n-1,i,j);
            int ans;
            if(type==1) ans=an.fs;
            else ans=an.sc;
            cout<<B[ans]<<endl;
        }
    }
    return 0;
}

