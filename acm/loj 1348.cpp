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
#define nd 30005
vector<int>v(nd),gr[nd];
int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>v[i];
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            cin>>u>>v;
            gr[u].pb(v);
            gr[v].pb(u);
        }

    }
    return 0;
}

