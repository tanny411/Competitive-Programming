#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;
// int root[100003];
// int Find(int x){
//     if(root[x]==x) return x;
//     else return root[x]=Find(root[x]);
// }
vector<int>graph[100003],flag,ans,nodes; //,arekflag;
struct ret{
    int nedges=0;
    int odd=-1;
    ret(){}
    ret(int nedges,int odd):nedges(nedges),odd(odd){}
    void pr(){
        cout<<" "<<nedges<<" "<<odd<<endl;
    }
};

ret dfs(int u){
    flag[u]=1;
    // arekflag[u]=1;
    int odd=-1;
    if(graph[u].size()&1) odd=u;
    nodes.pb(u);
    int nedges=0;

    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        nedges+=flag[v];
    }
    for(int i=0;i<graph[u].size();i++){
        int v=graph[u][i];
        if(!flag[v]){
            ret a=dfs(v);
            if(odd==-1 && a.odd!=-1) odd=a.odd;
            nedges+=a.nedges;
        }
    }
    return ret(nedges,odd);
}

int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) graph[i].clear();
        flag=vector<int>(n+1);
        ans=vector<int>(n+1);
        vector<pair<int,int>>pr;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            graph[x].pb(y);
            graph[y].pb(x);
            pr.pb({x,y});
        }
        int oddnode=-1,a=-1,b=-1,odd=0,odde=0;
        //odde = koyta node odd hoise
        //odd = koyta graph odd hoise

        for(int i=1;i<=n;i++){
            if(flag[i]) continue;
            
            nodes.clear();
            // arekflag=vector<int>(n+3);
            ret p=dfs(i);
            // cout<<i;
            // p.pr();
            /*
            p.nedges=0;
            for(int i=0;i<pr.size();i++){
                if(arekflag[pr[i].first]) p.nedges++;
            }
            */
            //number of edges
            // cout<<"ed: "<<p.nedges<<" oddnode: "<<p.odd<<endl;
            if(p.nedges>0 && p.nedges&1){
                odd++;
                for(int j=0;j<nodes.size();j++){
                    ans[nodes[j]]=1;
                    odde++;
                }
                //remove node with odd degree
                if(oddnode!=-1) continue;
                if(p.odd!=-1){
                    oddnode=p.odd;
                }
                //else a pair of connected nodes to remove
                //(maked removal of odd edges) and place 'em separately
                else{
                    oddnode=-2;
                    a=i;
                    b=graph[i][0]; 
                }
            }
        }
        int cnt=1;
        if(odde!=n) cnt++;

        if(odd&1){
            if(oddnode>-1) ans[oddnode]=0, cnt=2; //give it to even
            else ans[a]=0,ans[b]=2, cnt=3; //separate 'em
        }

        // cout<<oddnode<<" "<<a<<" "<<b<<" "<<odd<<" "<<odde<<endl;

        cout<<cnt<<endl;

        for(int i=1;i<=n;i++) {
            if(i>1) cout<<" ";
            cout<<ans[i]+1;
        }
        cout<<endl;
    }
    return 0;
}
/*
1
5 5
1 2 
2 3
3 4
4 5
1 5
*/