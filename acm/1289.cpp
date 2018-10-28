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

#define mx 100000003
#define szz 5761460
int prime[szz];
ll flag[mx/64 + 10];
int cnt=0;
void sieve()
{
    ll i,j,k;
    for(i=3;i<mx;i+=2)
         if(!(flag[i/64]&(1LL<<(i%64))))
                for(j=i*i;j<mx;j+=(i+i))
                    flag[j/64]|=(1LL<<(j%64));

    prime[cnt++]=2;
    for (int i = 3; i<mx; i+=2)
        if(!(flag[i/64]&(1LL<<(i%64))))
            prime[cnt++]=i;
}
unsigned int prod[szz];
int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    prod[0]=2;
    for(int i=1;i<cnt;i++)
    {
        prod[i]=prime[i]*prod[i-1];
    }
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        unsigned int ans=1;
        for(int i=0;i<cnt && prime[i]*prime[i]<=n;i++)
        {
            unsigned int ret=1,x=n/prime[i];//reducing one power;
            while(x>=prime[i]) ret*=prime[i],x/=prime[i]; //finding maximum power of prime[i] in n
            ans*=ret;
        }
        int in=upper_bound(prime,prime+cnt,n)-prime-1;
        ans*=prod[in];
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}

