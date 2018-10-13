#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long

#define fs first
#define sc second

using namespace std;
ll crossProduct(pll a,pll b)///oa X ob
{
    return a.fs*b.sc-a.sc*b.fs;
}
ll polyArea(vector<pll>&p,int n)///atleast 3 points
{
    ll area=0;
    for(int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        area+=crossProduct(p[i],p[j]);
    }
    return abs(area)/2.0;
}
ll Points(vector<pll>&p,int n)
{
    ll ret=0;
    for(int i=0;i<n;i++)
    {
        int j=(i+1)%n;
        ret+=__gcd( abs(p[i].fs-p[j].fs) , abs(p[i].sc-p[j].sc) );
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pll>p(n);
        for(int i=0;i<n;i++) cin>>p[i].fs>>p[i].sc;
        ll A=polyArea(p,n);
        ll B=Points(p,n);
        ll I=A+1-B/2;
        //cout<<"Area = "<<A<<"  B = "<<B<<endl;
        cout<<"Case "<<test++<<": "<<I<<endl;
    }
    return 0;
}

