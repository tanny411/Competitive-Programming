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
    ll n;
    cin>>n;
    ll prime=n;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            prime=i;
            break;
        }
    }
    if(prime==2)
    {
        cout<<n/2<<endl;
    }
    else{
        n-=prime;
        cout<<1+n/2<<endl;
    }
    return 0;
}

