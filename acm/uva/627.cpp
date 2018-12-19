#include<bits/stdc++.h>
using namespace std;

    vector<int>v[350];
    vector<int>p;
    int path[350],flag[350];



    void bfs(int source,int des)
    {
        int top,j,s;
        queue<int>q;
        flag[source]=1;
        path[source]=source;

        q.push(source);
        while(!q.empty())
        {
            if(flag[des]) return;
            top=q.front();
            q.pop();
            for(s=0;s<v[top].size();s++)
            {
                j=v[top][s];
                //if(path[j]==-1)
                if(flag[j]==0)
                {
                    //printf("           %d\n");
                    q.push(j);
                    path[j]=top;
                    flag[j]=1;
                }
            }
        }

    }

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int i,k,f,x,y,now,n;
    char str[1000];
    stringstream ss;
    while(scanf("%d",&n)==1)
    {
        i=n+1;
        while(i--)
        {
            v[i].clear();
        }
        getchar();
        while(n--)
        {
            gets(str);
            for(i=0;str[i];i++)
            {
                if(str[i]==',' || str[i]=='-') str[i]=' ';
            }
            ss<<str;
            //puts(str);
            ss>>x;
            while(ss>>y) v[x].push_back(y);
            ss.clear();
            /*
            printf(                 "\n%d-",x);
            for(i=0;i<v[x].size();i++)
            {
                printf(" %d",v[x][i]);
            }
            printf("\n");
            */
        }
        scanf("%d",&k);
        printf("-----\n");
        while(k--)
        {
            //memset(path,-1,sizeof(path));
            memset(flag,0,sizeof(flag));

            scanf("%d %d",&x,&y);
            bfs(x,y);
            //printf("\nbfs ended\n");
            //if(path[y]==-1)
            if(flag[y]==0)
            {
                printf("connection impossible\n");
            }
            else
            {
                p.clear();
                p.push_back(y);
                now=y;
                while(now!=x)
                {
                    //printf(".");
                    now=path[now];
                    p.push_back(now);
                }
                i=p.size();
                printf("%d",p[i-1]);
                for(i=i-2;i>-1;i--)
                {
                    printf(" %d",p[i]);
                }
                printf("\n");
            }

        }

    }
    return 0;
}

