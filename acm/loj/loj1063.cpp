#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define ll long long
#define llu unsigned long long
#define eps .0000001
#define zero 0.0000000000000001
#define floatless(a,b) ( (a-b)<=eps )
#define floatequal(a,b) ( floatless(a,b) && floatless(b,a) )
#define incircle_r(a,b,c) 2*area(triangle)/perimeter(triangle)
#define circumcircle_R(a,b,c) a*b*c/sqrt( (a+b+c)*(a+b-c)*(b+c-a)*(c+a-b) )
#define circumcircle_2R_sinelaw a/sinA
#define triarea(a,b,c) sqrt( (a+b+c)*(b+c-a)*(a-b+c)*(a+b-c) )/9
#define mediantoarea(a,b,c) (4/3)*triarea(a,b,c)
#define output freopen("out.txt","w",stdout);
#define input freopen("in.txt","r",stdout);
using namespace std;

int dis[10001];
int low[10001];
vector<int>v[10001];
int art[10001];
int tim;

void articulation_point(int u,int parent)
{
    dis[u]=low[u]=++tim;
    int nc=0;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(dis[y]==-1)
        {
            nc++;
            articulation_point(y,u);
            low[u]=min(low[u],low[y]);
            if(low[y]>=dis[u]) art[u]=1;
        }
        else if(y!=parent)
        {
            low[u]=min(low[u],dis[y]);
        }
    }
    if(parent==-1)
    {
        if(nc>1) art[u]=1;
        else art[u]=0;
    }
}

int main()
{
    int t,x,y,cas=1,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            dis[i]=-1;
            art[i]=0;
        }
        while(m--)
        {
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        tim=0;
        for(int i=1;i<=n;i++)
        {
            if(dis[i]==-1)
            {
                articulation_point(i,-1);
            }
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(art[i])
            {
                cnt++;
            }
        }
        printf("Case %d: %d\n",cas++,cnt);
    }
    return 0;
}
