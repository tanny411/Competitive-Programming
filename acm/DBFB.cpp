#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define md 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

int main()
{
    int t;
    cin>>t;
    ll ara[100006];
    ara[1]=0;
    ara[2]=1;
    for(int i=3;i<=100000;i++) ara[i]=(ara[i-1]+ara[i-2])%md;
    while(t--)
    {
        int n,m;
        cin>>m>>n;
        vector<ll>a(m),b(m);
        ll suma=0,sumb=0,ans=0;
        for(int i=0;i<m;i++) cin>>a[i],suma=(suma+a[i])%md;
        for(int i=0;i<m;i++) cin>>b[i],sumb=(sumb+b[i])%md;
        if(n==1) ans=(suma*m)%md;
        else if(n==2) ans=(sumb*m)%md;
        else
        {
            ans=(((suma*ara[n-1])%md + (sumb*ara[n])%md )*m)%md;
        }
        cout<<ans<<endl;
    }
    return 0;
}
