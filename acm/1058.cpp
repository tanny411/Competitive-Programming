#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define LLU unsigned long long

#define fs first
#define sc second
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pii>v(n),mids;
        for(int i=0;i<n;i++) cin>>v[i].fs>>v[i].sc;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mids.pb(pii( v[i].fs+v[j].fs, v[i].sc+v[j].sc ));
            }
        }
        ll ans=0;
        sort(mids.begin(),mids.end());
        pii a=mids[0];
        ll x=1;
        for(int i=1;i<mids.size();i++){
            if(mids[i]==a) x++;
            else{
                ans+=(x*(x-1))/2;
                a=mids[i];
                x=1;
            }
        }
        ans+=(x*(x-1))/2;
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
