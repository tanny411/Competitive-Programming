#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

struct d2
{
    int first,second;
}top,w;

queue<d2>q;
int level[9][9],i,j,wx,wy;
int dirx[8]={ 2, 2,-2,-2,1,-1,1,-1};
int diry[8]={ 1,-1, 1,-1,2,2,-2,-2};

void bfs(int x,int y,int fx,int fy)
{
    memset(level,-1,sizeof(level));
    top.first=x;
    top.second=y;
    q.push(top);
    level[x][y]=0;
    while(level[fx][fy]==-1)
    {
        top=q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
            wx=top.first+dirx[i];
            wy=top.second+diry[i];
            if(wx>0 && wx<=8 && wy>0 && wy<=8)
            {
                if(level[wx][wy]!=-1) continue;
                level[wx][wy]=level[top.first][top.second]+1;
                w.first=wx;
                w.second=wy;
                q.push(w);
            }
        }
    }
    while(!q.empty()) q.pop();
}

int main()
{
    char y,fy;
    int x,fx;
    while(scanf("%c%d %c%d",&y,&x,&fy,&fx)==4)
    {
        getchar();
        bfs(x,y-96,fx,fy-96);
        printf("To get from %c%d to %c%d takes %d knight moves.\n",y,x,fy,fx,level[fx][fy-96]);
    }
    return 0;
}
