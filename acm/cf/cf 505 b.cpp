#include<bits/stdc++.h>
#define pb push_back
#define sc second
#define fs first
using namespace std;
#define mx 50000
///TLE
int flag[mx+3];
vector<int>prime;
void sieve()
{
    prime.pb(2);
    for(int i=4;i<=mx;i+=2) flag[i]=1;
    for(int i=3;i<=mx;i+=2){
        if(flag[i]==0){
            //cout<<i<<endl;
            prime.pb(i);
            if(1ll*i*i>50000ll) continue;
            for( int j=i*i;j<=mx;j+=(i+i)){
                flag[j]=1;
            }
        }
    }
    return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    //cout<<"aysha"<<endl;
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    vector<pair<int,int> >v(n);
    for(int i=0;i<n;i++){
        cin>>v[i].fs>>v[i].sc;
    }
    for(int i=0;i<prime.size();i++){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(v[j].fs%prime[i]==0 || v[j].sc%prime[i]==0) cnt++;
            while(v[j].fs%prime[i]==0) v[j].fs/=prime[i];
            while(v[j].sc%prime[i]==0) v[j].sc/=prime[i];
        }
        if(cnt==n){
            cout<<prime[i]<<endl;
            return 0;
        }
    }
    for(int j=0;j<n;j++){
        if(v[j].fs!=1) mp[v[j].fs]++;
        if(v[j].sc!=1 && v[j].fs!=v[j].sc) mp[v[j].sc]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        if(i->sc==n)
        {
            cout<<(i->fs)<<endl;
            return 0;
        }
    }
    cout<<"-1"<<endl;
    return 0;
}
