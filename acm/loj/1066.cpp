#include<bits/stdc++.h>
using namespace std;

struct Pair
{
    int first,second;
}p[27],top;
char grid[11][11];
int dirx[]={-1,0,0,1},diry[]={0,-1,1,0};
int n;

void clean()
{
    for(int i=0;i<26;i++)
    {
        p[i].first=p[i].second=0;
    }
}

void printgrid()
{
    for(int i=0;i<n;i++) puts(grid[i]);
}

int bfs(int sx,int sy)
{
    int x,y;
    grid[p[sx].first][p[sx].second]='.';
    queue<Pair>q;
    q.push(p[sx]);
    int level[11][11];
    memset(level,-1,sizeof(level));
    level[p[sx].first][p[sx].second]=0;
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        x=top.first;
        y=top.second;
        for(int i=0;i<4;i++)
        {
            top.first=x+dirx[i];
            top.second=y+diry[i];
            if(top.first>=0 && top.second>=0 && top.first<n && top.second<n && (grid[top.first][top.second]=='.' || grid[top.first][top.second]==sy+'A') && level[top.first][top.second]==-1)
            {
                level[top.first][top.second]=level[x][y]+1;
                if(grid[top.first][top.second]==sy+'A')
                {
                    return level[top.first][top.second];
                }
                q.push(top);
            }
        }
    }
    return -1;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,t;

    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {

        scanf("%d",&n);
        getchar();
        for(int i=0;i<n;i++)
        {
            gets(grid[i]);
        }
        clean();
        ///i dont know this part
        int i,j,c=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(isalpha(grid[i][j]))
                {
                    p[ grid[i][j]-'A'].first=i;
                    p[ grid[i][j]-'A'].second=j;
                    c++;
                }
            }
        }
        //printf("                                                 c=%d\n",c);
        printf("Case %d: ",t);
        int x=0,k=0,a=0;
        for(i=1;i<c;i++)
        {
            k=bfs(a,i);
            //printf("               %d\n",k);printgrid();
            if(k==-1) break;
            x+=k;
            a=i;
        }
        if(k==-1) printf("Impossible\n");
        else printf("%d\n",x);
    }
    return 0;
}


/*
4

5
A....
####.
..B..
.####
C.DE.

2
AC
.B

2
A#
#B

3
A.C
##.
B..

*/
