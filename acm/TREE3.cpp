#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
vector<int>v[100006];
int flag[100006];
int f=0;
vector<pair<pii,pii> >ans;

int dfs(int u,int p)
{
    if(f) return 0;
    flag[u]=1;
    int cnt=0;
    int ara[4];
    for(int i=0;i<v[u].size();i++)
    {
        int c=v[u][i];
        if(flag[c]) continue;
        if(dfs(c,u))
        {
            if(cnt<3)
            {
                ara[cnt]=c;
                cnt++;
                if(cnt==3)
                {
                    cnt=0;
                    ans.pb({ {u,ara[1]},{ara[2],ara[0]} });
                }
            }
        }
        if(f) return 0;
    }
    if(cnt==2 && p!=-1)
    {
        ans.pb({ {u,ara[1]},{p,ara[0]} });
        return 0;
    }
    else if(cnt==0) return 1;
    else
    {
        f=1;
        return 0;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        f=0;
        for(int i=1;i<=n;i++) {v[i].clear();flag[i]=0;}
        ans.clear();
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        if((n-1)%3!=0)
        {
            cout<<"NO\n";
            continue;
        }
        dfs(1,-1);
        if(f) {cout<<"NO\n";continue;}
        cout<<"YES\n";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i].fs.fs<<" "<<ans[i].fs.sc<<" "<<ans[i].sc.fs<<" "<<ans[i].sc.sc<<endl;
        }
    }
    return 0;
}

