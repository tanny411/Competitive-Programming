#include<bits/stdc++.h>
using namespace std;
int n,dirx[]={-1,-1,-1,0,0,1,1,1},diry[]={-1,0,1,-1,1,-1,0,1};
char grid[30][30];
struct S
{
    int f,s;
}top;
queue<S>q;

void bfs(int i,int j)
{
    int p;
    top.f=i;
    top.s=j;
    q.push(top);
    while(!q.empty())
    {
        top=q.front();
        i=top.f;
        j=top.s;
        q.pop();
        for(p=0;p<8;p++)
        {
            top.f=i+dirx[p];
            top.s=j+diry[p];
            if(top.f>-1 && top.s>-1 && top.f<n && top.s<n && grid[top.f][top.s]=='1')
            {
                q.push(top);
                grid[top.f][top.s]='0';
            }
        }
    }
}

int main()
{
    int i,j,Count,test=1;
    while(scanf("%d",&n)==1)
    {
        getchar();
        Count=0;
        for(i=0;i<n;i++)
        {
            gets(grid[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(grid[i][j]=='1'){
                Count++;
                grid[i][j]='0';
                bfs(i,j);
                }
            }
        }
        printf("Image number %d contains %d war eagles.\n",test++,Count);
    }
    return 0;
}
