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

char ara[35][85],flag[31][81];
int in,dirx[]={-1,1,0,0},diry[]={0,0,-1,1};

void floodfill(int x,int y)
{
    flag[x][y]=1;
    char a=ara[x][y];
    queue<pii>q;
    q.push(pii(x,y));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            x=top.first+dirx[i];
            y=top.second+diry[i];
            if(x>=0 && y>=0 && x<in && (ara[x][y]==' ' || ara[x][y]==a) && flag[x][y]==0)
            {
                ara[x][y]=a;
                flag[x][y]=1;
                q.push(pii(x,y));
            }
        }
    }
}

int main()
{
    while(gets(ara[0]))
    {
        memset(flag,0,sizeof(flag));
        char border=0;
        for(int i=0;ara[0][i];i++) if(ara[0][i]!=' ') border=ara[0][i];
        in=1;
        while(1)
        {
            gets(ara[in]);
            if(ara[in][0]=='_')
            {
                break;
            }

            if(border==0)
            {
                for(int i=0;ara[in][i];i++) if(ara[in][i]!=' ') border=ara[in][i];
            }

            in++;
        }
        for(int i=0;i<in;i++)
        {
            for(int j=0;ara[i][j];j++)
            {
                if(flag[i][j]) continue;
                if(ara[i][j]!=border && ara[i][j]!=' ')
                {
                    floodfill(i,j);
                }
            }
        }
        for(int i=0;i<=in;i++) puts(ara[i]);
    }
    return 0;
}
