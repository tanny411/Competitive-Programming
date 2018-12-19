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
#define MOD 1000000007
#define ll long long
#define llu unsigned long long
using namespace std;
#define mx 2000002
llu inv(llu base,llu power)
{
    if(power==0) return 1;
    llu x=inv(base,power/2);
    x=(x*x)%MOD;
    if(power&1) x=(base*x)%MOD;
    return x;
}
llu ara[mx];
int main()
{
    int cas=1;
    ara[0]=1;
    for(int i=1;i<mx;i++)
    {
        ara[i]=(ara[i-1]*i)%MOD;
    }
    llu t,n,r;
    cin>>t;
    while(t--)
    {
        cin>>n>>r;
        llu ans;
        llu ans2=(ara[r-1]*ara[n])%MOD;
        ans2=inv(ans2,MOD-2)%MOD;
        ans=(ara[n+r-1]*ans2)%MOD;
        printf("Case %d: %llu\n",cas++,ans);
    }
    return 0;
}
