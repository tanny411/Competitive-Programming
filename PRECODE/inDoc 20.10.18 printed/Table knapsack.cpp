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

int main()
{
    int n;
    cin>>n;
    vector<int>cost(n+1),weight(n+1);
    for(int i=1;i<=n;i++) cin>>cost[i];
    for(int i=1;i<=n;i++) cin>>weight[i];
    int cap;
    cin>>cap;
    int tbl[n+1][cap+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            if(i==0 || j==0) tbl[i][j]=0;
            else
            {
                if(j-weight[i]>-1) tbl[i][j]=max(tbl[i-1][j],cost[i]+tbl[i-1][j-weight[i]]);
                else tbl[i][j]=tbl[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=cap;j++)
        {
            cout<<" "<<tbl[i][j];
        }
        cout<<endl;
    }
    cout<<tbl[n][cap]<<endl;
    return 0;
}

