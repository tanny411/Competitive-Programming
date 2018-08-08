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
vector<int>gr[1005];
map<string,int>mp;
int nd=1;
int dfs(int u)
{
    if(gr[u].empty()) return 1;
    vector<int>v;
    for(int i=0;i<gr[u].size();i++)
    {
        v.pb(dfs(gr[u][i]));
    }
    sort(v.rbegin(),v.rend());
    int mx=v[0];
    int rem=mx-1;
    for(int i=1;i<v.size();i++)
    {
        if(v[i]>rem)
        {
            mx+=v[i]-rem;
            rem=v[i]-1;
        }
    }
    if(rem==0) mx++;
    return mx;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        if(mp[s]==0) mp[s]=nd++;
        int u=mp[s];
        int x;
        cin>>x;
        while(x--)
        {
            cin>>s;
            if(s[0]>='A' && s[0]<='Z')
            {
                if(mp[s]==0) mp[s]=nd++;
                gr[u].pb(mp[s]);
            }
        }
    }
    cout<<dfs(1)<<endl;
    return 0;
}

