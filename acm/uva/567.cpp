#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int main()
{
    vector<int>v[21];
    queue<int>q;
    int test=1,i,j,k,x,a,start,stop,level[22],top;
    while(scanf("%d",&x)==1)
    {
        {
            i=1;
            while(x--)
            {
                scanf("%d",&a);
                v[a].push_back(i);
                v[i].push_back(a);
            }
        }
        for(i=2;i<20;i++)
        {
            scanf("%d",&x);
            while(x--)
            {
                scanf("%d",&a);
                v[a].push_back(i);
                v[i].push_back(a);
            }
        }
        printf("Test Set #%d\n",test++);
        scanf("%d",&x);
        while(x--)
        {
            memset(level,-1,sizeof(level));
            scanf("%d %d",&start,&stop);
            q.push(start);
            level[start]=0;
            while(level[stop]==-1)
            {

                top=q.front();
                q.pop();
                for(j=0;j<v[top].size();j++)
                {
                    if(level[v[top][j]]==-1)
                    {
                        level[v[top][j]]=level[top]+1;
                        q.push(v[top][j]);
                    }
                }
            }
            while(!q.empty()) q.pop();
            printf("%2d to %2d: %d\n",start,stop,level[stop]);
        }
        for(i=1;i<=20;i++) v[i].clear();
        printf("\n");
    }
    return 0;
}
