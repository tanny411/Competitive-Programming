#include<iostream>
#include<vector>
#include<cstring>
#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007
#define ll long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
int n,l;
vector<int>v;
ll dp[55][55];
ll rec(int st,int en){

    if(dp[st][en]!=-1) return dp[st][en];
    if(st+1==en) return dp[st][en]=0;
    ll len=v[en]-v[st];
    ll ret=1<<30;;
    for(int i=st+1;i<en;i++){
        ret=min(ret,rec(st,i)+rec(i,en));
    }
    return dp[st][en]=ret+len;
}
int main()
{
    while(cin>>n && n){
        cin>>l;
        v.clear();
        v.pb(0);
        for(int i=0;i<l;i++){
            int x;
            cin>>x;
            v.pb(x);
        }
        v.pb(n);
        memset(dp,-1,sizeof dp);

        cout<<"The minimum cutting is "<<rec(0,v.size()-1)<<"."<<endl;

//        for(int i=0;i<v.size();i++){
//            for(int j=0;j<v.size();j++) cout<<dp[i][j]<<" ";
//            cout<<endl;
//        }
    }
    return 0;
}
