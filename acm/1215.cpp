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

#define mx 1000004
using namespace std;
vector<int>prime,flag(mx);
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
    int n=prime.size();
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll a,b,L;
        cin>>a>>b>>L;
        ll l=a*b/__gcd(a,b);
        cout<<"Case "<<test++<<": ";
        if(L%l==0) {
            ll p=L/l;
            ll temp=p;
            for(int i=0;i<n && prime[i]*prime[i]<=temp;i++)
            {
                if(temp%prime[i]==0)
                {
                    while(l%prime[i]==0){
                        l/=prime[i];
                        p*=prime[i];
                    }
                    while(temp%prime[i]==0) temp/=prime[i];
                }
            }
            if(temp>1){
                while(l%temp==0){
                    l/=temp;
                    p*=temp;
                }
            }
            cout<<p<<endl;
        }
        else cout<<"impossible"<<endl;
    }
    return 0;
}

