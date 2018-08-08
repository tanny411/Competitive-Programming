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

int main()
{
    int cas=1;
    int t;
    cin>>t;
    while(t--)
    {
        ll k,c,n,a;
        cin>>k>>c>>n>>a;
        vector<ll>v(n),cum(n);
        v[0]=a;
        for(int i=1;i<n;i++)
        {
            v[i]=(v[i-1]*k + c)%1000007;
        }
        sort(v.begin(),v.end());
        cum[0]=v[0];
        for(int i=1;i<n;i++)
        {
            cum[i]=v[i]+cum[i-1];
        }
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=cum[n-1]-cum[i]-v[i]*(n-1-i);
        }
        cout<<"Case "<<cas++<<": "<<ans<<endl;
    }
    return 0;
}

