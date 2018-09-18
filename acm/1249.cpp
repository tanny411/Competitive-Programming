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

int main(){
    int t,test=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector< pair<int,string> >v(n);
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>v[i].sc>>x>>y>>z;
            v[i].fs=x*y*z;
        }
        sort(v.begin(),v.end());
        cout<<"Case "<<test++<<": ";
        if(v[0].fs==v[n-1].fs) cout<<"no thief\n";
        else cout<<v[n-1].sc<<" took chocolate from "<<v[0].sc<<endl;
    }
    return 0;
}
