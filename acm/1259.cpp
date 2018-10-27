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
#define nd 10000007
using namespace std;
bitset<nd>flag;
vector<int>prime;
void sieve()
{
    flag[0]=flag[1]=1;
    prime.pb(2);
    for(int i=4;i<nd;i+=2) flag[i]=1;
    for(int i=3;i<nd;i+=2)
    {
        if(flag[i]==0)
        {
            prime.pb(i);
            for(ll j=1ll*i*i;j<nd;j+=(i+i)) flag[j]=1;
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
        int n;
        cin>>n;
        int cnt=0;
        int mx=1<<30;
        for(int i=0;i<prime.size() && prime[i]<mx;i++) {
            if(n<prime[i]) break;
            if(flag[n-prime[i]]==0) cnt++,mx=n-prime[i];
        }
        cout<<"Case "<<test++<<": "<<cnt<<endl;
    }
    return 0;
}

