#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ppi pair<pii,int>
#define Max 1000
//#define INT_MAX 1<<30

class comp
{
public:
    bool operator()(ppi a,ppi b)const
    {
        return a.second>b.second;
    }
};

int dirx[]={0,0,-1,1},diry[]={-1,1,0,0},nodes,level[Max][Max],m,n,ara[Max][Max];

int dijkstra()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            level[i][j]=INT_MAX;
        }
    }
    level[0][0]=ara[0][0];
    priority_queue<ppi,vector<ppi>,comp>q;
    q.push(ppi(pii(0,0),level[0][0]));
    while(!q.empty())
    {
        ppi p=q.top();
        if(p.first.first==m-1 && p.first.second==n-1) return level[m-1][n-1];
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=p.first.first+dirx[i];
            int y=p.first.second+diry[i];
            if(x>=0 && y>=0 && x<m && y<n && level[p.first.first][p.first.second]+ara[x][y]<level[x][y])
            {
                level[x][y]=level[p.first.first][p.first.second]+ara[x][y];
                q.push(ppi(pii(x,y),level[x][y]));
            }
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int T,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d",&m,&n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++) scanf("%d",&ara[i][j]);
        }
        printf("%d\n",dijkstra());
    }
    return 0;
}
