///tle
#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define inf 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
int n;
string s;
int dx,dy;
int chx[]={0,0,1,-1};
int chy[]={1,-1,0,0};
char ara[]={'U','D','R','L'};
int minimum=inf;
int dfs(int x,int y,int depth,int firstchange,int lastchange)
{
    if(lastchange-firstchange+1>minimum) return inf;
    if(abs(dx-x)+abs(dy-y)>(n-depth)) return inf;
    if(depth==n)
    {
        if(x!=dx || y!=dy) return inf;
        if(firstchange==-1) return 0;
        else return minimum=min(minimum,lastchange-firstchange+1);
    }
    int mn=inf;
    for(int i=0;i<4;i++)
    {
        int fch=firstchange,lch=lastchange;
        int tx=x+chx[i];
        int ty=y+chy[i];
        if(s[depth]!=ara[i]){
            if(firstchange==-1) fch=depth;
            lch=depth;
        }
        mn=min(mn,dfs(tx,ty,depth+1,fch,lch));
    }
    return mn;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    int x,y;
    cin>>n>>s>>x>>y;
    dx=x;dy=y;
    if(abs(x)+abs(y)>n) cout<<"-1"<<endl;
    else{
        int u=0,v=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R') u++;
            else if(s[i]=='L') u--;
            else if(s[i]=='U') v++;
            else v--;
        }
        if(x==u && y==v) cout<<0<<endl;
        else{
            minimum=inf;
            int ans=dfs(0,0,0,-1,-1);
            if(ans<=n) cout<<ans<<endl;
            else cout<<-1<<endl;
        }
    }
    return 0;
}

