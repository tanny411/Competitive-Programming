#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll phi(int n)
{
    ll ret=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0) n/=i;
            ret-=ret/i;
        }
    }
    if(n>1) ret-=ret/n;
    return ret;
}

ll bigmod(ll base,ll power, ll m)
{
    if(power==0) return 1ll;
    if(power==1) return base;
    ll x=bigmod(base,power/2,m);
    x=(x*x)%m;
    if(power&1) x=(x*base)%m;
    return x;
}

ll hugemod(string a,string b,int m)
{
    int la=a.length();
    int lb=b.length();
    //reduce b by 1;
    for(int i=lb-1;i>=0;i--)
    {
        if(b[i]-'0'>=1) {b[i]=b[i]-1;break;}
        else b[i]='9';
    }
    //cout<<b<<endl;
    ll A=0;
    for(int i=0;i<la;i++)
    {
        A=(A*10+a[i]-'0')%m;
    }

    ll x=1;
    for(int i=0;i<lb;i++)
    {
        x=bigmod(x,10,m);
        x=(x*bigmod(A,b[i]-'0',m))%m;
    }
    x=( (A-1)*x )%m;
    return (x+m)%m;
}

int main()
{
    string a,b;
    ll c;
    cin>>a>>b>>c;
    //reduce b by 1;
    ll ans=hugemod(a,b,c);
    cout<< ( ans!=0 ? ans:c ) <<endl;
    return 0;
}

