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

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    int t,test=1;
    cin>>t;
    while(t--){
        int n,m,k,p;
        cin>>n>>m>>k;
        vector<int>ara[n+1][2+1];///0 is positive/1 index is negative
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                char ch;
                int x;
                cin>>ch>>x;
                if(ch=='+') ara[i][0].pb(x);
                else ara[i][1].pb(x);
            }
        }
        cin>>p;
        vector<int>v(p);
        for(int i=0;i<p;i++) cin>>v[i];
        int cnt=1;
        for(int i=0;i<n;i++){
            int f=0;
            for(int j=0;j<ara[i][0].size();j++){
                if(binary_search(v.begin(),v.end(),ara[i][0][j])){
                    f=1;
                    break;
                }
            }
            if(f) continue;
            for(int j=0;j<ara[i][1].size();j++){
                if(!binary_search(v.begin(),v.end(),ara[i][1][j])){
                    f=1;
                    break;
                }
            }
            if(!f) {cnt=0; break;}
        }
        cout<<"Case "<<test++<<": "<<(cnt==1?"Yes":"No")<<endl;
    }
    return 0;
}
