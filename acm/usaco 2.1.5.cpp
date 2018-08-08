/*
ID: aysha.k1
LANG: C++11
TASK: hamming
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

int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    int n,b,d;
    cin>>n>>b>>d;
    vector<int>v(1);
    for(int i=1;i<(1<<b) && v.size()<n;i++)
    {
        int f=1;
        for(int j=0;j<v.size();j++)
        {
            if(__builtin_popcount(v[j]^i)<d)
            {
                f=0;
                break;
            }
        }
        if(f) v.pb(i);
    }
    cout<<v[0];
    for(int i=1;i<n;i++)
    {
        if(i%10==0) cout<<endl<<v[i];
        else cout<<" "<<v[i];
    }
    cout<<endl;
    return 0;
}

