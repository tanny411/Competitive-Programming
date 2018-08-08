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

int n,lg;
vector<int>v(1000);
int table[1000][1000];///[n][lg];

void prn()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=lg;j++)
        {
            cout<<table[i][j];
        }
        cout<<endl;
    }
}

void pre_process()
{
    ///O(nlogn)
    ///table stores index of minimum array element from i to i+2^j -1
    for(int j=0; (1<<j)<=n ;j++ ) /// small to big ranges
    {
        for(int i=0; i+(1<<j)-1<n; i++)
        {
            if(j==0) table[i][j]=i;
            else
            {
                if(v[table[i][j-1]]<v[table[i+(1<<(j-1))][j-1]])
                {
                    table[i][j]=table[i][j-1];
                }
                else table[i][j]=table[i+(1<<(j-1))][j-1];
            }
        }
    }
    //prn();
}

int query(int l,int r)
{
    ///O(1)
    int Lg=log2(r-l+1);
    ///nearsest power of 2 to the range l to r;
    return min(v[table[l][Lg]],v[table[r-(1<<Lg)+1][Lg]]);
}

int main()
{
    cin>>n;
    lg=log2(n);
    for(int i=0;i<n;i++) cin>>v[i];
    pre_process();
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<query(x,y)<<endl;
    }
    return 0;
}

