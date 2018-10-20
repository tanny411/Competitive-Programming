#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


ll dp[20][20][20];
vector<int>v;
int siz,hsiz;

ll pal(int ind,int leftmost_lo,int leftmost_hi)
{
    if(ind<=hsiz)
    {
        if(leftmost_lo>=leftmost_hi) return 1;
        else return 0;
    }
    if(dp[ind][leftmost_lo][leftmost_hi]!=-1) return dp[ind][leftmost_lo][leftmost_hi];
    ll ret=0;
    int start;
    if(ind==siz) start=1;
    else start=0;
    int n=siz-ind+1;
    for(int i=start; i<=9; i++)
    {
        int newleftmost_lo=leftmost_lo;
        int newleftmost_hi=leftmost_hi;
        if(i<v[ind] && ind>newleftmost_lo) newleftmost_lo=ind;
        if(i<v[n] && n>newleftmost_lo) newleftmost_lo=n;
        if(i>v[ind] && ind>newleftmost_hi) newleftmost_hi=ind;
        if(i>v[n] && n>newleftmost_hi) newleftmost_hi=n;
        ret+=pal(ind-1,newleftmost_lo,newleftmost_hi);
    }
    return dp[ind][leftmost_lo][leftmost_hi]=ret;
}
ll ara[20];
int main()
{
    ara[0]=1;
    ll add=9;
    for(int i=1; i<=17; i+=2)
    {
        ara[i]=ara[i-1]+add;
        ara[i+1]=ara[i]+add;
        add*=10;
    }
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        v.clear();
        if(a>b) swap(a,b);
        a--;
        ll ans1=0;
        if(a>=0)
        {
            v.pb(0);
            if(a==0) v.pb(0);
            else
            {
                while(a)
                {
                    v.pb(a%10);
                    a/=10;
                }
            }
            memset(dp,-1,sizeof dp);
            siz=v.size()-1;
            hsiz=siz/2;
            ans1=pal(siz,0,0);
            v.clear();
            ans1+=ara[siz-1];
        }
        v.pb(0);
        if(b==0) v.pb(0);
        else
        {
            while(b)
            {
                v.pb(b%10);
                b/=10;
            }
        }
        siz=v.size()-1;
        hsiz=siz/2;
        memset(dp,-1,sizeof dp);
        ll ans2=pal(siz,0,0);
        ans2+=ara[siz-1];
        cout<<"Case "<<cas++<<": "<<ans2-ans1<<"\n";
    }
    return 0;
}
