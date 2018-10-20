#include <bits/stdc++.h>
using namespace std;

/*------- Constants---- */

#define LL                      long long
#define ull                     unsigned long long
#define mod                     1000000007
#define MEMSET_INF              63
#define MEM_VAL                 1061109567
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define lop(i,a,b)              for( int i = (a) ; i < (b) ; i++)
#define pb(a)                   push_back((a))
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define inf                     1<<29
#define lc                      ((n)<<1)
#define rc                      ((n)<<1 |1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define DI(n)                   int n;sc(n)
#define DII(a,b)                int a,b;sc(a);sc(b)
#define DIII(a,b,c)             int a,b,c;sc(a);sc(b);sc(c)
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a):(b))

/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
/*------ template functions ------ */
#ifndef getchar_unlocked
#define getchar_unlocked getchar
#endif
template<class T> inline void sc(T &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 | c>57) && c != '-');c = gc());
      if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
template <class T> inline T bigmod(T p,T e,T M){LL ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;} return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

/*************************** END OF TEMPLATE ****************************/
const int N = 1e5+5;
int SZ = 0;
const int LM = 17;
int P[N][LM];
vi G[N];
int sub[N];
int dep[N];
bool deleted[N];
int Par[N];


/***************** LCA *****************/
void dfs(int u,int p,int d=0)
{
      P[u][0] = p;
      dep[u] = d;
      for(int i=1;i<LM ; i++){
            if(P[u][i-1] !=-1 ) P[u][i] = P[P[u][i-1]][i-1];
      }
      for(auto a: G[u]) if(p!=a){
            dfs(a,u,d+1);
      }
}

int lca(int u,int v)
{
      if(dep[u] > dep[v]) swap(u,v);
      for(int i = LM-1; i>=0 ; i-- ) {
            int nw = dep[v]- (1<<i);
            if(nw >= dep[u]) v = P[v][i];
      }
      if(u==v)return v;
      for(int i= LM-1; i>=0 ; i-- ) {
            if(P[u][i] != P[v][i]) u = P[u][i], v=P[v][i];
      }
      return P[u][0];
}

int dist(int u,int v)
{
      int l = lca(u,v);
      return dep[u] + dep[v] - 2* dep[l];
}

/**************** DECOMPOSITION *************/
void dfs1(int u,int p)
{
      sub[u] =1;
      SZ ++;
      for(auto a: G[u]){
            if(a==p|| deleted[a] )continue;
            dfs1(a,u);
            sub[u] += sub[a];
      }
}

int find_root(int u,int p)
{

      for(auto a: G[u]) {
            if(a==p|| deleted[a]) continue;
            if(sub[a] > SZ/2) {
                  return find_root(a,u);
            }
      }
      return u;
}
void decompose(int u,int p)
{
      SZ = 0;
      dfs1(u,-1);
      int root = find_root(u,-1);
      Par[root] = p;
      deleted[root]  =1;

      for(auto a : G[root]) {
            if(deleted[a] || a == p )continue;
            decompose(a,root);
      }
}


/**********************************************/

int ans[N];
void update(int u)
{
      int v = u;
      while(v>0){
            ans [v] = min(ans[v] , dist(v,u));
            v = Par[v];
      }

}

int query(int u)
{
      int ret  = inf;
      int v = u;
      while(v>0){
            ret = min(ret , ans[v] + dist(v,u));
            v = Par[v];
      }
      return ret;

}


int main()
{
      ms(P,-1);
      DII(n,m);
      forn(i,n-1){
            DII(a,b);
            G[a].pb(b);
            G[b].pb(a);
      }
      dfs(1,-1);
      decompose(1,-1);

      forn(i,n+1) ans[i] = inf;
      update(1);
      forn(i,m){
            DII(t,k);
            if(t==1){
                  update(k);
            }
            else {
                  printf("%d\n", query(k));
            }
      }
      return 0;
}
