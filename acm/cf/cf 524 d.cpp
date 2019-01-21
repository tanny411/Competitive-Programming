#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define LL unsigned long long

#define fs first
#define sc second

using namespace std;

LL bg(LL base,LL n)
{
    if(n==1) return base;
    if(n==0) return 1LL;
    LL x=bg(base,n/2);
    x=x*x;
    if(n&1) x*=base;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        LL n,k;
        cin>>n>>k;
        if(k==1)
        {
            cout<<"YES "<<n-1<<endl;
            continue;
        }
        LL splits=1+(bg(4,n-1)-1)/3,in=1;
        int i=n-2;
        for(i=n-2;i>=0 && splits<k;i--)
        {
            splits+=in+2;
            if(splits>k){
                splits=0;
                break;
            }
            in=(in-1)*2 + 5;
            splits+=((bg(4,i)-1)/3)*in;
        }
        if(splits>=k) cout<<"YES "<<i+1<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}

