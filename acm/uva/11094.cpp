#include<bits/stdc++.h>

int m,n,X,dirx[]={-1,0,0,1},diry[]={0,-1,1,0};
char ara[22][22],land;

void dfs(int x,int y)
{
    X++;
    ara[x][y]=0;
    int i,a,b;
    for(i=0;i<4;i++)
    {
        a=x+dirx[i];
        b=y+diry[i];
        if(b==n) b=0;
        else if(b==-1) b=n-1;
        if(a>-1 && b>-1 && a<m && b<n && ara[a][b]==land)
        {
            dfs(a,b);
        }
    }
}

int main()
{

    int i,j,Max;
    while(scanf("%d %d",&m,&n)==2)
    {
        getchar();
        for(i=0;i<m;i++)
        {
            gets(ara[i]);
        }
        X=0;
        Max=0;
        scanf("%d %d",&i,&j);
        land=ara[i][j];
        dfs(i,j);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ara[i][j]==land)
                {
                    X=0;
                    dfs(i,j);
                    //+printf("x=%d\n",X);
                    if(Max<X) Max=X;
                }
            }
        }
        printf("%d\n",Max);
    }
    return 0;
}
