#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
using namespace std;

char grid[35][85];
int dirx[]={1,-1,0,0},diry[]={0,0,-1,1},in;

void bfs(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    grid[x][y]='#';
    while(!q.empty())
    {
        pii p=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            x=p.first+dirx[i];
            y=p.second+diry[i];
            if(x>=0 && x<in && y>=0 && grid[x][y]==' ')
            {
                grid[x][y]='#';
                q.push(pii(x,y));
            }
        }
    }
}

int main()
{
    //freopen("out.txt","w",stdout);
    int n,x,y;
    scanf("%d",&n);
    getchar();
    while(n--)
    {
        in=0;
        int f=1;
        while(gets(grid[in]))
        {
            int z=1;
            for(int i=0;grid[in][i];i++)
            {
                if(f){
                if(grid[in][i]=='*')
                {
                    x=in;
                    y=i;
                    f=0;
                }
                }
                if(grid[in][i]!='_')
                {
                    z=0;
                }
            }
            if(z) break;
            in++;
        }
        bfs(x,y);
        for(int i=0;i<=in;i++) puts(grid[i]);
    }
    return 0;
}
/*
XXXXXXXXX
X   X   X
X * X   X
X       X
XXXXXXXXX
X   X
X   X
X   X
XXXXX
_____
*/
