#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

int main()
{
    int nodenumber,n,route[1003],vis[1003],top,i,j,flag=0;
    string a,b,trace[1003],prn[1003];
    vector<int>v[1003];
    queue<int>q;
    map<string,int>node;
    while(scanf("%d",&n)==1)
    {
        if(flag) cout << endl;
        flag=1;
        node.clear();
        memset(vis,-1,sizeof(vis));
        nodenumber=1;
        while(n--)
        {
            cin >> a >> b;
            if(node[a]==0) { trace[nodenumber]=a;  node[a]=nodenumber++; }
            if(node[b]==0) { trace[nodenumber]=b;  node[b]=nodenumber++; }
            v[node[a]].push_back(node[b]);
            v[node[b]].push_back(node[a]);
        }
        cin >> a >> b;
        if(node[a]==0) { trace[nodenumber]=a;  node[a]=nodenumber++; }
        if(node[b]==0) { trace[nodenumber]=b;  node[b]=nodenumber++; }
        q.push(node[a]);
        vis[node[a]]=1;
        while(vis[node[b]]==-1 && !q.empty())
        {
            top=q.front();
            q.pop();
            for(i=0;i<v[top].size();i++)
            {
                if(vis[v[top][i]]==-1)
                {
                    vis[v[top][i]]=1;
                    q.push(v[top][i]);
                    route[v[top][i]]=top;
                }
            }
        }
        while(!q.empty()) q.pop();
        for(i=0;i<nodenumber;i++) v[i].clear();
        if(vis[node[b]]==-1)
        {
            cout << "No route" <<endl;
        }
        else{
        j=0;
        i=node[b];
        while(trace[i]!=a)
        {
            prn[j++]=trace[i];
            i=route[i];
        }
        prn[j++]=trace[node[a]];
        for(i=j-1;i>0;i--)
        {
            cout<<prn[i]<<" "<<prn[i-1]<<endl;
        }
        }
    }
    return 0;
}
