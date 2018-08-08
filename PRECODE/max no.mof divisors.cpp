#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

vector<int>prime;
void sieve(int n)
{
    prime.pb(2);
    vector<bool>flag(n+2);
    for(int i=3;i<=n;i+=2)
    {
        if(flag[i]==false) prime.pb(i);
        if(i<=sqrt(n) && flag[i]==false)
        {
            for(int j=i*i;j<=n;j+=(i+i)) flag[j]=true;
        }
    }
}
int main()
{
    ///maximum number of divisors from 1 to 100000
    int n=100000;
    sieve(n);
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int x=i;
        int ans=1;
        for(int j=0;prime[j]<=sqrt(x);j++)
        {
            if(x%prime[j]==0)
            {
                int cnt=1;
                while(x%prime[j]==0) cnt++,x/=prime[j];
                ans*=cnt;
            }
        }
        if(x>1) ans*=2;
        mx=max(mx,ans);
    }
    cout<<mx<<endl;
    return 0;
}

