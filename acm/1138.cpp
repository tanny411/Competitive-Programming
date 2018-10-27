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
int zero(ll n)
{
    int ret=0;
    for(ll i=5;;i*=5)
    {
        if(n/i > 0) ret+=n/i;
        else break;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int lo=1,hi=500000000;
        int ans=-1;
        while(lo<hi)
        {
            int m=(hi+lo)/2;
            //cout<<hi<<" "<<lo<<" "<<m<<endl;
            int x=zero(m);
            if(x>=n) hi=m;
            else lo=m+1;
            if(x==n) ans=m;
        }
        if(ans==-1) cout<<"Case "<<test++<<": impossible\n";
        else cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

