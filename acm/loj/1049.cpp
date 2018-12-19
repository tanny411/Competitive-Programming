#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int Max,x;
vector<pii>v[101];
void dfs(int s,int prev)
{
    if(s==1 && prev!=0)
    {
        if(Max>x) Max=x;
        x=0;
        return ;
    }
    for(int i=0;i<v[s].size();i++)
    {
        if(v[s][i].first!=prev)
        {
            x+=v[s][i].second;
            dfs(v[s][i].first,s);
        }
    }
    return ;
}

int main()
{
    int t,T;
    int n,a,b,w;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) v[i].clear();
        while(n--)
        {
            scanf("%d %d %d",&a,&b,&w);
            v[a].push_back(pii(b,0));
            v[b].push_back(pii(a,w));
        }
    Max=1<<30;
    x=0;
    dfs(1,0);
    printf("Case %d: %d\n",t,Max);
    }

    return 0;
}
