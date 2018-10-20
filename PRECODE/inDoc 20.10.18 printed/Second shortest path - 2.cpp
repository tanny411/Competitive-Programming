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

vector<pii>gr[5002];
int d1[5002],d2[5002];
void dijkstra(int s)
{
    d1[s]=0;
    priority_queue<pii,vector<pii>,greater<pii> >q;
    q.push(pii(0,s));
    while(!q.empty())
    {
        int u=q.top().sc;
        q.pop();
        for(int i=0;i<gr[u].size();i++)
        {
            int v=gr[u][i].fs;
            int d=gr[u][i].sc;
            if(d1[u]+d<d1[v])
            {
                int temp=d1[v];
                d1[v]=d1[u]+d;
                d2[v]=min(d2[v],min(temp,min(d2[u]+d,d1[u]+3*d)));
                q.push(pii(d1[v]+d2[v],v));
            }
            else if(d1[u]+d>d1[v] && d1[u]+d<d2[v]) d2[v]=d1[u]+d;
            else d2[v]=min(d2[v],min(d1[u]+3*d,d2[u]+d));
        }
    }
}
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<=n;i++)
        {
            gr[i].clear();
            d1[i]=d2[i]=30000000; ///not giving 1<<30 cuz we'll be adding stuffs to it
        }
        while(m--)
        {
            int x,y,w;
            cin>>x>>y>>w;
            gr[x].pb(pii(y,w));
            gr[y].pb(pii(x,w));
        }
        dijkstra(1);
        cout<<"Case "<<cas++<<": "<<min(d2[n],d2[1]+d1[n])<<endl;
        ///d2[1]+d1[n] case is checked again because when working with
        ///node 1, its d2[1] is not yet found and remains inf
    }
    return 0;
}

