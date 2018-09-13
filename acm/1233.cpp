#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL long long
#define LLU unsigned long long

#define fs first
#define sc second

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>coin(n),limit(n),nisi,hoise(m+1);
        for(int i=0;i<n;i++) cin>>coin[i];
        for(int i=0;i<n;i++) cin>>limit[i];
        hoise[0]=1;///kisu na nile '0' to hoisei
        for(int i=0;i<n;i++){///for each coin
            nisi=vector<int>(m+1,0);
            for(int j=coin[i];j<=m;j++){
                if(hoise[j]==0 && hoise[j-coin[i]] && nisi[j-coin[i]]<limit[i]){
                    hoise[j]=1;
                    nisi[j]=nisi[j-coin[i]]+1;
                    //cout<<j<<" banaite "<<i<<"-th coin "<<nisi[j]<<" bar lagse"<<endl;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++) ans+=hoise[i];
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
