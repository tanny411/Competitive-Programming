#include<bits/stdc++.h>

#define pb push_back

#define pii pair<double,double>

#define fs first
#define sc second

#define mx 1e7

using namespace std;

struct edge{
    int v,cap,flow,index;
    edge(){}
    edge(int a,int b,int c,int d){
        v=a;cap=b;flow=c;index=d;
    }
};

vector<edge>gr[500];
vector<int>start(500),level(500);

bool bfs(int s,int t,int n)
{
    fill(level.begin(), level.begin()+n, -1);
    level[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<gr[u].size();i++)
        {
            edge &e=gr[u][i];
            if(level[e.v]==-1 && e.flow<e.cap)
            {
                level[e.v]=level[u]+1;
                q.push(e.v);
            }
        }
    }
    return (level[t]!=-1);
}
int dfs(int u,int t,int f)
{
    if(u==t) return f;
    for(;start[u]<gr[u].size();start[u]++)
    {
        edge &e=gr[u][start[u]];
        if(level[e.v]==level[u]+1 && e.flow<e.cap)
        {
            int cur_flow=min(f,e.cap-e.flow);
            int temp_flow=dfs(e.v,t,cur_flow);
            if(temp_flow>0)
            {
                e.flow+=temp_flow;
                gr[e.v][e.index].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

int Dinic(int s,int t,int n)
{
    if(s==t) return 0;
    ///clear flow
    for(int i=0;i<n;i++){
        for(int j=0;j<gr[i].size();j++){
            gr[i][j].flow=0;
        }
    }
    int total=0;
    while(bfs(s,t,n))
    {
        fill(start.begin(), start.begin() + n, 0);
        while(1){
            int flow=dfs(s,t,mx);
            if(flow<=0) break;
            total+=flow;
        }
    }
    return total;
}
void addEdge(int s, int t, int cap1)
{
    edge a = edge(t,cap1,0,gr[t].size());
    edge b = edge(s,0,0,gr[s].size());
    gr[s].push_back(a);
    gr[t].push_back(b);

}
int main()
{
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    int test=1;
    while(t--)
    {
        int n;
        double d;
        cin>>n>>d;

        int source=0,pengs=0;
        for(int i=0;i<2*n+5;i++) gr[i].clear();

        vector<pii>v(n+2);

        for(int i=1;i<=n;i++){
            double x,y;
            int p,m;
            cin>>x>>y>>p>>m;
            pengs+=p;
            v[i]=pii(x,y);

            ///super-source to each node with capacity=#of penguin
            addEdge(source,i,p);

            ///split node into 2 with capacity=#of jump offs
            addEdge(i,i+n,m);

            ///edges to other nodes with distance<=d
            for(int j=1;j<i;j++){
                x=fabs(v[i].fs-v[j].fs);
                y=fabs(v[i].sc-v[j].sc);
                double dist=sqrt(x*x+y*y);
                if(dist+1e-9 <= d){
                    addEdge(i+n,j,1e7);
                    addEdge(j+n,i,1e7);
                }
            }
        }
        int ok=0;
        cout<<"Case "<<test++<<":";
        for(int i=1;i<=n;i++){
            int flow=Dinic(source,i,n+n+1);
            if(flow==pengs){
                ok=1;
                cout<<" "<<i-1;
            }
        }
        if(!ok) cout<<" -1";
        cout<<endl;
    }
    return 0;
}
