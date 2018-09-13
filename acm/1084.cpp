#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define fs first
#define sc second

using namespace std;
int tree[300000];
void build(int node,int b,int e){
    if(b==e);
    else {
        int m=(b+e)/2;
        build(node*2,b,m);
        build(node*2+1,m+1,e);
    }
    tree[node]=1<<30;
}
void update(int node,int b,int e,int i,int val){
    if(b==i && b==e) tree[node]=val;
    else{
        int m=(b+e)/2;
        if(i<=m) update(node*2,b,m,i,val);
        else update(node*2+1,m+1,e,i,val);
        tree[node]=min(tree[node*2],tree[node*2+1]);
    }
}
int query(int node,int b,int e,int i,int j)
{
    if(i<=b && e<=j) return tree[node];
    if(j<b || e<i) return 1<<30;
    int m=(b+e)/2;
    return min(query(node*2,b,m,i,j),query(node*2+1,m+1,e,i,j));
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++) cin>>v[i];
        sort(v.begin(),v.end());
        build(1,0,n-1);
        //update(1,0,n-1,0,1<<30);
        //update(1,0,n-1,1,1<<30);
        int ans=-1;
        for(int i=2;i<n;i++){
            int in=lower_bound(v.begin(),v.end(),v[i]-2*k)-v.begin();
            if(i-in+1<3); //update(1,0,n-1,i,1<<30);
            else if (in==0) update(1,0,n-1,i,1);
            else{
                int q=query(1,0,n-1,in-1,i-1);
                update(1,0,n-1,i,q+1);
            }
        }
        ans=query(1,0,n-1,n-1,n-1);
        if(ans==1<<30) ans=-1;
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
