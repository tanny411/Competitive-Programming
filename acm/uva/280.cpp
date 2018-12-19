#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>v[102];
char flag[102];

void dfs(int source)
{
    int i;
    for(i=0;i<v[source].size();i++)
    {
        if(!flag[v[source][i]])
        {
            flag[v[source][i]]=1;
            dfs(v[source][i]);
        }
    }
}

int main()
{
    int x,y,Count,a,i;
    vector<int>ina;
    while(scanf("%d",&n)==1 && n)
    {
        for(i=1;i<=n;i++) v[i].clear();

        while(scanf("%d",&x) && x)
        {
            while(scanf("%d",&y) && y)
            {
                v[x].push_back(y);
            }
        }
        scanf("%d",&x);
        while(x--)
        {
            memset(flag,0,sizeof(flag));
            scanf("%d",&a);
            dfs(a);
            Count=0;
            ina.clear();
            for(i=1;i<=n;i++)
            {
                if(!flag[i])
                {
                    Count++;
                    ina.push_back(i);
                }
            }
            printf("%d",Count);
            for(i=0;i<ina.size();i++)
            {
                printf(" %d",ina[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
