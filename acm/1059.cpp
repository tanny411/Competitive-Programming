
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

///

using namespace std;
vector < pair<int,pii> >edge;
int root[10003];
int dsu(int x){
    if(root[x]==x) return x;
    else return root[x]=dsu(root[x]);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,n,m,a,test=1;
    cin>>t;
    while(t--){
        cin>>n>>m>>a;
        edge.clear();
        for(int i=1;i<=n;i++){
            root[i]=i;
        }
        for(int i=0;i<m;i++){
            int x,y,c;
            cin>>x>>y>>c;
            if(c>=a) continue;
            edge.pb({c,{x,y}});
        }
        sort(edge.begin(),edge.end());
        int sum=0;
        for(int i=0;i<edge.size();i++){
            int u=edge[i].sc.fs;
            int v=edge[i].sc.sc;
            int rootu=dsu(u);
            int rootv=dsu(v);
            if(rootu==rootv) continue;
            root[rootu]=rootv;
            sum+=edge[i].fs;
        }
        set<int>s;
        for(int i=1;i<=n;i++){
            s.insert(dsu(i));
        }
        cout<<"Case "<<test++<<": "<<sum+s.size()*a<<" "<<s.size()<<endl;
    }
    return 0;
}

