#include<bits/stdc++.h>
#define pb push_back
#define Pb pop_back
#define fs first
#define sc second
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define MOD 1000000007
#define LL long long
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
/*----------------------Graph Moves----------------*/
//const int fx[]= {+1,-1,+0,+0};
//const int fy[]= {+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

using namespace std;
pii tree[400000];
vector<int>cost(100004),rem(100004);
void build(int node,int b,int e){
    if(b==e){
        tree[node]=pii(b,cost[b]);
        return;
    }
    int m=(b+e)/2;
    build(node*2,b,m);
    build(node*2+1,m+1,e);
    if(tree[node*2].sc<tree[node*2+1].sc){
        tree[node]=tree[node*2];
    }
    else{
        tree[node]=tree[node*2+1];
    }
}
void update(int node,int b,int e,int i){
    if(b==e && b==i){
        tree[node]=pii(b,INT_MAX);
        return;
    }
    int m=(b+e)/2;
    if(i>m) update(node*2+1,m+1,e,i);
    else update(node*2,b,m,i);
    if(tree[node*2].sc<tree[node*2+1].sc){
        tree[node]=tree[node*2];
    }
    else{
        tree[node]=tree[node*2+1];
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>rem[i];
    for(int i=0;i<n;i++) cin>>cost[i];
    build(1,0,n-1);
    for(int i=0;i<m;i++){
        int t,d;
        cin>>t>>d;
        t--;
        LL tempCost=0;
        int angry=0;
        while(d){
            if(tree[1].sc==INT_MAX){
                angry=1;
                break;
            }
            int p=rem[t];
            int x=min(d,rem[t]);
            d-=x;
            rem[t]-=x;
            tempCost+=(LL)(1ll*cost[t]*x);
            if(rem[t]==0 && p) update(1,0,n-1,t);
            t=tree[1].fs;
        }
        if(!angry) cout<<tempCost<<endl;
        else cout<<0<<endl;
    }
    return 0;
}