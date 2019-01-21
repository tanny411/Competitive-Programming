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

using namespace std;
int root[1000];
int Find(int x){
    if(root[x]==x) return x;
    return root[x]=Find(root[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    int n,m;
    cin>>n>>m;
    //for(int i=1;i<=n;i++) root[i]=i;
    vector<pii>v[n+1];
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(pii(x,i));
        v[y].pb(pii(y,i));
    }
    for(int i=1,col=m+1;i<=n;i++)
    {
        if(v[i].empty()) {
            cout<<1<<endl;
            cout<<i<<" "<<col++<<endl;
            continue;
        }
        cout<<v[i].size()<<endl;
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j].fs<<" "<<v[i][j].sc<<endl;
        }
    }
    return 0;
}

