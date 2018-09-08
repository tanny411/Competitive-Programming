#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

///ios_base::sync_with_stdio(false);

using namespace std;

#define mxnode 1000

struct edge{
    int v,flow,cap,index;///index of reverse edge in gr[v]
    edge() {}
    edge(int a,int b,int c,int d)
    {
        v=a;flow=b;cap=c;index=d;
    }
};

vector<edge>gr[mxnode];
vector<int>level,start;

bool bfs(int s,int t,int n)
{
    level=vector<int>(n,-1);
    level[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<gr[u].size();i++)
        {
            edge e=gr[u][i];
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
    int total=0;
    while(bfs(s,t,n)==true)
    {
        start=vector<int>(n);
        while(int flow=dfs(s,t,INT_MAX))
        {
            total+=flow;
        }
    }
    return total;
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y,c;
        cin>>x>>y>>c;
        edge a(y,0,c,(int)gr[y].size());
        edge b(x,0,0,(int)gr[x].size());
        gr[x].pb(a);
        gr[y].pb(b);
    }
    int s,t;
    cin>>s>>t;
    cout<<Dinic(s,t,n)<<endl;
}
/**
6
10
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4
0 5
ans:23
*/
/*
6
10
0 1 3
0 2 7
1 3 9
1 4 9
2 1 9
2 4 9
2 5 4
3 5 3
4 5 7
0 4 10
0 5
ans:14
*/
/*
6
9
0 1 10
0 2 10
1 3 4
1 4 8
1 2 2
2 4 9
3 5 10
4 3 6
4 5 10
0 5
ans:19
*/
