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
#define maxnode 10000+2
#define logmaxnode (int)log2(10000)+2
using namespace std;
int n,start;
vector<int>gr[maxnode],lvl(maxnode,-1),parent(maxnode);

void _dfs(int node)
{
    for(int i=0; i<gr[node].size(); i++)
    {
        int v=gr[node][i];
        if(lvl[v]!=-1) continue;
        parent[v]=node;
        lvl[v]=lvl[node]+1;
        _dfs(v);
    }
}

int table[maxnode][logmaxnode];

void init_lca()
{
    memset(table,-1, sizeof table);

    for(int j=0; (1<<j)<n; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(j==0) table[i][j]=parent[i];
            else if(table[i][j-1]!=-1) table[i][j]=table[table[i][j-1]][j-1];
        }
    }
}

int lca_query(int p,int q)
{
    if(lvl[q]>lvl[p]) swap(p,q);

    //int lg=log2(lvl[p]);
    int lg;
    for(lg=1; (1<<lg)<=lvl[p]; lg++);
    lg--;

    for(int i=lg; i>=0; i--)
    {
        if(lvl[p]-(1<<i)>=lvl[q])
        {
            p=table[p][i];
        }
    }

    if(p==q) return q;

    for(int i=lg; i>=0; i--)
    {
        if(table[p][i]!=-1 && table[p][i]!=table[q][i])
        {
            p=table[p][i];
            q=table[q][i];
        }
    }

    return parent[p];
}

int main()
{
    int m;
    cin>>n>>m;
    int x,y;
    while(m--)
    {
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    start=0;
    lvl[start]=0;
    parent[start]=start;

    _dfs(start);
    init_lca();
    int q;
    cin>>q;
    while(q--)
    {

        cin>>x>>y;
        cout<<lca_query(x,y)<<endl;

    }
    return 0;
}

