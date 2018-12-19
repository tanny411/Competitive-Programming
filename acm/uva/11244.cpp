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

int m,n;
char ara[110][110];
int dirx[]={-1,-1,-1,1,1,1,0,0};
int diry[]={0,-1,1,0,-1,1,1,-1};

int floodfill(int x,int y)
{
    int Count=1;
    ara[x][y]='.';
    queue<pii>q;
    q.push(pii(x,y));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();

            for(int i=0;i<8;i++)
            {
                x=top.first+dirx[i];
                y=top.second+diry[i];
                if(x>=0 && y>=0 && x<m && y<n && ara[x][y]=='*')
                {
                    Count++;
                    ara[x][y]='.';
                    q.push(pii(x,y));
                }
            }
    }
    return Count;
}

int main()
{
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&m,&n)==2)
    {
        getchar();
        int Count=0;
        if(m==0 && n==0) return 0;
        for(int i=0;i<m;i++)
        {
            gets(ara[i]);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ara[i][j]=='*')
                {
                   int x=floodfill(i,j);
                   if(x==1) Count++;
                }
            }
        }
        printf("%d\n",Count);
    }
    return 0;
}
