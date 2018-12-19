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
#define Max 1<<30;
using namespace std;

struct edge
{
    int u,v,w;

    edge(int a,int b,int c)
    {
        u=a;v=b;w=c;
    }
};

int main()
{
    vector<edge>v;
    int dist[2010];
    int t,n,m,i,j,a,b,c,flag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        v.clear();
        for(i=0;i<n;i++) dist[i]=Max;
        i=m;
        while(i--)
        {
            scanf("%d %d %d",&a,&b,&c);
            v.pb(edge(a,b,c));
        }
        for(i=0;i<n;i++)
        {
            flag=1;
            for(j=0;j<m;j++)
            {
                if(dist[v[j].u]+v[j].w < dist[v[j].v])
                {
                    dist[v[j].v]=dist[v[j].u]+v[j].w;
                    flag=0;
                }
            }
            if(flag) break;
        }
        if(i==n) printf("possible\n");
        else printf("not possible\n");
    }
    return 0;
}
