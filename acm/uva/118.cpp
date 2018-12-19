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

char orientation;
int m,n,grid[55][55];

void view(char x)
{
     if(orientation=='E')
     {
         if(x=='L') orientation='N';
         else orientation='S';
     }
    else if(orientation=='W')
    {
        if(x=='L') orientation='S';
         else orientation='N';
    }
    else if(orientation=='N')
    {
        if(x=='L') orientation='W';
         else orientation='E';
    }
    else if(orientation=='S')
    {
        if(x=='L') orientation='E';
         else orientation='W';
    }
}

int walk(int *x, int *y)
{
    int X=*x,Y=*y;
    if(orientation=='N') Y++;
    else if(orientation=='S') Y--;
    else if(orientation=='E') X++;
    else if(orientation=='W') X--;
    if(X>m || Y>n || X<1 || Y<1)
    {
        if(grid[*x][*y]==-1) return 1;
        grid[*x][*y]=-1;
        return 0;
    }
    *x=X;
    *y=Y;
    return 1;
}

int main()
{
    //freopen("out.txt","w",stdout);
    char ara[110];
    int x,y,z;
    scanf("%d %d",&m,&n);
    m++;
    n++;
    while(scanf("%d %d %c",&x,&y,&orientation)==3)
    {
        x++;
        y++;
        getchar();
        gets(ara);
        z=1;
        for(int i=0;ara[i];i++)
        {
            if(ara[i]=='F')
            {
                z=walk(&x,&y);
                if(!z) break;
            }
            else view(ara[i]);
        }
        if(z) printf("%d %d %c\n",x-1,y-1,orientation);
        else printf("%d %d %c LOST\n",x-1,y-1,orientation);
    }
    return 0;
}
