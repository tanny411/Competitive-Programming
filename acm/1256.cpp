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
struct edge{
    int v,id,flag;
    edge(){}
    edge(int a,int b,int c){
        v=a;
        id=b;
        flag=c;
    }
};
vector<edge>gr[30];
vector<int>path;

void dfs(int u,int ed){
    for(int i=0;i<gr[u].size();i++)
    {
        if(gr[u][i].flag==0){
            gr[u][i].flag=1;
            dfs(gr[u][i].v,gr[u][i].id);
        }
    }
    if(ed!=-1) path.pb(ed);
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
        for(int i=0;i<26;i++) gr[i].clear();
        path.clear();
        vector<int>indegree(30),outdegree(30);
        vector<string>str(m);
        int st=0;
        for(int i=0;i<m;i++){
            string s;
            cin>>s;
            str[i]=s;
            int u=s[0]-'a';
            int v=s[s.length()-1]-'a';
            st=u;
            gr[u].push_back( edge(v,i,0) );
            outdegree[u]++;
            indegree[v]++;
        }

       int cnt1=0,cnt2=0,hobena=0,en=-1;
        for(int i=0;i<26 && hobena==0;i++){
            if(indegree[i]-outdegree[i]==1) cnt1++,en=i;
            else if(-indegree[i]+outdegree[i]==1) cnt2++,st=i;
            else if(indegree[i]!=outdegree[i]) hobena=1;
        }
        //cout<<cnt1<<" "<<cnt2<<" "<<hobena<<endl;
        //cout<<"start"<<st<<endl;
        if( (cnt1==1 && cnt2==1 && hobena==0) || (cnt1==0 && cnt2==0 && hobena==0) )
        {
            //cout<<"aislo\n";
            if((cnt1==1 && cnt2==1 && hobena==0)) gr[en].pb(edge(st,10000,0)),m++;
            dfs(st,-1);
            if(path.size()==m){
                cout<<"Case "<<test<<": Yes\n";
                int f=0;
                if((cnt1==1 && cnt2==1 && hobena==0))
                {
                    int i;
                    for(i=0;i<path.size();i++){
                        if(path[i]==10000) break;
                    }
                    int brk=i;
                    for(i=brk-1;i>=0;i--){
                        if(f) cout<<" ";
                        f=1;
                        cout<<str[path[i]];
                    }
                    for(i=path.size()-1;i>brk;i--){
                        if(f) cout<<" ";
                        f=1;
                        cout<<str[path[i]];
                    }
                }
                else
                {
                    for(int i=path.size()-1;i>=0;i--){
                        if(f) cout<<" ";
                        f=1;
                        cout<<str[path[i]];
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
5
ab bc cd db da
*/
