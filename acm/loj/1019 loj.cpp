#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define Max 1<<30

class comp
{
public:
    bool operator()(pii a,pii b)const
    {
        return a.second>b.second;
    }
};

vector<pii>v[101];
int level[101],n;

int dijkstra()
{
    priority_queue<pii,vector<pii>,comp>q;
    level[1]=0;
    q.push(pii(1,0));
    while(!q.empty())
    {
        pii p=q.top();
        if(p.first==n) return level[p.first];
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
    return -1;//level[n];
}

int main()
{
    int t,T,m,a,b,w;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            v[i].clear();
            level[i]=Max;
        }
        while(m--)
        {
            scanf("%d %d %d",&a,&b,&w);
            v[a].push_back(pii(b,w));
            v[b].push_back(pii(a,w));
        }
        printf("Case %d: ",t);
        int k=dijkstra();
        if(k==-1) printf("Impossible\n");
        else printf("%d\n",k);
    }
}
