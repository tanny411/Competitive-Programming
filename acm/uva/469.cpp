#include<bits/stdc++.h>
using namespace std;
struct V
{
    int f,s;
}s;
int main()
{
    int i,j,k,Count,n,m,t,x,y,f=0;
    int dirx[]={-1,-1,-1,0,0,1,1,1};
    int diry[]={1,0,-1,1,-1,1,0,-1};
    queue<V>q;
    struct V top;
    char ara[110][110],flag[100][100];
    scanf("%d",&t);
    getchar();
    getchar();
    while(t--)
    {
        if(f) printf("\n");
        f=1;
        i=0;
        while(gets(ara[i]) && !isdigit(ara[i][0]))
        {
            i++;
        }
        m=i;
        n=strlen(ara[0]);
        do
        {
            memset(flag,0,sizeof(flag));
            sscanf(ara[i],"%d %d",&x,&y);
            x--;
            y--;
            Count=1 ;
            flag[x][y]=1;
            top.f=x;
            top.s=y;
            q.push(top);
            while(!q.empty())
            {
                top=q.front();
                q.pop();
                x=top.f;
                y=top.s;
                for(int p=0;p<8;p++)
                {
                    top.f=x+dirx[p];
                    top.s=y+diry[p];
                    if(top.s>-1 && top.f>-1 && top.f<m && top.s<n && ara[top.f][top.s]=='W' && !flag[top.f][top.s])
                    {
                        flag[top.f][top.s]='1';
                        q.push(top);
                        Count++;
                    }
                }

            }
            printf("%d\n",Count);
        }
        while(gets(ara[i]) && ara[i][0]);


    }
    return 0;
}
