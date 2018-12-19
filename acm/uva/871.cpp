#include<bits/stdc++.h>

using namespace std;

int dirx[8]={-1,-1,-1,0,0,1,1,1},diry[8]={-1,0,1,-1,1,-1,0,1};
char grid[30][30];
int m,n;
struct co{
int x,y;
}top;
queue<co>q;

int bfs(int i,int j)
{
    int p,counti=1;
    top.x=i;
    top.y=j;
    grid[top.x][top.y]='0';
    q.push(top);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        i=top.x;
        j=top.y;
        for(p=0;p<8;p++)
        {
            top.x=i+dirx[p];
            top.y=j+diry[p];
            if(top.x>=0 && top.x<m && top.y>=0 && top.y<n && grid[top.x][top.y]=='1')
            {
                q.push(top);
                grid[top.x][top.y]='0';
                counti++;
            }
        }
    }
    return counti;
}

int main()
{
    int t,in,maxi,f=0;
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        maxi=0;
        m=0;
        while(gets(grid[m]) && grid[m][0])
        {
            m++;
        }
        n=strlen(grid[0]);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    in=bfs(i,j);
                    //printf("          %d\n",in);
                    if(in>maxi) maxi=in;
                }
            }
        }
        if(f) printf("\n");
        f=1;
        printf("%d\n",maxi);
    }
    return 0;
}
