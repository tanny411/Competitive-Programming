#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define pii pair<int,int>
#define ppi pair<pii,int>

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);
///loj 1099
using namespace std;
vector<pair<int,int> >gr[5002];
int d[2][5002];
int flag[2][5002];

void dijkstra(int s)
{
    priority_queue<pair<int,pair<int,int> > ,vector< pair<int,pair<int,int> > > ,greater< pair<int,pair<int,int> > > >q; ///dis,t=0(shortest),1(second shortest),u
    d[0][s]=0;
    q.push({0,{0,s}});
    while(!q.empty())
    {
        int t=q.top().sc.fs;
        int u=q.top().sc.sc;
        q.pop();
        if(flag[t][u]) continue;
        flag[t][u]=1;
        for(int i=0;i<gr[u].size();i++)
        {
            int v=gr[u][i].fs;
            int dd=gr[u][i].sc;
            if(d[0][v]>d[t][u]+dd)
            {
                d[1][v]=d[0][v];
                d[0][v]=d[t][u]+dd;
                q.push({d[1][v],{1,v}});
                q.push({d[0][v],{0,v}});
            }
            else if(d[0][v]<d[t][u]+dd && d[1][v]>d[t][u]+dd)///need to give d[0][v]<d[t][u]+dd becasue the second shortest cant be equal to shortest,if can be equal dont give this
            {
                d[1][v]=d[t][u]+dd;
                q.push({d[1][v],{1,v}});
            }
        }
    }
}

int main()
{
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        int n,r;
        cin>>n>>r;
        for(int i=0;i<=n;i++)
        {
            gr[i].clear();
            d[0][i]=d[1][i]=1<<30;
            flag[0][i]=flag[1][i]=0;
        }
        while(r--)
        {
            int x,y,w;
            cin>>x>>y>>w;
            gr[x].pb({y,w});
            gr[y].pb({x,w});
        }
        dijkstra(1);
        cout<<"Case "<<cas++<<": "<<d[1][n]<<endl;
    }
    return 0;
}

