#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

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

void dijkstra(int source)
{
    for(int i=1;i<=n;i++) level[i]=1<<30;
    priority_queue<pii,vector<pii>,comp>q;
    level[source]=0;
    q.push(pii(source,0));
    while(!q.empty())
    {
        pii p=q.top();
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
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,T,E,time,a,b,w,Count,f=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&E,&time,&t);
        for(int i=1;i<=n;i++) v[i].clear();
        while(t--)
        {
           scanf("%d %d %d",&a,&b,&w);
            v[b].push_back(pii(a,w));
        }
        dijkstra(E);
        Count=0;
        for(int i=1;i<=n;i++)
        {if(level[i]<=time) Count++;}
        if(f) printf("\n");
        f=1;
        printf("%d\n",Count);
    }
    return 0;
}
/*

1
4 2 1 8 1 2 1 1 3 1 2 1 1 2 4 1 3 1 1 3 4 1 4 2 1 4 3 1

*/
