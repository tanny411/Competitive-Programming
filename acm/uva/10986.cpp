#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define Max 1<<30;

class comp
{
public:
    bool operator()(pii a,pii b)const
    {
        return a.second>b.second;
    }
};

vector<pii>v[20001];
int nodes,level[20001];

int dijkstra(int source,int des)
{
    for(int i=0;i<nodes;i++) level[i]=Max;
    level[source]=0;
    priority_queue<pii,vector<pii>,comp>q;
    q.push(pii(source,level[source]));
    while(!q.empty())
    {
        pii p=q.top();
        if(p.first==des) return level[des];
        q.pop();
        for(int i=0;i<v[p.first].size();i++)
        {
            int k=v[p.first][i].first;
            if(level[k]>level[p.first]+v[p.first][i].second)
            {
               level[k]=level[p.first]+v[p.first][i].second;
               q.push(pii(k,level[k]));
            }
        }
    }
    return -1;
}

int main()
{
    int t,T,m,a,b,w,s,d;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d %d",&nodes,&m,&s,&d);
        for(int i=0;i<nodes;i++) v[i].clear();
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&w);
            v[a].push_back(pii(b,w));
            v[b].push_back(pii(a,w));
        }
        m=dijkstra(s,d);
        if(m==-1) printf("Case #%d: unreachable\n",t);
        else printf("Case #%d: %d\n",t,m);
    }
    return 0;
}
