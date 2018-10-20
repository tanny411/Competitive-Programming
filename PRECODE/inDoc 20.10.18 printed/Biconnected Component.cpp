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

#define maxnode 1000+7
vector<int>gr[maxnode],disc(maxnode,-1),low(maxnode);
stack<pii>s;
int t=0;

void dfs_bcc(int p,int u)
{
    disc[u]=low[u]=++t;
    int child=0;

    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(v==p) continue;
        else if(disc[v]==-1)
        {
            s.push(pii(u,v));
            child++;
            dfs_bcc(u,v);
            low[u]=min(low[u],low[v]);
            if((p==-1 && child>1) || disc[u]<=low[v] )
            {
                ///u is a articulation point
                ///so all the edges we visited(tree/backedges) from here are in a BCC
                cout<<"BCC : \n";
                while(1)
                {
                    int x=s.top().fs;
                    int y=s.top().sc;
                    cout<<x<< " "<<y<<endl;
                    s.pop();
                    if(x==u && y==v) break;
                }
            }
        }
        else if(low[u]>disc[v]) ///edge in stack
        {
            s.push(pii(u,v));
            low[u]=min(low[u],disc[v]);
        }
    }
}

void BCC(int n)
{
    /*
    Do required clearing and init
    */
    for(int i=0;i<n;i++)
    {
        if(disc[i]==-1)
        {
            dfs_bcc(-1,i);
            if(!s.empty()) cout<<"BCC : "<<endl;
            while(!s.empty())
            {
                cout<<s.top().fs<<" "<<s.top().sc<<endl;
                s.pop();
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    BCC(n);
    return 0;
}

