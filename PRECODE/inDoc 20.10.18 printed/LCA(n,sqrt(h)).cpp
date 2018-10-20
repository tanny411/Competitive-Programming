//#include<bits/stdc++.h>

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

#include<limits.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

#define clr( a, b )     memset((a),b,sizeof(a))
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))


#define fs first
#define sc second

///ios_base::sync_with_stdio(false)

using namespace std;
#define maxnode 10000
int n;//given no. of nodes;
vector<int>sec(maxnode+2),parent(maxnode+2,-1),lvl(maxnode+2,-1),dist(maxnode+2);
vector<pii>gr[maxnode+2];
//sec=last node of previous section
//bfs level of each node
int nsec,start;//no. of sections


void lca_dfs(int node,int lv)
{
    if(lvl[node]<nsec) sec[node]=start;
    else if(lvl[node]%nsec==0) sec[node]=parent[node];
    else sec[node]=sec[parent[node]];

    for(int i=0; i<gr[node].size(); i++)
    {
        int v=gr[node][i].fs;
        if(lvl[v]!=-1) continue;
        lvl[v]=lv+1;
        parent[v]=node;
        dist[v]=dist[node]+gr[node][i].sc;
        lca_dfs(v,lvl[v]);
    }
}

int query(int x,int y)
{
    //take them up until their ancestor is common in th eupper section
    while(sec[x]!=sec[y])
    {
        if(lvl[x]>lvl[y]) x=sec[x];
        else y=sec[y];
    }
    //for the final section go manually
    while(x!=y)
    {
        if(lvl[x]>lvl[y]) x=parent[x];
        else y=parent[y];
    }
    //max complexity O(2*sqrt(h));
    //sqrt(h) sections should be traversed
    //and final section traversed manually is of length sqrt(h)
    return x;
}
void prn()
{
    for(int i=1; i<=n; i++) cout<<" "<<lvl[i];

    cout<<endl;
    for(int i=1; i<=n; i++) cout<<" "<<dist[i];
}

int main()
{
    cin>>n;
    nsec=sqrt(n);
    int x,y,w;
    int c=n-1;///its a tree
    while(c--)
    {
        cin>>x>>y>>w;
        gr[x].pb(pii(y,w));
        gr[y].pb(pii(x,w));
    }

    start=1;
    lvl[start]=dist[start]=0;
    parent[start]=start;
    lca_dfs(start,0);
    //prn();

    cin>>x>>y;
    cout<<query(x,y)<<endl;

    //distance from x to y
    cout<<dist[x]+dist[y]-2*dist[p]<<endl;
    return 0;
}
