#include<stdio.h>
#include<queue>

using namespace std;

struct d2
{
    int first,second;
};

int grid[1001][1001],dirx[4]={ -1,1,0,0 },diry[4]={ 0,0,-1,1 },level[1001][1001];
int wx,wy,row,col,i,j;///working (x,y)
d2 top,w;
queue<d2>q;

void reset()
{
    while(!q.empty()) q.pop();
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            grid[i][j]=0;
        }
    }
}

void bfs(int x,int y,int fx,int fy)///source(x,y);destination(fx,fy)
{
    grid[x][y]=-1;
    top.first=x;
    top.second=y;
    q.push(top);
    level[x][y]=0;
    while(grid[fx][fy]!=-1)
    {
        top=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            wx=top.first+dirx[i];
            wy=top.second+diry[i];
            if( wx>=0 && wx<row && wy>=0 && wy<col && grid[wx][wy]!=-1 )
            {
                grid[wx][wy]=-1;
                level[wx][wy]=level[top.first][top.second]+1;
                w.first=wx;
                w.second=wy;
                q.push(w);
            }
        }
    }
}

int main()
{
    int c,d,x,y;
    while(scanf("%d %d",&row,&col)==2)
    {
        if(row==0 && col==0) break;
        scanf("%d",&c);
        while(c--)
        {
            scanf("%d %d",&x,&d);
            while(d--)
            {
                scanf("%d",&y);
                grid[x][y]=-1;
            }
        }
        scanf("%d %d %d %d",&x,&y,&c,&d);
        bfs(x,y,c,d);
        printf("%d\n",level[c][d]);
        reset();
    }
    return 0;
}
