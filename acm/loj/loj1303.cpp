#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>wheel(m,-1), line(n), rode(n);
        for(int i=0;i<n;i++) line[i]=i;
        vector<vector<int> > people_flag(n, vector<int>(m,0));
        int cur_wheel = 0, cnt = 0, all_rode=0;
        while(all_rode<n){
            // cout<<".\n";
            if(cur_wheel==m) cur_wheel=0;
            if(wheel[cur_wheel]!=-1){
                int cur = wheel[cur_wheel];
                people_flag[cur][cur_wheel]=1;
                rode[cur]++;
                if(rode[cur]<m) line.push_back(cur);
                else all_rode++;
                wheel[cur_wheel]=-1;
            }
            for(int i=0;i<line.size();i++){
                if(!people_flag[line[i]][cur_wheel]){
                    wheel[cur_wheel]=line[i];
                    line.erase(line.begin()+i);
                    break;
                }
            }
            cur_wheel++;
            cnt++;
        }
        cout<<"Case "<<cas++<<": "<<cnt*5<<endl;
    }
    return 0;
}