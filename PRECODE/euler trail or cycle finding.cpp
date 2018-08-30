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
#define mxnode 26

using namespace std;
struct edge{
    int v,flag;
    edge(){}
    edge(int a,int c){
        v=a;
        flag=c;
    }
};
vector<edge>gr[mxnode];
vector<int>path;

void dfs(int u){
    for(int i=0;i<gr[u].size();i++)
    {
        if(gr[u][i].flag==0){
            gr[u][i].flag=1;
            dfs(gr[u][i].v);
        }
    }
    path.pb(u);
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int test=1;test<=t;test++)
    {
        int m;
        cin>>m;
        for(int i=0;i<mxnode;i++) gr[i].clear();
        path.clear();
        vector<int>indegree(mxnode),outdegree(mxnode);
        int st=0;
        for(int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            st=u;
            gr[u].push_back( edge(v,0) );
            outdegree[u]++;
            indegree[v]++;
        }

       int cnt1=0,cnt2=0,hobena=0,en=-1;
        for(int i=0;i<26 && hobena==0;i++){
            if(indegree[i]-outdegree[i]==1) cnt1++,en=i;
            else if(-indegree[i]+outdegree[i]==1) cnt2++,st=i;
            else if(indegree[i]!=outdegree[i]) hobena=1;
        }
        //cout<<st<<" "<<en<<endl;
        if( (cnt1==1 && cnt2==1 && hobena==0) || (cnt1==0 && cnt2==0 && hobena==0) )
        {
            //cout<<"Dhuke\n";
            if((cnt1==1 && cnt2==1 && hobena==0)) gr[en].pb(edge(st,0)),m++;
            dfs(st);
            if(1){///fix this part
                cout<<"Case "<<test<<": Yes\n";
                int f=0;
                if((cnt1==1 && cnt2==1 && hobena==0))
                {
                    int i;
                    for(i=0;i<path.size()-1;i++){
                        if(path[i]==st && path[i+1]==en) break;
                    }
                    int brk=i+1;
                    for(i=brk-1;i>=0;i--){
                        if(f) cout<<" ";
                        f=1;
                        cout<<path[i];
                    }
                    for(i=path.size()-1;i>brk;i--){
                        if(f) cout<<" ";
                        f=1;
                        cout<<path[i];
                    }
                }
                else
                {
                    for(int i=path.size()-1;i>=0;i--){
                        if(f) cout<<" ";
                        f=1;
                        cout<<path[i];
                    }
                }
                cout<<"\n";
            }
            else{
                cout<<"Case "<<test<<": No\n";
            }
        }
        else cout<<"Case "<<test<<": No\n";
    }
    return 0;
}

/**
1

5
1 2
2 3
3 4
4 2
4 1
ans euler path
*/
