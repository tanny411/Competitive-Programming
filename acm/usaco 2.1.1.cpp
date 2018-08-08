/*
ID: aysha.k1
LANG: C++11
TASK: castle
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


int dx[]= {0,-1,0,1};
int dy[]= {-1,0,1,0};
int in[100][100];
int com,val;
int vis[100][100];
int no[100];
int mx=-1<<30;

void dfs(int si,int sj)
{
    val++;
    vis[si][sj]=com;
    //cout<<si<<"  "<<sj<<"  :"<<endl;
    for(int i=0; i<4; i++)
    {
        if(in[si][sj]&(1<<i)) continue;
        int x=si+dx[i];
        int y=sj+dy[i];
        //cout<<x<<" "<<y<<endl;
        if(vis[x][y]==0) dfs(x,y);
    }
}

int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    int m,n;
    cin>>m>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>in[i][j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j]==0)
            {
                com++;
                val=0;
                dfs(i,j);
                no[com]=val;
                mx=max(mx,val);
            }
        }
    }
    cout<<com<<endl;
    cout<<mx<<endl;
    mx=-1<<30;
    pii module;
    char side;
    for(int j=0;j<m;j++)
    {
        for(int i=n-1;i>=0;i--)
        {
            if((in[i][j]&(2))>0 && i!=0 && vis[i][j]!=vis[i-1][j])
            {
                if(mx<no[vis[i][j]]+no[vis[i-1][j]])
                {
                    mx=no[vis[i][j]]+no[vis[i-1][j]];
                    module=pii(i,j);
                    side='N';
                }
            }
            if((in[i][j]&(4))>0 && j!=m-1 && vis[i][j]!=vis[i][j+1])
            {
                if(mx<no[vis[i][j]]+no[vis[i][j+1]])
                {
                    mx=no[vis[i][j]]+no[vis[i][j+1]];
                    module=pii(i,j);
                    side='E';
                }
            }
        }
    }
    /*
    for(int i=1;i<=com;i++)
    {
        cout<<" "<<no[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<" "<<vis[i][j];
        }
        cout<<endl;
    }
    */
    cout<<mx<<endl;
    cout<<module.fs+1<<" "<<module.sc+1<<" "<<side<<endl;
    return 0;
}

