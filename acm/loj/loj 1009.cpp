#include<bits/stdc++.h>
using namespace std;

vector<int>v[20003];
int flag[20003],num,Max;

void clean()
{
    int i;
    for(i=0;i<=Max;i++) v[i].clear();
    memset(flag,0,sizeof(flag));
}

int bfs(int source)
{
    int Count=1;
    int total=0;
    ///1 means counting group,2 means rival group
    int top,i,k,p,c;
    flag[source]=1;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        total++;
        top=q.front();
        q.pop();
        if(flag[top]==1) p=2;
        else p=1;
        c=0;
        for(i=0;i<v[top].size();i++)
        {
            k=v[top][i];
            if(flag[k]==0)
            {
                flag[k]=p;
                q.push(k);
                c++;
            }
        }
        if(p==1) Count+=c;
    }
    if(total-Count>Count) Count=total-Count;
    return Count;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t,a,b,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d",&n);
        //printf("what?\n");
        Max=20003;
        clean();
        //printf("done\n");
        Max=-1<<28;
        while(n--)
        {
            scanf("%d %d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
            if(a>Max) Max=a;
            if(b>Max) Max=b;
        }
        //printf("                   Max=%d\n",Max);
        num=0;
        for(int j=1;j<=Max;j++)
        {
            if(flag[j]==0)
            {
                if(v[j].empty()) continue;
                num+=bfs(j);
            }
        }
        printf("Case %d: %d\n",i,num);
    }
    return 0;
}
