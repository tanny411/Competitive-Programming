#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define Max 1<<30
int n;
vector<pii>v[501];
int level[501];

int maxi(int a,int b)
{
    return a>b?a:b;
}

class comp
{
public:
    bool operator()(pii a,pii b)const
    {
        return a.second>b.second;
    }
};

void dijkstra(int s)
{
    for(int i=0; i<n; i++) level[i]=Max;
    priority_queue<pii,vector<pii>,comp>q;
    q.push(pii(s,0));
    level[s]=0;
    while(!q.empty())
    {
        pii p=q.top();
        q.pop();
       // for(int i=0;i<n;i++) cout<<level[i]<<endl;
       // cout<<endl;
        for(int i=0;i<v[p.first].size();i++)
        {
            int k=v[p.first][i].first;
            if(level[k]>maxi(level[p.first],v[p.first][i].second))
            {
               level[k]=maxi(level[p.first],v[p.first][i].second);
               q.push(pii(k,level[k]));
            }
        }
    }
}

int main()
{
    int t,T,e,a,b,w,s,f=0;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&n,&e);
        for(int i=0;i<n;i++) v[i].clear();
        while(e--)
        {
            scanf("%d %d %d",&a,&b,&w);
            v[a].push_back(pii(b,w));
            v[b].push_back(pii(a,w));
        }
        scanf("%d",&s);
        dijkstra(s);
        printf("Case %d:\n",t);
        for(int i=0;i<n;i++)
        {
            if(level[i]==Max) printf("Impossible\n");
            else printf("%d\n",level[i]);
        }
    }
    return 0;
}
