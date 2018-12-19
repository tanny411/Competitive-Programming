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
using namespace std;

class comp
{
public:
    bool operator()(pii a,pii b)
    {
        return a.second>b.second;
    }
};

vector<pii>v[5001];
int n;
ll dists[5001],distt[5001];

void dijkstra(int s, ll dist[])
{
    for(int i=0;i<=n;i++) dist[i]=1<<30;
    dist[s]=0;
    priority_queue<pii,vector<pii>,comp>q;
    q.push(pii(s,0));
    while(!q.empty())
    {
        pii top=q.top();
        q.pop();
        for(int i=0; i<v[top.first].size() ;i++)
        {
            if(dist[v[top.first][i].first]>dist[top.first]+v[top.first][i].second)
            {
                dist[v[top.first][i].first]=dist[top.first]+v[top.first][i].second;
                q.push(pii(v[top.first][i].first,dist[v[top.first][i].first]));
            }
        }
    }
}

int main()
{
    int t,m,cas=1,a,b,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=0;i<=n;i++) v[i].clear();
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&w);
            v[a].pb(pii(b,w));
            v[b].pb(pii(a,w));
        }
        dijkstra(1,dists);
        dijkstra(n,distt);
        ll minpath=dists[n],secmin=1<<30;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                ll x=dists[i]+v[i][j].second+distt[v[i][j].first];
                ll y=dists[i]+3*v[i][j].second+distt[v[i][j].first];
                if(x!=minpath && x<secmin)
                {
                    secmin=x;
                }
                else if(y!=minpath && y<secmin)
                {
                    secmin=y;
                }
            }
        }
        //cout<<"minpath="<<dists[n]<<" "<<distt[1]<<endl;
        printf("Case %d: %lld\n",cas++,secmin);
    }
    return 0;
}
