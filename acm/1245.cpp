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
        ll ans=n,i,a,b=n;
        for(i=1;(i+1)<=b;i++)
        {
            a=n/i;
            b=n/(i+1);
            ans+=(a-b)*i;
            if(b>i) ans+=b;
        }
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

