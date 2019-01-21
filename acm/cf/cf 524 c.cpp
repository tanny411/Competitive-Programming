#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<LL,LL>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;
pii fun(LL h,LL b,int c)///pii (1,0) black white
{
    LL x=0,y=0,x1=0,y1=0;//1,0
    x=y=x1=y1=b/2;
    if(b&1) {
        if(c) x++,y1++;
        else y++,x1++;
    }
    LL totx=(h/2)*x+(h/2)*x1;
    LL toty=(h/2)*y+(h/2)*y1;
    if(h&1) {
        totx+=x;
        toty+=y;
    }
    return pii(totx,toty);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        LL n,m,x1,y1,x2,y2;
        cin>>n>>m;
        auto ans=fun(n,m,0);

        cin>>x1>>y1>>x2>>y2;
        auto p=fun(y2-y1+1,x2-x1+1,(x1+y1)%2);
        ans.fs-=p.fs;
        ans.sc-=p.sc;
        ans.sc+=(y2-y1+1)*(x2-x1+1);

        LL x3,x4,y3,y4;
        cin>>x3>>y3>>x4>>y4;
        p=fun(y4-y3+1,x4-x3+1,(x3+y3)%2);
        ans.fs-=p.fs;
        ans.sc-=p.sc;
        ans.fs+=(y4-y3+1)*(x4-x3+1);

        x1=max(x1,x3);
        y1=max(y1,y3);
        x2=min(x2,x4);
        y2=min(y2,y4);

        if(x1<=x2 && y1<=y2)
        {
            p=fun(y2-y1+1,x2-x1+1,(x1+y1)%2);
            ans.fs+=p.fs;
            ans.sc+=p.sc;
            ans.sc-=(y2-y1+1)*(x2-x1+1);
        }
        cout<<ans.sc<<" "<<ans.fs<<endl;
    }
    return 0;
}

