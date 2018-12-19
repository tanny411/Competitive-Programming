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
#define INTMAX 1<<30
#define MOD 1000000007
#define ll long long
#define llu unsigned long long
using namespace std;
int m,n,Jx,Jy;
char ara[202][202];
int fire[202][202],dx[]={0,0,-1,1},dy[]={-1,1,0,0},jane[202][202];

void bfsfire(int sx,int sy)
{
    fire[sx][sy]=0;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=top.first+dx[i];
            int y=top.second+dy[i];
            if(x>=0 && y>=0 && x<m && y<n && ara[x][y]=='.' && fire[x][y]>fire[top.first][top.second]+1)
            {
                fire[x][y]=fire[top.first][top.second]+1;
                q.push(pii(x,y));
            }
        }
    }
}

int bfsjane(int sx,int sy)
{
    jane[sx][sy]=0;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty())
    {
        pii top=q.front();
        int d=jane[top.first][top.second];
        q.pop();
        for(int i=0;i<4;i++)
        {
            int x=top.first+dx[i];
            int y=top.second+dy[i];
            if(x==-1 || y==-1 || x==m || y==n ) return d+1;
            if(x>=0 && y>=0 && x<m && y<n && ara[x][y]=='.' && d+1<fire[x][y])
            {
                ara[x][y]='J';
                jane[x][y]=d+1;
                q.push(pii(x,y));
            }
        }
    }
    return -1;
}

int main()
{
    int test,cas=1;
    cin>>test;
    while(test--)
    {
        cin>>m>>n;
        getchar();
        for(int i=0;i<m;i++)
        {
            gets(ara[i]);
            for(int j=0;j<n;j++) { fire[i][j]=1<<30; jane[i][j]=-1; }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(ara[i][j]=='J')
                {
                    Jx=i;
                    Jy=j;
                }
                if(ara[i][j]=='F') bfsfire(i,j);
            }
        }
        //for(int i=0;i<m;i++) {for(int j=0;j<n;j++) cout<<" "<<fire[i][j]; cout<<endl; }
        printf("Case %d: ",cas++);
        int ans=bfsjane(Jx,Jy);
        if(ans==-1) printf("IMPOSSIBLE\n");
        else printf("%d\n",ans);
    }
    return 0;
}
