#include<bits/stdc++.h>
using namespace std;
vector<int>v[32];
int level[32];

int bfs(int source,int des)
{
    int i,top,k;
    level[source]=0;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        if(level[des]!=-1) return level[des];
        for(i=0;i<v[top].size();i++)
        {
            k=v[top][i];
            if(level[k]==-1)
            {
                level[k]=level[top]+1;
                q.push(k);
            }
        }
    }
    return -1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    map<string,int>mp;
    string s,r;
    int t,T,n,m,p,i;
    scanf("%d",&T);
    printf("SHIPPING ROUTES OUTPUT\n");
    for(t=1;t<=T;t++)
    {
        printf("\nDATA SET  %d\n\n",t);
        scanf("%d %d %d",&m,&n,&p);
        for(i=0;i<m;i++)
        {
            cin>>s;
            mp[s]=i;
            v[i].clear();
        }
        while(n--)
        {
            cin>>s>>r;
            v[mp[s]].push_back(mp[r]);
            v[mp[r]].push_back(mp[s]);
        }
        int x;
        while(p--)
        {
            cin>>n>>s>>r;
            memset(level,-1,sizeof(level));
            n*=100;
            x=bfs(mp[s],mp[r]);
            if(x<0) printf("NO SHIPMENT POSSIBLE\n");
            else cout<<"$"<<n*x<<endl;
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
