#include<bits/stdc++.h>
using namespace std;

struct st
{
    int n,w;
}s;

int nodes,level[30001];
vector<st>v[30001];

int bfs(int source)
{
    int top;
    memset(level,-1,sizeof(level));
    level[source]=0;
    queue<int>q;
    q.push(source);
    int max=-1<<28;
    int node=source;
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for(int i=0;i<v[top].size();i++)
        {
            int k=v[top][i].n;
            if(level[k]==-1)
            {
                level[k]=level[top]+v[top][i].w;
                if(level[k]>max)
                {
                    max=level[k];
                    node=k;
                }
                q.push(k);
            }
        }
    }
    return node;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t,T,x,a,b,w;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&nodes);
        x=nodes;
        while(x--)
        {
            v[x].clear();
        }
        x=nodes-1;
        while(x--)
        {
            scanf("%d %d %d",&a,&b,&w);
            s.n=a;
            s.w=w;
            v[b].push_back(s);
            s.n=b;
            v[a].push_back(s);
        }
        cout<<"Case "<<t<<": "<<level[bfs(bfs(0))]<<endl;
        /*
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<v[i].size();j++)
            {
                printf(" (%d %d)",v[i][j].n,v[i][j].w);
            }
            printf("\n");
        }
        int p,q,r;
        p=bfs(0);
        for(int i=0;i<nodes;i++) printf("            %d\n",level[i]);
        int path=level[p];
        q=bfs(p);
        r=level[q];
        printf("              bfs(0)=  %d  path-length= %d  bfs(one node)=%d path length=%d\n",p,path,q,r);
        for(int i=0;i<nodes;i++) printf("            %d\n",level[i]);
        */
    }
    return 0;
}
