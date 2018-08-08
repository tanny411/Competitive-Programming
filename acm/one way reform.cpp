#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int n;
int gr[205][205];

void dfs(int u)
{
    for(int i=1; i<=n; i++)
    {
        if(gr[u][i]>0)
        {
            if(gr[u][i]==1) cout<<u<<" "<<i<<endl;
            if(gr[u][i]==10) gr[u][i]=gr[i][u]=1;
            else gr[u][i]=gr[i][u]=0;
            dfs(i);
            break;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>n>>m;
        for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) gr[i][j]=gr[j][i]=0;
        vector<int>deg(n+1);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            gr[u][v]=gr[v][u]=1;
            deg[u]++;
            deg[v]++;
        }
        int cnt=0;
        int pr=-1;
        for(int i=1; i<=n; i++)
        {
            if(deg[i]&1)
            {
                if(pr==-1) pr=i;
                else
                {
                    int c=gr[i][pr]?10:2;
                    gr[i][pr]=gr[pr][i]=c,pr=-1;
                }
            }
            else cnt++;
        }
        cout<<cnt<<endl;
        for(int i=1; i<=n; i++)
        {
            dfs(i);
        }
    }
    return 0;
}

