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

#define maxnode 10000+5
int n,N;
vector<int>lvl,euler,firstocc(maxnode,-1),gr[maxnode];
///lvl: lvl[i] is the lvl of the node in euler[i]
///euler: euler tour er nodes serially
///index of each nodes first occurences in euler;


void prn()
{
    cout<<"euler :";
    for(int i=0;i<euler.size();i++) cout<<" "<<euler[i];
    cout<<endl<<"firstocc :";
    for(int i=0;i<n;i++) cout<<" "<<firstocc[i];
    cout<<endl<<"lvl :";
    for(int i=0;i<lvl.size();i++) cout<<" "<<lvl[i];
    cout<<endl;
}

void dfs(int u,int lv)
{
    euler.pb(u);
    lvl.pb(lv);
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(firstocc[v]==-1)
        {
            firstocc[v]=euler.size();
            dfs(v,lv+1);
            euler.pb(u);
            lvl.pb(lv);
        }
    }
}

///RMQ
/*
->E[1, 2*N-1] – the nodes visited in an Euler Tour of T;
E[i] is the label of i-th visited node in the tour
->L[1, 2*N-1] – the levels of the nodes visited in the Euler Tour;
L[i] is the level of node E[i]
->H[1, N] – H[i] is the index of the first occurrence of node i in E
(any occurrence would be good, so it’s not bad if we consider the first one)
-->Assume that H[u] < H[v] (otherwise you must swap u and v).
It’s easy to see that the nodes between the first occurrence of u and the first
occurrence of v are E[H[u]…H[v]]. Now, we must find the node situated on the smallest level.
For this, we can use RMQ. So, LCAT(u, v) = E[RMQL(H[u], H[v])] (remember that RMQ returns the index).
*/
int st[2*maxnode+2][(int)log2(2*maxnode)+2];
void prep()
{
    for(int j=0;(1<<j)<=N;j++)
    {
        for(int i=0;i+(1<<j)-1<N;i++)
        {
            if(j==0) st[i][j]=i;
            else if(lvl[st[i][j-1]]<lvl[st[i+(1<<(j-1))][j-1]]) st[i][j]=st[i][j-1];
            else st[i][j]=st[i+(1<<(j-1))][j-1];
        }
    }
}

int RMQ(int x,int y)
{
    int ans;
    int lg=log2(y-x+1);
    if(lvl[st[x][lg]]<lvl[st[y-(1<<lg)+1][lg]]) ans=st[x][lg];
    else ans=st[y-(1<<lg)+1][lg];
    return ans;
}

int main()
{
    cin>>n;
    while(1)
    {
        int x,y;
        cin>>x>>y;
        if(x==-1 && y==-1) break;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    int start=1;
    firstocc[start]=0;
    dfs(start,0);
    N=euler.size();
    prep();
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(firstocc[x]>firstocc[y]) swap(x,y);
        int Q=RMQ(firstocc[x],firstocc[y]);
        cout<<euler[Q]<<endl;
    }
    //prn();
    return 0;
}
/*
14
1 2
1 3
1 4
3 5
3 6
3 7
6 8
6 9
7 10
7 11
10 12
10 13
-1 -1

*/
