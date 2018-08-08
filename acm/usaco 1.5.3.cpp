/*
ID: aysha.k1
LANG: C++11
TASK: sprime
*/
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

int n;
vector<int>prime;
void sieve()
{
    prime.pb(2);
    int mx=sqrt(1000000000)+3;
    vector<int>flag(mx+2);
    for(int i=3;i<mx;i+=2)
    {
        if(flag[i]) continue;
        prime.pb(i);
        for(int j=i*i;j<mx;j+=(i+i)) flag[j]=1;
    }
}

int isprime(int x)
{
    if(x<=1) return 0;
    for(int i=0;i<prime.size() && prime[i]*prime[i]<=x ;i++)
    {
        if(x%prime[i]==0) return 0;
    }
    return 1;
}

vector<int>ans;

void rec(int pos,int num)
{
    if(pos==n) { ans.pb(num); return; }
    int start=pos==0?1:0;
    for(int i=start;i<10;i++)
    {
        if(isprime( num*10+i )) rec(pos+1,num*10+i);
    }
}

int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    sieve();
    cin>>n;
    //cout<<prime.size()<<endl;
    rec(0,0);
    //cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<endl;
    return 0;
}

