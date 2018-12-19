#include<bits/stdc++.h>
using namespace std;

int m,n,dirx[]={-1,0,0,1},diry[]={0,-1,1,0};
char grid[22][22];
struct st
{
    int x,y;
}source,top;

int bfs()
{
    int Count=1,x,y;
    grid[source.x][source.y]='#';
    queue<st>q;
    q.push(source);
    while(!q.empty())
    {
        int x,y,i;
        top=q.front();
        q.pop();
        x=top.x;
        y=top.y;
        for(i=0;i<4;i++)
        {
            top.x=x+dirx[i];
            top.y=y+diry[i];
            if(top.x>=0 && top.y>=0 && top.x<m && top.y<n && grid[top.x][top.y]=='.')
            {
            grid[top.x][top.y]='#';
            Count++;
            q.push(top);
            }
        }
    }
    return Count;
}

int main()
{
    int t,i,x,j,f;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d %d",&n,&m);
        getchar();
        f=1;
        for(x=0;x<m;x++)
        {
            gets(grid[x]);
            if(f){
            for(j=0;grid[x][j];j++)
            {
                if(grid[x][j]=='@')
                {
                    source.x=x;
                    source.y=j;
                    f=0;
                    break;
                }
            }
            }
        }
        printf("Case %d: %d\n",i,bfs());
    }
    return 0;
}
/*
....#.
.....#
......
......
......
......
......
#@...#
.#..#.

.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........

..#..#..#..
..#..#..#..
..#..#..###
..#..#..#@.
..#..#..#..
..#..#..#..

..#.#..
..#.#..
###.###
...@...
###.###
..#.#..
..#.#..
*/
