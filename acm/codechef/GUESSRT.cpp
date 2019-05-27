#include<bits/stdc++.h>
#define fs first
#define sc second
#define md 1000000007
#define LL long long
#define LLU unsigned long long
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

LL bg(LL base, LL power){
    if(power==0) return 1LL;
    if(power==1) return base%md;
    LL x=bg(base, power/2);
    x=(x*x)%md;
    if(power&1) x=(x*base)%md;
    return x;
}

LL inv(LL base){
    return bg(base, md-2);
}

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--){
        LL n,k,m;
        cin>>n>>k>>m;
        LL x=m/2 + 1;
        if(!(m&1)) x--;
        LL num=((bg(n-1,x)*inv(bg(n,x)))%md + md)%md;
        LL num2=0;
        if(!(m&1)) num2=((num*inv(n+k))%md + md)%md;
        num=(1-num+md)%md;
        num=(num+num2)%md;
        num=(num+md)%md;
        cout<<num<<endl;
    }
    return 0;
}