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
#define mx 10000006

using namespace std;

/**
a+(a+1)+(a+2)+....+(a+k-1) //k length er series
sum => {k*(2a-1+k)}/2=n
=> 2a-1=2n/k - k
=> lhs is a odd number
=> 2(n/k) is always even
=> rhs : if k is even divisor of n, even - even = even ; but lhs is odd
=> if k is odd, even - odd = odd
=> so ans=number of odd divisors of n
*/


vector<int>prime;
bitset<mx>flag;

void sieve()
{
    prime.pb(2);
    for(int i=3;i<mx;i+=2)
    {
        if(flag[i]==0)
        {
            prime.pb(i);
            for(ll j=1ll*i*i;j<mx;j+=(i+i)) flag[j]=1;
        }
    }
}

int main()
{
    sieve();
    int sz=prime.size();
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        while(n%2==0) n>>=1;
        ll ans=1;
        for(int i=0;i<sz && prime[i]*prime[i]<=n ;i++)
        {
            int cnt=1;
            while(n%prime[i]==0) n/=prime[i],cnt++;
            ans*=cnt;
        }
        if(n>1) ans*=2ll;
        cout<<"Case "<<test++<<": "<<ans-1<<endl;
    }
    return 0;
}
