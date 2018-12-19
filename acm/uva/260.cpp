#include<bits/stdc++.h>

using namespace std;

int n,dirx[]={-1,-1,0,0,1,1},diry[]={-1,0,-1,1,0,1};
char grid[205][205];
struct st
{
    int f,s;
}top;
queue<st>q;

int bfs(int i,int j)
{
    while(!q.empty()) q.pop();
    int p;
    top.f=i;
    top.s=j;
    q.push(top);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        i=top.f;
        j=top.s;
        for(p=0;p<6;p++)
        {
            top.f=i+dirx[p];
            top.s=j+diry[p];
            if(top.f>-1 && top.f<n && top.s>-1 && top.s<n && grid[top.f][top.s]=='b')
            {
                if(top.f==n-1) return 1;
                else q.push(top);
                grid[top.f][top.s]='w';
            }
        }
    }
    return 0;
}
int main()
{
    int test=1,i;
    while(scanf("%d",&n) && n)
    {
        getchar();
        for(i=0;i<n;i++)
        {
            gets(grid[i]);
        }
        for(i=0;i<n;i++)
        {
            if(grid[0][i]=='b')
                if(bfs(0,i)) break;
        }
        printf("%d ",test++);
        if(i==n) printf("W\n");
        else printf("B\n");
    }
    return 0;
}
