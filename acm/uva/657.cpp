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

class comp
{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};

char grid[55][55];
int m,n,dirx[]={-1,1,0,0},diry[]={0,0,-1,1};


void floodfill_dot(int x,int y)
{
    queue<pii>q;
    q.push(pii(x,y));
    grid[x][y]='*';
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            x=top.first+dirx[i];
            y=top.second+diry[i];
            if(x>=0 && y>=0 && x<m && y<n && grid[x][y]=='X')
            {
                grid[x][y]='*';
                q.push(pii(x,y));
            }
        }
    }
}


int floodfill_dice(int x,int y)
{
    int Count=0;
    queue<pii>q;
    q.push(pii(x,y));
    if(grid[x][y]=='X')
    {
        floodfill_dot(x,y);
        Count++;
    }
    grid[x][y]='.';
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            x=top.first+dirx[i];
            y=top.second+diry[i];
            if(x>=0 && y>=0 && x<m && y<n && (grid[x][y]=='X' || grid[x][y]=='*'))
            {
                if(grid[x][y]=='X')
                {
                    floodfill_dot(x,y);
                    Count++;
                }
                grid[x][y]='.';
                q.push(pii(x,y));
            }
        }
    }
    return Count;
}

int main()
{
    int t=1;
    while(scanf("%d %d",&n,&m)==2)
    {
        if( m==0 && n==0 ) return 0;
        getchar();
        priority_queue<int,vector<int>,comp>q;
        for(int i=0;i<m;i++) gets(grid[i]);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='*') q.push(floodfill_dice(i,j));
            }
        }
        printf("Throw %d\n",t++);
        printf("%d",q.top());
        q.pop();
        while(!q.empty())
        {
            printf(" %d",q.top());
            q.pop();
        }
        printf("\n\n");
    }
    return 0;
}


/*
30 15
..............................
..............................
...............*..............
...*****......****............
...*X***.....**X***...........
...*****....***X**............
...***X*.....****.............
...*****.......*..............
..............................
........***........******.....
.......**X****.....*X**X*.....
......*******......******.....
.....****X**.......*X**X*.....
........***........******.....
..............................

*/
