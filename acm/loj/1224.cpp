#include<bits/stdc++.h>
using namespace std;
int tree[50001*50][4];
int val[50001*50];
map<char,int>mp; //={{'A',0},{'C',1},{'G',2},{'T',3}};
int main(){
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
    int t,n,cs=1;
    cin>>t;
    while(t--){
        cin>>n;
        string s;
        memset(tree, -1 , sizeof tree);
        memset(val, 0 , sizeof val);
        int node=0,mx=0;
        while(n--){
            int cur=0;
            cin>>s;
            //insert in trie
            for(int i=0;i<s.length();i++){
                if(tree[cur][mp[s[i]]]==-1){
                    tree[cur][mp[s[i]]]=++node;
                }
                cur=tree[cur][mp[s[i]]];
                val[cur]++;

                //dfs to the tree to and for each node:depth*val
                //here instant update is done, so no need to dfs later
                mx=max(mx,(i+1)*val[cur]);
            }
        }
        // for(int i=0;i<node;i++) cout<<val[node]<<" "; cout<<endl;
        cout<<"Case "<<cs++<<": "<<mx<<endl;
    }
    return 0;
}