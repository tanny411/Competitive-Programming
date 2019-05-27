#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define sc second
#define fs first
using namespace std;

int main(){
    int cas=1,t;

    cin>>t;
    while(t--)
    {
        int n,r,c,sr,sc;
        cin>>n>>r>>c>>sr>>sc;
        string s;
        cin>>s;
        map<pii,pair<pii,pii> >mp; //l,r,u,d
        mp[pii(sr,sc)]={{sc-1,sc+1},{sr-1,sr+1}};
        for(int i=0;i<n;i++){
            
            if(s[i]=='N'){
                if(mp.find(pii(sr-1,sc))==mp.end()) sr--;
                else sr=mp[pii(sr-1,sc)].sc.fs;
            }
            else if(s[i]=='S') {
                if(mp.find(pii(sr+1,sc))==mp.end()) sr++;
                else sr=mp[pii(sr+1,sc)].sc.sc;
            }
            else if(s[i]=='W') {
                if(mp.find(pii(sr,sc-1))==mp.end()) sc--;
                else sc=mp[pii(sr,sc-1)].fs.fs;
            }
            else {
                if(mp.find(pii(sr,sc+1))==mp.end()) sc++;
                else sc=mp[pii(sr,sc+1)].fs.sc;
            }
            
            pair<pii,pii>p;
                
            if(mp.find(pii(sr,sc-1))==mp.end()) p.fs.fs=sc-1;
            else p.fs.fs=mp[pii(sr,sc-1)].fs.fs;
            
            if(mp.find(pii(sr,sc+1))==mp.end()) p.fs.sc=sc+1;
            else p.fs.sc=mp[pii(sr,sc+1)].fs.sc;
            
            if(mp.find(pii(sr-1,sc))==mp.end()) p.sc.fs=sr-1;
            else p.sc.fs=mp[pii(sr-1,sc)].sc.fs;
            
            if(mp.find(pii(sr+1,sc))==mp.end()) p.sc.sc=sr+1;
            else p.sc.sc=mp[pii(sr+1,sc)].sc.sc;
            
            mp[pii(sr,sc)]=p;
            mp[pii(sr,p.fs.sc-1)].fs.fs=p.fs.fs;
            mp[pii(sr,p.fs.fs+1)].fs.sc=p.fs.sc;
            mp[pii(p.sc.fs+1,sc)].sc.sc=p.sc.sc;
            mp[pii(p.sc.sc-1,sc)].sc.fs=p.sc.fs;

            // cout<<sr<<" "<<sc<<endl;
        }
        cout<<"Case #"<<cas++<<": "<<sr<<" "<<sc<<endl;
    }

    return 0;
}