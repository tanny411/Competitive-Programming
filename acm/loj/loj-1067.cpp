#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define pb push_back
#define Pb pop_back
#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)
#define pf1(x) printf("%d\n", x)
#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000003
#define ll long long
#define llu unsigned long long
using namespace std;

ll ara[1000001];


ll inv(ll base,ll power)
{
    if(power==0) return 1;
    ll x=inv(base,power/2);
    x=(x*x)%MOD;
    if(power&1) x=(base*x)%MOD;
    return x;
}


int main()
{
    ara[0]=1;
    for(int i=1;i<1000001;i++)
    {
        ara[i]=(ara[i-1]*i)%MOD;
    }
    ll t,n,r,cas=1;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        ll x= (ara[n]*inv(ara[r],MOD-2)*inv(ara[n-r],MOD-2))%MOD;
        //int x= (ara[n]/(ara[r])/(ara[n-r]) );
        printf("Case %lld: %lld\n",cas++,x);
    }
    return 0;
}
