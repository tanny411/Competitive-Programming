#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>gr[n+2],flag(n+3);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
        //cout<<i<<"  ";
    }
    priority_queue<int,vector<int>,greater<int> >p;
    p.push(1);
    flag[1]=1;
    while(!p.empty()){
        int x=p.top();
        p.pop();
        cout<<x<<" ";
        for(int i=0;i<gr[x].size();i++){
            if(flag[gr[x][i]]==0) p.push(gr[x][i]),flag[gr[x][i]]=1;
        }
    }
    return 0;
}