#include<bits/stdc++.h>
#define pii pair<int,int>
#define ppi pair<pii,int>
#define fs first
#define sc second
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int test=1;test<=t;test++){
        int n,m,p;
        cin>>n>>m>>p;
        vector<ppi>edge(m);
        vector<int>dist(n+2);
        ///keeping all 0 to detect ANY cycle in the graph, otherwise
        ///we will detect only the neg. cycle reachable from a specific source
        for(int i=0;i<m;i++){
            int I,E;
            cin>>edge[i].fs.fs>>edge[i].fs.sc>>I>>E;
            edge[i].sc=E*p-I;
        }
        int neg_cycle=0;
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                int cost=edge[i].sc;
                int u=edge[i].fs.fs;
                int v=edge[i].fs.sc;
                if(dist[v]>dist[u]+cost){
                    if(j==n-1) neg_cycle=1;
                    else dist[v]=dist[u]+cost;
                }
            }
        }
        cout<<"Case "<<test<<": "<<((!neg_cycle)?"NO":"YES")<<endl;
    }
    return 0;
}
