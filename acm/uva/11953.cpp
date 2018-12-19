#include<bits/stdc++.h>
using namespace std;

int n,flag,dirx[]={-1,0,0,1},diry[]={0,-1,1,0};
char grid[102][102];

void dfs(int x,int y)
{
    if(!flag && grid[x][y]=='x') flag=1;
    grid[x][y]='.';
    int a,b;
    for(int i=0;i<4;i++)
    {
        a=x+dirx[i];
        b=y+diry[i];
        if(a>-1 && b>-1 && a<n && b<n && grid[a][b]!='.') dfs(a,b);
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,T,i,j;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        getchar();
        for( i=0;i<n;i++)
        {
            gets(grid[i]);
        }
        int c=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                flag=0;
                if(grid[i][j]!='.') dfs(i,j);
                if(flag) c++;
            }
        }
        printf("Case %d: %d\n",t,c);
    }
    return 0;
}
