#include<bits/stdc++.h>
using namespace std;

int isit(char ch)
{
    if(ch=='a' || ch=='b' || ch=='c' || ch=='h') return 1;
    else return 0;
}

struct st
{
    int f,s;
}top,home,girls[3];

char grid[21][21],level[21][21];
int dirx[]={-1,0,0,1},diry[]={0,-1,1,0};

int bfs(st source)
{
    int x,y;
    level[source.f][source.s]=0;
    queue<st>q;
    q.push(source);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        x=top.f;
        y=top.s;
        for(int i=0;i<4;i++)
        {
            top.f=x+dirx[i];
            top.s=y+diry[i];
            if(grid[top.f][top.s]!='#' && grid[top.f][top.s]!='m' && level[top.f][top.s]==-1)
            {
                if(grid[top.f][top.s]=='h') return level[x][y]+1;
                level[top.f][top.s]=level[x][y]+1;
                q.push(top);
            }
        }
    }

}

int main()
{
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        getchar();
        for(int i=0;i<m;i++)
        {
            gets(grid[i]);
            for(int j=0;j<n;j++)
            {
                if(isit(grid[i][j]))
                {

                if(grid[i][j]=='h')
                    {
                        home.f=i;
                        home.s=j;
                    }
                else
                    {
                        girls[grid[i][j]-'a'].f=i;
                        girls[grid[i][j]-'a'].s=j;
                    }
                }
            }
        }

        int r, max=-1<<28;
        for(int i=0;i<3;i++)
        {
            memset(level,-1,sizeof(level));
            r=bfs(girls[i]);
            if(r>max) max=r;
        }
        printf("Case %d: %d\n",t,max);

    }
    return 0;
}

/*
2 6 8
########
#...c..#
#......#
#.a.h.b#
#......#
########
5 9
#########
#mmm...c#
#ma.h####
#m....b.#
#########

*/
