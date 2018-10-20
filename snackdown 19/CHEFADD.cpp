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
int c,lastpos;
int dp[32][32][32][2];
int rec(int pos,int na,int nb,int carry)
{
    if(na<0 || nb<0) return 0;
    if(pos>=lastpos) return (carry==0 && na==0 && nb==0);
    int &ret=dp[pos][na][nb][carry];
    if(ret!=-1) return ret;
    ret=0;
    if(!carry)
    {
        if(c&(1<<pos)) ret=rec(pos+1,na-1,nb,0)+rec(pos+1,na,nb-1,0);
        else ret=rec(pos+1,na,nb,0)+rec(pos+1,na-1,nb-1,1);
    }
    else
    {
        if(c&(1<<pos)) ret=rec(pos+1,na-1,nb-1,1)+rec(pos+1,na,nb,0);
        else ret=rec(pos+1,na-1,nb,1)+rec(pos+1,na,nb-1,1);
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b>>c;
        int na=0,nb=0,temp=c;
        lastpos=0;
        while(a){
            if(a&1) na++;
            a/=2;
        }
        while(b){
            if(b&1) nb++;
            b/=2;
        }
        while(temp){
            lastpos++;
            temp/=2;
        }
        memset(dp,-1,sizeof dp);
        cout<<rec(0,na,nb,0)<<endl;
    }
    return 0;
}

