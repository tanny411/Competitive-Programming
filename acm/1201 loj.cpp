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

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>gr[n+1],notified(n+1),deg(n+1);
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            gr[u].pb(v);
            gr[v].pb(u);
            deg[u]++;
            deg[v]++;
        }
        int cnt=0;
        queue<int>q;
        for(int i=1; i<=n; i++)
        {
            if(deg[i]==0) cnt++;
            else if(deg[i]==1) q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(notified[u]==0)cnt++;
            for(int i=0; i<gr[u].size(); i++)
            {
                int v=gr[u][i];
                if(!notified[u])notified[v]=1;
                deg[v]--;
                if(deg[v]==1) q.push(v);
            }
        }
        cout<<"Case "<<cas++<<": "<<cnt<<"\n";
    }
    return 0;
}
/**
1

7 6
1 2
2 3
3 4
4 5
5 6
6 7
*/
