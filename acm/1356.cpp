///TLE

#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long

#define fs first
#define sc second
#define II ( { int a ; read(a) ; a; } )
using namespace std;

struct Reader {
  int b; Reader() { read(); }
  void read() { b = getchar(); }
  void skip() { while (0 <= b && b <= 32) read(); }
  unsigned int next_u32() {
    unsigned int v=0; for (skip(); 48<=b&&b<=57; read()) v = 10*v+b-48; return v; }
  int next_int() {
    int v = 0; bool s = false;
    skip(); if (b == '-') { s = true; read(); }
    for (; 48<=b&&b<=57; read()) v = v*10 + b-48; return s ? -v : v; }
  char next_char() { skip(); char c = b; read(); return c; }
  void next(char *s) { for (skip(); b > 32; read()) *s++ = b; *s = 0; }
  bool has_next() { skip(); return b > 0; }
  bool has_next_u32() { skip(); return 48 <= b && b <= 57; }
  bool has_next_int() { skip(); return b == 45 || (48 <= b && b <= 57); }
  void skip_line() {
    for (; b != 10 && b != 13 && b >= 0; read());
    char p = b; read();
    if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
  void next_line(char *s) {
    for (; b != 10 && b != 13 && b >= 0; read()) *s++ = b; *s = 0;
    while (b == 10 || b == 13) read(); }
  void next_real_line(char *s, int &l) {
    for (l = 0; b != 10 && b != 13 && b >= 0; read()) *s++ = b, ++l;
    *s = 0; char p = b; read();
    if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
};
#define mx 500005
vector<int>prime;
int par[mx];
#define NIL 0
#define INF (1<<28)
vector< int > G[mx];
int n,match[mx],dist[mx],ara[mx];
void sieve()
{
    prime.pb(2);
    for(ll i=3;i<mx;i+=2)
    {
        if(dist[i]==0) {
            prime.pb(i);
            for(ll j=i*i;j<mx;j+=(i+i)) dist[j]=1;
        }
    }
}
bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(par[ara[i]]) continue;
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    memset(match,0,sizeof match);
    while(bfs())
        for(i=1; i<=n; i++){
            if(par[ara[i]]) continue;
            if(match[i]==NIL && dfs(i))
                matching++;
        }
    return matching;
}

int main()
{
    sieve();
    int sz=prime.size();
    for(int i=1;i<mx;i++)
    {
        int temp=i;
        for(int j=0;j<sz && prime[j]*prime[j]<=temp;j++)
        {
            if(temp%prime[j]==0){
                while(temp%prime[j]==0) temp/=prime[j],par[i]^=1;
            }
        }
        if(temp>1) par[i]^=1;
    }
    //for(int i=0;i<100;i++) cout<<i<<" "<<par[i]<<endl;
    int test=1;
    Reader rd;
    int t = rd.next_int();
    while(t--)
    {
        n = rd.next_int();
        memset(match,0,sizeof match);
        int mxx=-1;
        for(int i=1;i<=n;i++) ara[i]=rd.next_int(),match[ara[i]]=i,mxx=max(mxx,ara[i]);
        for(int i=0;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++)
        {
          for(int j=0;j<sz;j++)
          {
              int y = prime[j] * ara[i];
              if( y > mxx ) break ;
              if(  match[y]>0 )
              {
                  G[match[y]].pb(i);
                  G[i].pb(match[y]);
              }
          }
        }
//        for(int i=0;i<n;i++)
//        {
//            int temp=dist[i];
//            for(int j=0;j<sz && prime[j]*prime[j]<=temp;j++)
//            {
//                if(temp%prime[j]) continue;
//                while(temp%prime[j]==0) temp/=prime[j];
//                int x=dist[i]/prime[j];
//                if(match[x]>0)
//                {
//                    if(par[dist[i]]) G[i].pb(match[x]-1);
//                    else G[match[x]-1].pb(i);
//                }
//            }
//            if(temp>1 && match[1]>0)
//            {
//                if(par[dist[i]]) G[i].pb(match[1]-1);
//                else G[match[1]-1].pb(i);
//            }
//        }
//        for(int i=1;i<=n;i++)
//        {
//            cout<<"U="<<i<<":";
//            for(int j=0;j<G[i].size();j++) cout<<" "<<G[i][j]; cout<<endl;
//        }
        //cout<<"BPM "<<maxBPM(n)<<endl;
        printf("Case %d: %d\n",test++,n-hopcroft_karp());
    }
    return 0;
}

