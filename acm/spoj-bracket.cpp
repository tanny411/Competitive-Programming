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

using namespace std;
string s;
struct data{
    int unmatchedLeft,unmatchedRight;
}tree[120000];
data milao(data l,data r)
{
    data ret;
    ret.unmatchedLeft=l.unmatchedLeft+r.unmatchedLeft-min(l.unmatchedLeft,r.unmatchedRight);
    ret.unmatchedRight=l.unmatchedRight+r.unmatchedRight-min(l.unmatchedLeft,r.unmatchedRight);
    return ret;
}
void build(int node,int b,int e)
{
    if(b==e) {
        if(s[b]=='(') tree[node].unmatchedLeft=1,tree[node].unmatchedRight=0;
        else tree[node].unmatchedLeft=0,tree[node].unmatchedRight=1;
    }
    else{
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
        tree[node]=milao(tree[node*2],tree[node*2+1]);
    }
}
void update(int node,int b,int e,int in)
{
    if(b==e && b==in)
    {
       tree[node].unmatchedLeft=1-tree[node].unmatchedLeft;
       tree[node].unmatchedRight=1-tree[node].unmatchedRight;
    }
    else{
        int m=(b+e)/2;
        if(in<=m) update(node*2,b,m,in);
        else update(node*2+1,m+1,e,in);
        tree[node]=milao(tree[node*2],tree[node*2+1]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t=10,test=1;
    while(t--)
    {
        int n,m;
        cin>>n>>s;
        build(1,0,n-1);
        cout<<"Test "<<test++<<":\n";
        cin>>m;
        while(m--)
        {
            int k;
            cin>>k;
            if(k) update(1,0,n-1,k-1);
            else if(tree[1].unmatchedLeft==0 && tree[1].unmatchedRight==0) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}

