#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>v[1001];
int flag[1001],common[1001];

void bfs(int source)
{
    flag[source]=1;
    common[source]++;
    queue<int>q;
    q.push(source);
    int top,k;
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for(int i=0;i<v[top].size();i++)
        {
            k=v[top][i];
            if(!flag[k])
            {
                flag[k]=1;
                common[k]++;
                q.push(k);
            }
        }
    }

}

int main()
{
    int t,T,ara[101],k,m,i,a,b;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d %d %d",&k,&n,&m);
        for(i=1;i<=n;i++) v[i].clear();
        for(i=0;i<k;i++)
        {
            scanf("%d",&ara[i]);
        }
        while(m--)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
        }
        memset(common,0,sizeof(common));
        for(i=0;i<k;i++)
        {
            memset(flag,0,sizeof(flag));
            bfs(ara[i]);
        }
        int count=0;
        for(i=1;i<=n;i++)
        {
            if(common[i]==k) count++;
        }
        printf("Case %d: %d\n",t,count);
    }
    return 0;
}
