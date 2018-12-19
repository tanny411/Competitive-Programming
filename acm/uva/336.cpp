#include<stdio.h>
#include<iostream>
#include<queue>
#include<map>
#include<string.h>
using namespace std;

int main()
{
    queue<int>q;
    int level[33],num,test=1,ttl,x,y,i,top;
    map<int,int>node;
    vector<int>v[33];
    int e,nodenumber,source;
    while(scanf("%d",&e)==1 && e)
    {
        node.clear();///when i gave this at the end gave me WA
        nodenumber=1;
        while(e--)
        {
            scanf("%d %d",&x,&y);
            if(node[x]==0) node[x]=nodenumber++;
            if(node[y]==0) node[y]=nodenumber++;
            v[node[x]].push_back(node[y]);
            v[node[y]].push_back(node[x]);
        }
        while(scanf("%d %d",&source,&ttl)==2)
        {
            if(source==0 && ttl==0) break;
            memset(level,-1,sizeof(level));
            q.push(node[source]);
            level[node[source]]=0;
            while(!q.empty())
            {
                top=q.front();
                q.pop();
                for(i=0;i<v[top].size();i++)
                {
                    if(level[v[top][i]]==-1)
                    {
                        level[v[top][i]]=level[top]+1;
                        q.push( v[top][i] );
                    }
                }
            }
            num=0;
            for(i=1;i<nodenumber;i++)
            {
                if(level[i]>ttl || level[i]==-1) num++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",test++,num,source,ttl);
        }
        for(i=1;i<nodenumber;i++)
        {
            v[i].clear();
        }
    }

    return 0;
}
