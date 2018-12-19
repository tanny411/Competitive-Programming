#include<bits/stdc++.h>

using namespace std;

char grid[102][102];
int dirx[8]={-1,-1,-1, 0,0 , 1,1,1};
int diry[8]={-1, 0, 1,-1,1 ,-1,0,1};

struct X
{
    int f,s;
}x;


queue<X>q;
int p,m,n;

void bfs(int i,int j)
{
    x.f=i;
    x.s=j;
    q.push(x);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        i=x.f;
        j=x.s;

    for(p=0;p<8;p++)
    {
        x.f=i+dirx[p];
        x.s=j+diry[p];
        if(grid[x.f][x.s]=='@')
        {
            q.push(x);
            grid[x.f][x.s]='*';
        }
    }
    }
}

int main()
{
    int i,j,Count;

    while(scanf("%d %d",&m,&n)==2 && m )
    {
        getchar();
        Count=0;
        for(i=0;i<m;i++)
            {
                gets(grid[i]);
            }
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    Count++;
                    bfs(i,j);
                }
            }
        }
        printf("%d\n",Count);
    }
    return 0;
}
