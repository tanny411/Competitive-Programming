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

///ios_base::sync_with_stdio(false);

using namespace std;
/**
8 9
ans:202 (194 hor and ver)
**/
int main()
{
    int t,test=1;
    cin>>t;
    while(t--){
        ll h,w;
        cin>>h>>w;
        ll ans=0;
        for(ll i=1;i<=500;i++){
            int F=0;
            for(ll j=i;j<=500;j++){
                int f=0;

                ll th=j+j;
                ll tw=i+i+j+j;

                ll temp=0;

                if(th<=h && tw<=w) temp+=(h+1-th)*(w+1-tw),f=1,F=1;

                swap(th,tw);
                if(th<=h && tw<=w) temp+=(h+1-th)*(w+1-tw),f=1,F=1;

                if(i!=j) temp*=2ll;

                ans+=temp;

                if(f==0) break;
            }
            if(F==0) break;
        }
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
