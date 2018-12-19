#include<bits/stdc++.h>
using namespace std;

vector<int>v[1005];
int level[1005];
int n,d;

void bfs(int source)
{
    int top,i,k;
    queue<int>q;
    q.push(source);
    level[source]=0;
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
    int t,i,a,b,f=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(level,-1,sizeof(level));
        scanf("%d %d",&n,&d);
        for(i=0;i<n;i++) v[i].clear();
        while(d--)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        bfs(0);
        if(f) printf("\n");
        f=1;
        for(i=1;i<n;i++)
        {
            printf("%d\n",level[i]);
        }
    }
    return 0;
}
