/**
Xenia the programmer has a tree consisting of n nodes. We will consider the tree nodes indexed from 1 to n.
We will also consider the first node to be initially painted red, and the other nodes — to be painted blue.

The distance between two tree nodes v and u is the number of edges in the shortest path between v and u.

Xenia needs to learn how to quickly execute queries of two types:

1.paint a specified blue node in red;
2.calculate which red node is the closest to the given one and print the shortest distance to the closest red node.
Your task is to write a program which will execute the described queries.
*/

//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define dout(n) printf("%d\n",n)
const int N = int(1e5)+10;
const int LOGN = 20;
const int INF = int(1e9);
set<int> g[N];
int par[N],sub[N],level[N],ans[N];
int DP[LOGN][N];
int n,m;
/*Using centroid Decomposition of a tree */

/*----------- Pre-Processing ------------*/
void dfs0(int u)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=DP[0][u])
		{
			DP[0][*it]=u;
			level[*it]=level[u]+1;
			dfs0(*it);
		}
}
void preprocess()
{
	level[0]=0;
	DP[0][0]=0;///LCA table
	dfs0(0);
	for(int i=1;i<LOGN;i++)
		for(int j=0;j<n;j++)
			DP[i][j] = DP[i-1][DP[i-1][j]];
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int d = level[b]-level[a];
	for(int i=0;i<LOGN;i++)
		if(d&(1<<i))
			b=DP[i][b];
	if(a==b)return a;
	for(int i=LOGN-1;i>=0;i--)
		if(DP[i][a]!=DP[i][b])
			a=DP[i][a],b=DP[i][b];
	return DP[0][a];
}
int dist(int u,int v)
{
    int x=u;
    int y=v;
    cout<<"lca  of "<<x<<" and "<<y<<" is "<<lca(x,y)<<endl;
    cout<<"dist "<<level[u] + level[v] - 2*level[lca(u,v)]<<endl;
	return level[u] + level[v] - 2*level[lca(u,v)];

	///in this problem level is the distance
}
/*-----------------Decomposition Part--------------------------*/
int nn;
void dfs1(int u,int p)
{
	sub[u]=1;
	nn++;
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p)
		{
			dfs1(*it,u);
			sub[u]+=sub[*it];
		}
}
int dfs2(int u,int p)
{
	for(auto it=g[u].begin();it!=g[u].end();it++)
		if(*it!=p && sub[*it]>nn/2)
			return dfs2(*it,u);
	return u;
}
void decompose(int root,int p)
{
	nn=0;
	dfs1(root,root);
	int centroid = dfs2(root,root);
	if(p==-1)p=centroid;
	par[centroid]=p;///parent linking in centroid decomposed tree
	for(auto it=g[centroid].begin();it!=g[centroid].end();it++)
	{
		g[*it].erase(centroid);
		decompose(*it,centroid);
	}
	g[centroid].clear();
}
/*----------------- Handle the Queries -----------------*/

void update(int u)
{
	int x = u;
	while(1)
	{
		ans[x] = min(ans[x],dist(x,u));
		if(x==par[x])
			break;
		x = par[x];
	}
}
int query(int u)
{
	int x = u;
	int ret=INF;
	while(1)
	{
		ret = min(ret,dist(u,x) + ans[x]);
		if(x==par[x])
			break;
		x = par[x];
		cout<<"x is "<<x<<endl;
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		g[u-1].insert(v-1);
		g[v-1].insert(u-1);
	}
	preprocess();///made lca table
	decompose(0,-1);
	for(int i=0;i<n;i++)
		ans[i]=INF;
	update(0);//first node is initially painted red
	while(m--)
	{
		int t,v;
		scanf("%d %d",&t,&v);v--;
		if(t==1)
			update(v);
		else
			dout(query(v));
	}
	return 0;
}
