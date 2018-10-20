#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)

#define pf1(x) printf("%d\n", x)

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long
#define clr( a, b )     memset((a),b,sizeof(a))
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))


#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

template <class T>

struct Dijkstra
{
    int n;
    vector< vector< pair<int,T> > > adj; ///the weight can be int/double so we use template
    ///when calling Dijkstra we put the type in <T>
    vector<T>dist;
    vector<int>parent;
    Dijkstra (int n): n(n),adj(n){}
    void addedge(int x,int y,T w)
    {
        adj[x].pb( {y,w} );
        adj[y].pb( {x,w} );
    }
    void shortestpath(int src)
    {
        priority_queue<pair<T,int>,vector<pair<T,int>> , greater<pair<T,int>> >q;
        dist = vector<T>(n,numeric_limits<T>::max()); ///T type er max value is in numeric limits max()
        parent = vector<int>(n,-1);
        dist[src]=0;
        parent[src]=src;
        q.push({0,src});
        while(!q.empty())
        {
            int u=q.top().sc;
            q.pop();
            for(int i=0;i<adj[u].size();i++)
            {
                int v=adj[u][i].fs;
                T vd=adj[u][i].sc;
                if(dist[u]<dist[v]-vd)///to avoid overflow
                {
                    dist[v]=dist[u]+vd;
                    q.push({dist[v],v});
                    parent[v]=u;
                }
            }
        }
    }
};

using namespace std;

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n,m,s,d;
        cin>>n>>m>>s>>d;
        Dijkstra<int> D(n);
        while(m--)
        {
            int x,y,w;
            cin>>x>>y>>w;
            D.addedge(x,y,w);
        }
        D.shortestpath(s);
        cout<<"Case #"<<cas++<<": ";
        if(D.dist[d]==numeric_limits<int>::max()) cout<<"unreachable"<<endl;
        else cout<<D.dist[d]<<endl;
    }

    return 0;
}

