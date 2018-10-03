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

#define mx 1000004
int flag[mx];
int sign[mx];///mobius function
void sieve()
{
    for(int i=0;i<mx;i++) sign[i]=1;

    sign[2]=-1;
    for(int i=4;i<mx;i+=2) flag[i]=1,sign[i]=-1;
    for(int i=4;i<mx;i+=4) sign[i]=0;

    for(ll i=3;i<mx;i+=2)
    {
        if(!flag[i])
        {
            sign[i]=-1;
            for(ll j=i+i;j<mx;j+=i)
            {
                flag[j]=1;
                sign[j]*=-1;
            }
            ll k=i*i;
            for(ll j=k;j<mx;j+=k)
            {
                sign[j]=0;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    sieve();
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        if(n>m) swap(n,m);
        if(n==0)
        {
            cout<<"Case "<<test++<<": "<<(m!=0)<<endl;
            continue;
        }
        ll ans=2; ///horizontal and vertical rays
        for(ll i=1;i<=n;i++)
        {
            //cout<<sign[i]<<endl;
            ans+=sign[i]*(n/i)*(m/i);
        }
        cout<<"Case "<<test++<<": "<<ans<<endl;
    }
    return 0;
}
