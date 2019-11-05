#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
unordered_map<int,int>mp;
int lazy[400000];
void build(int node,int b,int e){
    if(b==e){
        int x;
        cin>>x;
        mp[x]=b;
        lazy[node]=b;
        return;
    }
    int m=(b+e)/2;
    build(node*2,b,m);
    build(node*2+1,m+1,e);
}
int query(int node,int b,int e,int ix){
    if(b==e) return lazy[node];
    
    if(lazy[node]){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    
    int m=(b+e)/2;
    if(ix<=m) return query(node*2,b,m,ix);
    else query(node*2+1,m+1,e,ix);
}
void update(int node,int b,int e,int i,int j){
    if(b!=e && lazy[node]){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if(i<=b && e<=j) {
        lazy[node]+=1;
        return;
    }
    if(j<b || e<i) return;
    int m=(b+e)/2;
    update(node*2,b,m,i,j);
    update(node*2+1,m+1,e,i,j);
}
int main(){
    int n;
    cin>>n;
    memset(lazy,0,sizeof lazy);
    build(1,0,n-1);
    int ans=0;
    for(int i=0;i<n;i++) {
        int x;
        cin>>x;
        ans+=query(1,0,n-1,mp[x])-i;
        update(1,0,n-1,0,mp[x]-1);
    }
    cout<<ans<<endl;
    return 0;
}