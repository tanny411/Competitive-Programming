/*
ID: aysha.k1
LANG: C++11
TASK: sort3
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

    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    int n;
    cin>>n;
    vector<int>v(n),srt(n);
    for(int i=0; i<n; i++)
    {
        cin>>v[i];
        srt[i]=v[i];
    }
    sort(srt.begin(),srt.end());
    int in=0;
    int ara[5][5];
    memset(ara,0,sizeof ara);
    while(in<n)
    {
        ara[srt[in]][v[in]]++;
        in++;
    }
    int ans=0;
    int mn=min(ara[1][2],ara[2][1]);
    ans+=mn;
    ara[1][2]-=mn;ara[2][1]-=mn;
    mn=min(ara[1][3],ara[3][1]);
    ans+=mn;
    ara[1][3]-=mn;ara[3][1]-=mn;
    mn=min(ara[3][2],ara[2][3]);
    ans+=mn;
    ara[3][2]-=mn;ara[2][3]-=mn;
    ans+=2*max(ara[1][2],ara[2][1]);
    cout<<ans<<endl;
    /*
    cout<<" "<<ara[1][2]<<" "<<ara[2][1]<<" ";
    cout<<" "<<ara[1][3]<<" "<<ara[3][1]<<" ";
    cout<<" "<<ara[3][2]<<" "<<ara[2][3]<<" ";*/
    return 0;
}


