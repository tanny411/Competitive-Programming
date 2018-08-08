/*
ID: aysha.k1
LANG: C++11
TASK: frac1
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

bool cmp(pii a,pii b)
{
    double aa=a.fs*1.0/a.sc;
    double bb=b.fs*1.0/b.sc;
    if(aa<bb) return true;
    else return false;
}

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);

    int n;
    cin>>n;
    vector<pii>v;
    map<pii,int>m;
    v.pb(pii(0,1));
    v.pb(pii(1,1));
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            int g=gcd(i,j);
            if(!m[pii(j/g,i/g)])
            {
                m[pii(j/g,i/g)]=1;
                v.pb(pii(j/g,i/g));
            }
        }
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i].fs<<"/"<<v[i].sc<<endl;
    }
    return 0;
}

