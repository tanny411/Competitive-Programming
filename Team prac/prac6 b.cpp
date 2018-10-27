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

int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        ll a,b,c;
        ll d,e,f;
        ll l,r;
        cin>>a>>b>>c>>d>>e>>f>>l>>r;

        a=abs(a-d);///6
        b=abs(b-e);///4
        c=abs(c-f);///2

        a*=r*r*r-l*l*l;
        b*=r*r-l*l;
        c*=r-l;

        ll deno=12;

        a*=2;
        b*=3;
        c*=6;

        a=(a+b+c);
        a*=2;

        ll g=__gcd(abs(a),abs(deno));

        a/=g;
        deno/=g;

        cout<<a<<"/"<<deno<<endl;
    }
    return 0;
}

