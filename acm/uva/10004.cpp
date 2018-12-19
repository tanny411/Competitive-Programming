#include<stdio.h>
#include<iostream>
#include<string.h>
#include<queue>

using namespace std;

queue<int>q;
vector<int>v[200];
int C[200],n;

int is_bipartite( int source,int color  )
{
    int i,top;
    C[source]=color;
    q.push(source);
    while(!q.empty())
    {
        top=q.front();
        q.pop();
        for(i=0;i<v[top].size();i++)
        {
            if(C[v[top][i]]==-1)///not given color also means not yet visited
            {
                C[v[top][i]]=1-C[top];
                q.push( v[top][i] );
            }
            else if(C[v[top][i]]==C[top]) return 0;
        }
    }
    return 1;
}
int main()
{
    int e,a,b,i;
    while( cin >> n  && n)
    {
        memset(C,-1,sizeof(C));

        cin >> e;

        while(e--)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(is_bipartite(0,0)) cout << "BICOLORABLE.\n";
        else cout << "NOT BICOLORABLE.\n";

        for(i=0;i<n;i++) v[i].clear();

    }
    return 0;
}
