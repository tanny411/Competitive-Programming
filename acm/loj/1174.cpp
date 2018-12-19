#include<bits/stdc++.h>
using namespace std;


vector<int>v[101];
//int level[101],lvl2[101];

void bfs(int source,int level[])
{
    int i,j,k,top;
    memset(level,-1,sizeof(level));
    level[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for(i=0;i<v[top].size();i++)
        {
            k=v[top][i];
            if(level[k]==-1)
            {
                level[k]=level[top]+1;
                q.push(k);
            }
        }
    }
}

int main()
{
    int t,T,nodes,e,s,d;
    int level[101],lvl2[101];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&nodes,&e);
        for(int i=0;i<nodes;i++) v[i].clear();
        while(e--)
        {
            scanf("%d %d",&s,&d);
            v[s].push_back(d);
            v[d].push_back(s);
        }
        scanf("%d %d",&s,&d);
        memset(level,-1,sizeof(level));
        memset(lvl2,-1,sizeof(lvl2));
        bfs(s,level);
        bfs(d,lvl2);
        int max=-1<<28;
        /*
        for(int i=0;i<nodes;i++) printf(" %d",level[i]);
        printf("\n");

        for(int i=0;i<nodes;i++) printf(" %d",lvl2[i]);
        printf("\n");
        */

        for(int i=0;i<nodes;i++)
        {
            level[i]+=lvl2[i];
            if(level[i]> max) max=level[i];
        }
        printf("Case %d: %d\n",t,max);
    }
    return 0;
}
