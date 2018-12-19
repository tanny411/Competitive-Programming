#include<bits/stdc++.h>

using namespace std;

struct S
{
    char ch;
    int s;
};

int dirx[]={-1,0,0,1},diry[]={0,-1,1,0},m,n;
char ara[100][100];

void dfs(int x,int y)
{
    char c=ara[x][y];
    ara[x][y]=0;
    int i,a,b;
    for(i=0;i<4;i++)
    {
        a=x+dirx[i];
        b=y+diry[i];
        if( a>-1 && b>-1 && a<m && b<n && ara[a][b]!=0 && ara[a][b]==c)
            dfs(a,b);
    }
    return;
}

bool comp(S a,S b)
{
    if(a.s!=b.s) return a.s>b.s;
    else return a.ch<b.ch;
}

int main()
{
    int i,j,t,test;
    char p;
    struct S state[30];
    scanf("%d",&test);
    getchar();
    for(int t=1;t<=test;t++)
    {
        p='a';
        for(i=0;i<26;i++)
        {
            state[i].ch=p++;
            state[i].s=0;
        }
        scanf("%d %d",&m,&n);
        getchar();
        for(i=0;i<m;i++) gets(ara[i]);
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(ara[i][j])
                {
                    state[ara[i][j]-'a'].s++;
                    dfs(i,j);
                }
            }
        }
        sort(state,state+26,comp);
        printf("World #%d\n",t);
        for(i=0;i<26;i++)
        {
            if(state[i].s==0) break;
            printf("%c: %d\n",state[i].ch,state[i].s);
        }
    }
    return 0;
}
