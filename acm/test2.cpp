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

using namespace std;
pii extendedEuclid(ll a,ll b)
{
    if(b==0) return pii(1,0);
    else
    {
        pii d=extendedEuclid(b,a%b);
        return pii(d.sc,d.fs-d.sc*(a/b));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    pii p=extendedEuclid(10,8);
    cout<<p.fs<<" "<<p.sc<<endl;
     p=extendedEuclid(2,5);
    cout<<p.fs<<" "<<p.sc<<" "<<__gcd(2,5)<<endl;
     p=extendedEuclid(-2,5);
    cout<<p.fs<<" "<<p.sc<<" "<<__gcd(-2,5)<<endl;
     p=extendedEuclid(2,-5);
    cout<<p.fs<<" "<<p.sc<<" "<<__gcd(2,-5)<<endl;
     p=extendedEuclid(-2,-5);
    cout<<p.fs<<" "<<p.sc<<" "<<__gcd(-2,-5)<<endl;
    return 0;
}

