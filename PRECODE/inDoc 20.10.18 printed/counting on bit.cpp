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

int normal_count(int n)
{
    int cnt=0;
    while(n)
    {
        cnt+=n&1;
        n=n>>1;
    }
    return cnt;
}

int Brian_Kernighan(int n)
{
    int cnt=0;
    while(n)
    {
        n=n&(n-1);
        cnt++;
    }
    return cnt;
}
///http://www.geeksforgeeks.org/next-higher-number-with-same-number-of-set-bits/
/**
Going upwards:
Find the rightmost occurrence of "01" in the number and make it "10".
Justify all following 1-bits as far to the right as possible.

Going downwards:
Find the rightmost occurrence of "10" in the number and make it "01".
Left-justify all following 1-bits (i.e. don't do anything if the bit you just set is already followed by a 1).
*/
int next_greater(int n)
{
    int a=(~n)+1; //-n
    int t=a&n;
    int x=n+t;
    int y=x^n;
    y=y/t;
    y=y>>2;
    return x|y;
}
int next_small(int y)
{
    int t = y + 1;
    int u = t ^ y;
    int v = t & y;
    return v - (v & -v) / (u + 1);
}
int main()
{
    ///built_in
    //cout<< __builtin_popcount(7) << endl;
    /*
    __builtin_popcount = int
    __builtin_popcountl = long int
    __builtin_popcountll = long long
    */
    cout<<next_greater(156)<<endl;
    return 0;
}

