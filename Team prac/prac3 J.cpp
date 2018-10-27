#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define inf 1000000007

#define ll long long
#define LLU unsigned long long

#define mx 1000010

#define sc(x) scanf("%lld",&x)

using namespace std;
vector<ll>ara,half;
char s[mx];
ll tree[4*mx];
void build(int node,int b,int e)
{
    if(b==e) tree[node]=ara[b];
    else{
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        tree[node]=min(tree[node*2],tree[node*2+1]);
    }
}
ll query(ll node,int b,int e,int i,int j)
{
    if(b>=i && e<=j) return tree[node];
    else if(i>e || j<b) return inf;
    else{
        int m=(b+e)/2;
        ll l=query(node*2,b,m,i,j);
        ll r=query(node*2+1,m+1,e,i,j);
        l=min(l,r);
        return l;
    }
}
int main()
{
    ll t,test=1;
    sc(t);
    while(t--)
    {
        ll n,d;
        sc(n);
        sc(d);
        ll dist=2*n;
        scanf("%s",s);
        ll mn=inf;
        ara=half=vector<ll>(n);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='/') ara[i]=dist++,half[i]=1;
            else if(s[i]=='\\') ara[i]=--dist,half[i]=1;
            else ara[i]=dist;
            mn=min(mn,ara[i]);
        }
        //for(int i=0;i<n;i++) cout<<" "<<ara[i]; cout<<endl;
        mn=-mn;
        //or(int i=0;i<n;i++) ara[i]-=mn;
        build(1,0,n-1);
        for(int i=1;i<n;i++)
        {
            ara[i]+=ara[i-1];
            half[i]+=half[i-1];
        }
        //for(int i=0;i<n;i++) cout<<" "<<ara[i]; cout<<endl;
        double out=1e20;
        for(int i=d-1;i<n;i++)
        {
            ll q=query(1,0,n-1,i-d+1,i);
            ll sum=ara[i]-(i>=d?ara[i-d]:0);
            ll h=half[i]-(i>=d?half[i-d]:0);
            out=min(out,1.0*sum-1.0*d*q+0.5*h);
        }
        //cout<<out<<endl;
        printf("Case #%lld: %.1lf\n",test++,out);
        //cout<<"Case #"<<test++<<": "<<fixed<<setprecision(1)<<out<<endl;
    }
    return 0;
}
