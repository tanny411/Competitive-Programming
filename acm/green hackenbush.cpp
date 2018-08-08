
#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
vector<int>gr[100005];

int dfs(int u,int p)
{
    if(u!=1 && gr[u].size()==1) {/*cout<<u<<" "<<1<<endl;*/return 1;}
    int ret=0;
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v!=p)
        {
            ret^=dfs(v,u);
        }
    }
    ret++;
    //cout<<u<<" "<<ret<<endl;
    return ret;

}

int main()
{
    //cout<<(3^4)<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    if( (dfs(1,-1)-1) ) cout<<"Alice\n";
    else cout<<"Bob\n";
    return 0;
}
/*
13
1 2
2 3
2 4
4 11
11 12
12 13
3 5
5 6
6 7
5 8
8 9
9 10
*/

