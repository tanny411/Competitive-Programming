/*
ID: aysha.k1
LANG: C++11
TASK: holstein
*/
//#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back()

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
vector<int>r;

vector<int>vit(50);
int v,f;
int ara[20][50];
int mn=1<<30;
vector<int>ans;
int all=0,alll=0;
void rec(int pos,vector<int>vt)
{
    int fi=0;
    for(int i=0;i<v;i++)
    {
        if(vt[i]<vit[i])
        {
            fi=1;
            break;
        }
    }
    if(fi==0 && mn>=r.size())
    {
        if(mn>r.size())
        {
            mn=r.size();
            ans=r;
        }
        else if(ans[0]>r[0]) ans=r;
    }
    if(fi==0 || pos==f) return;
    rec(pos+1,vt);
    for(int i=0;i<vt.size();i++)
    {
        vt[i]+=ara[pos][i];
    }
    r.pb(pos);
    rec(pos+1,vt);
    r.Pb;

}

int main()
{

    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    cin>>v;
    for(int i=0;i<v;i++)
    {
        cin>>vit[i];
    }
    cin>>f;
    for(int i=0;i<f;i++)
    {
        for(int j=0;j<v;j++)
        {
            cin>>ara[i][j];
        }
    }
    rec(0,vector<int>(v));
    cout<<mn;
    for(int i=0;i<ans.size();i++)
    {
        cout<<" "<<ans[i]+1;
    }
    cout<<endl;
    return 0;
}

