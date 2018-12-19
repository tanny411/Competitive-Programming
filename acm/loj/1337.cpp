#include<bits/stdc++.h>
using namespace std;

char grid[501][501];
int flag[501][501];
int m,n,dirx[]={-1,0,0,1},diry[]={0,-1,1,0},crystal[250005];

void dfs(int x,int y,int col)
{
    flag[x][y]=col;
    if(grid[x][y]=='C') crystal[col]++;
    int f,s;
    for(int i=0;i<4;i++)
    {
        f=x+dirx[i];
        s=y+diry[i];
        if(f>=0 && s>=0 && f<m && s<n && grid[f][s]!='#' && flag[f][s]==0)
        {
            dfs(f,s,col);
        }
    }
}
/*
1 4 5 2
..#..
.C#C.
##..#
..C#C
1 1 4 1
*/

int main()
{
    int t,T,q,x,y;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d",&m,&n,&q);
        getchar();
        for(int i=0;i<m;i++)
        {
            gets(grid[i]);
        }
        printf("Case %d:\n",t);
        int color=0;
        memset(flag,color,sizeof(flag));
        memset(crystal,0,sizeof(crystal));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(flag[i][j]==0)
                {
                    dfs(i,j,++color);
                }
            }
        }
        while(q--)
        {
            scanf("%d %d",&x,&y);///have to reduce 1
            printf("%d\n",crystal[flag[x-1][y-1]]);
        }
    }
    return 0;
}
