#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
int tree[50001*35][2];
int node;
void tr_insert(int xr,int intbit){
    int cur=0;
    // cout<<xr<<" << ";
    for(int i=intbit;i>=0;i--){
        int mask=1<<i;
        int d=(xr&mask)>0;
        if(tree[cur][d]==-1){
            tree[cur][d]=++node;
        }
        cur=tree[cur][d];
        // cout<<d<<" ";
    }
    // cout<<endl;
}
int main(){
    ll cas=1,t,intbit=31;
    cin>>t;
    // cout<<(1<<31)<<endl;
    while(t--){
        ll n,xr=0,cur,x;
        cin>>n;
        node=0;
        ll mmin=100000000,mmax=0;
        memset(tree,-1,sizeof tree);
        
        //insert initial sum of zero
        tr_insert(0,intbit);

        while(n--){
            cin>>x;
            xr^=x;
            //why do we xor?
            //i--j xor = x; i--k xor=y; then j--k xor=x^y
            //its like subtracting the i--j part from the total sum
            //then we minimize and maximize the sum thus obtained
            
            //minimize
            cur=0;
            ll mn=0;
            for(int i=intbit;i>=0;i--){
                ll mask=1<<i;
                int d=(xr&mask)>0;//same bit khujchi
                if(tree[cur][d]==-1) d=!d,mn+=mask;
                cur=tree[cur][d];
            }

            //maximize
            cur=0;
            ll mx=0;
            for(int i=intbit;i>=0;i--){
                ll mask=1<<i;
                int d=(xr&mask)==0;//different bit khujchi
                int diff=1;
                if(tree[cur][d]==-1) d=!d,diff=0;
                cur=tree[cur][d];
                if(diff)mx+=mask;
            }

            // cout<<x<<" "<<mn<<" "<<mx<<endl;
            mmax=max(mx,mmax);
            mmin=min(mmin,mn);

            tr_insert(xr,intbit);
        }
        cout<<"Case "<<cas++<<": "<<mmax<<" "<<mmin<<endl;
    }

    return 0;
}