#include<bits/stdc++.h>
using namespace std;

int level[2502],l;
vector<int>v[2502];

void bfs(int source)
{
    l=-1000;
    int top,i,k;
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
                if(level[k]>l) l=level[k];
                q.push(k);
            }
        }
    }
}

int main()
{
    int i,x,j,k,n;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&j);
            v[i].push_back(j);
        }
    }
    /*
    for(i=0;i<n;i++)
    {
        printf("%d -",i);
        for(j=0;j<v[i].size();j++)
        {
            printf(" %d",v[i][j]);
        }
        printf("\n");
    }
    */
    scanf("%d",&k);
    while(k--)
    {
        scanf("%d",&x);
        if(v[x].empty()) printf("0\n");
        else
        {
            memset(level,-1,sizeof(level));
            bfs(x);
            int lc[l+1];
            memset(lc,0,sizeof(lc));
            for(i=0;i<=n;i++)
            {
                lc[ level[i] ]++;
            }
            int Max=-1<<28,day;
            for(i=1;i<=l;i++)
            {
                if(lc[i]>Max) { Max=lc[i]; day=i; }
            }
            printf("%d %d\n",Max,day);
        }
    }
    return 0;
}
