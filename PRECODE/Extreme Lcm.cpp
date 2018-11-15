#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll unsigned long long
#define LLU unsigned long long

#define fs first
#define sc second

#define mx 3000010

using namespace std;
/*
//need to solve
unsigned long long allPairLcm( int n ) {
    unsigned long long res = 0;
    for( int i = 1; i <= n; i++ )
        for( int j = i + 1; j <= n; j++ )
            res += lcm(i, j); // lcm means least common multiple
    return res;
}
*/
vector<int>phi(mx);
vector<ll>divs(mx);

void sieve()
{
    for(int i=1;i<mx;i+=2) phi[i]=i;
    for(int i=2;i<mx;i+=2) phi[i]=i/2;
    for(ll i=3;i<mx;i+=2)
    {
        if(phi[i]==i) {
            for(ll j=i;j<mx;j+=i) phi[j]=(phi[j]/i)*(i-1);
        }
    }
}
void cumm()
{
    for(int i=1;i<mx;i++)
    {
        divs[i]=(divs[i]-1)/2*i;
        divs[i]+=divs[i-1];
    }
}
void divisor()
{
    for(int i=1;i<mx;i++) divs[i]=1;
    for(int i=2;i<mx;i++)
    {
        for(int j=i;j<mx;j+=i)
        {
            divs[j]+=1ll*phi[i]*i;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);

    sieve();
    divisor();
    cumm();

    int t,test=1;
    scanf("%d",&t);
    while(t--)
    {
        ll n;
        scanf("%llu",&n);
        printf("Case %d: %llu\n",test++,divs[n]);
    }
    return 0;
}
