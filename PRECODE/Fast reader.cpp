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

using namespace std;

#define II ( { int a ; read(a) ; a; } )
#define LL ( { Long a ; read(a) ; a; } )
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}

struct Reader {
  int b; Reader() { read(); }
  void read() { b = getchar_unlocked(); }
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
int main()
{
    //fisrt way
    int t=II;
    //second way
    Reader rd;
    int n = rd.next_int();
    return 0;
}

