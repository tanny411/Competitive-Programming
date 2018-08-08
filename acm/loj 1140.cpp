#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;
ll dig[20],nozero[20];

ll fun(ll n)
{
    int dg=1;
    ll r=n;
    ll ans=1,last;
    int num;
    ll baad=r%10;
    r/=10;
    ll dg10=1;
    if(!r) return ans;
    while(r)
    {
        num=r%10;
        if(num==0) last=baad+1;
        else last=num*dig[dg]+nozero[dg]-nozero[dg-1];
        ans+=last;
        r/=10;
        dg++;
        dg10*=10;
        baad=num*dg10+baad;
    }
    ans-=last;
    ans+=num*dig[dg-1]-nozero[dg-2];
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    ll num=10;
    dig[1]=1;
    nozero[1]=10;
    for(int i=2;i<11;i++)
    {
        dig[i]=i*num;
        num*=10;
        nozero[i]=nozero[i-1]+num;
    }
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        cout<<"Case "<<cas++<<": ";
        if(a==0) cout<<fun(b)<<endl;
        else cout<<fun(b)-fun(a-1)<<endl;
    }
    return 0;
}

