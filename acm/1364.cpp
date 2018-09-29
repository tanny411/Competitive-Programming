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

double dp[20][20][20][20][5][5];
int vis[20][20][20][20][5][5];
int test=1;
int C,D,H,S;

double rec(int c,int d,int h,int s,int j1,int j2)
{
    int cc=(13-c)+(j1==1)+(j2==1);
    int dd=(13-d)+(j1==2)+(j2==2);
    int hh=(13-h)+(j1==3)+(j2==3);
    int ss=(13-s)+(j1==4)+(j2==4);

    if(cc>=C && dd>=D && hh>=H && ss>=S) return 0.0;

    int &v=vis[c][d][h][s][j1][j2];
    double &ret=dp[c][d][h][s][j1][j2];
    if(v==test) return ret;
    v=test;

    ret=0.0;

    int j=(j1==0)+(j2==0);
    double tot=c+d+h+s+j;

    if(c>0) ret+=(c/tot)*(1+rec(c-1,d,h,s,j1,j2));
    if(d>0) ret+=(d/tot)*(1+rec(c,d-1,h,s,j1,j2));
    if(h>0) ret+=(h/tot)*(1+rec(c,d,h-1,s,j1,j2));
    if(s>0) ret+=(s/tot)*(1+rec(c,d,h,s-1,j1,j2));

    double jans,temp;
    if(!j1){
        jans=(j/tot)*(1+rec(c,d,h,s,1,j2));
        temp=(j/tot)*(1+rec(c,d,h,s,2,j2)); jans=min(jans,temp);
        temp=(j/tot)*(1+rec(c,d,h,s,3,j2)); jans=min(jans,temp);
        temp=(j/tot)*(1+rec(c,d,h,s,4,j2)); jans=min(jans,temp);
        ret+=jans;
    }
    else if(!j2){ ///notice the else if, we take only one joker at a time
        jans=(j/tot)*(1+rec(c,d,h,s,j1,1));
        temp=(j/tot)*(1+rec(c,d,h,s,j1,2)); jans=min(jans,temp);
        temp=(j/tot)*(1+rec(c,d,h,s,j1,3)); jans=min(jans,temp);
        temp=(j/tot)*(1+rec(c,d,h,s,j1,4)); jans=min(jans,temp);
        ret+=jans;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>C>>D>>H>>S;
        int j=(C>13?C-13:0) + (D>13?D-13:0) + (H>13?H-13:0) + (S>13?S-13:0) ;
        if(j>2) cout<<"Case "<<test++<<": "<<-1<<endl;
        else cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<rec(13,13,13,13,0,0)<<endl;
    }
    return 0;
}
