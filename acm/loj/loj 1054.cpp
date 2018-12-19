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
#define Max 1<<30
#define mod 1000000007
#define ll long long
using namespace std;
#define lim 65540

int bal;
ll p[lim];
ll Mod(ll x)
{
    return (x+mod)%mod;
}

void sieve()
{
    bool ara[lim];
    memset(ara,0,sizeof(ara));
    ll k=1,i;
    p[0]=2;
    for(i=3;i<lim;i+=2){
        if(ara[i]==0){
                p[k++]=i;
                for(ll j=i*i;j<lim;j=j+i+i)
                    ara[j]=1;
        }
    }
    bal=k;
}


ll bigmod(ll base,ll power)
{
    if(power==0) return 1;
    ll x=bigmod(base,power/2);
    x=(x*x)%mod;
    if(power&1)
    {
        x = ( base*x) %mod;
    }
    return x;
}

ll invmod(ll base)
{
    return bigmod(base,mod-2);
}

int main()
{
    //freopen("out.txt","w",stdout);
    sieve();

    int t,T;
    ll n,m,a,c,SOD;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld",&n,&m);
        a=n;
        SOD=1;
        for(int i=0;i<bal && a>1;i++)
        {
            if(a%p[i]==0)
            {
                c=0;
                while(a%p[i]==0)
                {
                    a/=p[i];
                    c++;
                }
                SOD=(SOD*Mod((( bigmod(p[i],c*m+1)-1 )%mod * invmod(p[i]-1))%mod))%mod;
                //cout<<p[i]<<endl;
            }
        }
        if(a!=1)
        {
            SOD=(SOD*Mod(((bigmod(a,m+1)-1)%mod * invmod(a-1))%mod))%mod;
            //cout<<a<<" balled"<<endl;
        }
        printf("Case %d: %lld\n",t,SOD);
        //cout<<"t="<<bal<<endl;

    }
    return 0;
}

