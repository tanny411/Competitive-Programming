#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

// int tree[400000];
int lazy[400000];
vector<int>ans,inp;

void update(int node,int b,int e,int i,int j){
    if(i<=b && e<=j) {lazy[node]+=1; return;}
    if(j<b || e<i) return;
    if(lazy[node] && b!=e){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    int m=(b+e)/2;
    update(node*2,b,m,i,j);
    update(node*2+1,m+1,e,i,j);
}

void query(int node,int b,int e){
    if(lazy[node] && b!=e){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        lazy[node]=0;
    }
    if(b==e) {ans.pb(lazy[node]);return;}
    int m=(b+e)/2;
    query(node*2,b,m);
    query(node*2+1,m+1,e);
}

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            update(1,0,n-1,max(0,i-x),min(i+x,n-1));
        }
        ans.clear();
        inp.clear();
        query(1,0,n-1);
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            inp.pb(x);
        }
        sort(inp.begin(),inp.end());
        int oops=0;
        for(int i=0;i<n;i++){
            if(inp[i]!=ans[i]) {oops=1;break;}
        }
        if(oops) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}