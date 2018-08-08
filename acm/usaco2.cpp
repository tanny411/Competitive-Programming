/*
ID: aysha.k1
TASK: gift1
LANG: C++
*/

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

using namespace std;

int main()
{
    freopen("gift1.in","r",stdin);
    freopen("gift1.out","w",stdout);

    int n,s,d,x;
    string a,b;
    map<string,int>m;
    cin>>n;
    vector<string>ara(n+2);
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a>>s>>d;
        if(d==0) continue;
        x=s/d;
        m[a]+=-s+(s-(x*d));
        while(d--)
        {
            cin>>a;
            m[a]+=x;
        }
    //cout << "Input nisi"<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<ara[i]<<" "<<m[ara[i]]<<endl;
    }
    return 0;
}

