/*
এটি একটি NP-hard প্রবলেম,অর্থাৎ এই প্রবলেমের কোনো পলিনমিয়াল টাইম সলিউশন নেই।
তবে গ্রাফটি যদি Tree হয় অর্থাত n-1 টা edge থাকে আর কোনো সাইকেল না থাকে তাহলে
ডাইনামিক প্রোগ্রামিং বা ম্যাক্স ফ্লো/বাইপারটাইট ম্যাচিং এর সাহায্যে প্রবলেমটি সলভ করা সম্ভব।
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
/// minimum vertex cover
using namespace std;
vector<int>g[100005];
int dp[100005][2];
int minvert(int p,int u,int taken)
{
    if(dp[u][taken]!=-1) return dp[u][taken];
    int mx=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==p) continue;
        if(taken==0)
        {
            mx+=minvert(u,v,1);
        }
        else
        {
            mx+=min(minvert(u,v,1),minvert(u,v,0));
        }
    }
    return dp[u][taken]=mx+taken;
}
int main()
{
    int n,x,y;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    cout<<min(minvert(-1,1,0),minvert(-1,1,1))<<endl;
    return 0;
}

