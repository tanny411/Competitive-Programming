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
        ll n;
        cin>>n;
        ll ans=0;
        while(n)
        {
            ll sq=sqrt(1.0*n);
            sq=n/2 + (n%2==1) - sq/2 - (sq%2==1);
            ans+=sq;
            n/=2ll;
        }
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
