#include<bits/stdc++.h>
#define pb push_back
#define pii pair<ll,ll>
#define ll long long
#define fs first
#define sc second
using namespace std;

ll ccw(pii a,pii b,pii c)
{
    ///ab X ac
    return (b.fs-a.fs)*(c.sc-a.sc)-(b.sc-a.sc)*(c.fs-a.fs);
}

///probably works either way, first wrt to x coordinate or y coordinate(wiki)
bool cmp(pii a,pii b)
{
    if(a.sc==b.sc) return a.fs<b.fs;
    else return a.sc<b.sc;
}

vector<pii> monotone (vector<pii>p)
{
    int n=p.size();
    vector<pii>hull;
    if(n<3) return hull;
    sort(p.begin(),p.end(),cmp);
    hull.pb(p[0]);
    hull.pb(p[1]);
    int hullsize=2;
    ///lower hull
    for(int i=2;i<n;i++)
    {
        while(hullsize>=2 && ccw(hull[hullsize-2],hull[hullsize-1],p[i])<=0)
        {
            hull.pop_back();
            hullsize--;
        }
        hull.pb(p[i]);
        hullsize++;
    }
    int t=hullsize;
    ///upper hull
    for(int i=n-2;i>-1;i--)
    {
        ///at least 2 points in upper hull
        while(hullsize>t && ccw(hull[hullsize-2],hull[hullsize-1],p[i])<=0)
        {
            hull.pop_back();
            hullsize--;
        }
        hull.pb(p[i]);
        hullsize++;
    }
    hull.pop_back();
    hullsize--;
    return hull;
}
double dist(pii a,pii b)
{
    double x=1.0*a.fs-1.0*b.fs;
    double y=1.0*a.sc-1.0*b.sc;
    return sqrt(x*x+y*y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,test=1;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;
        vector<pii>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i].fs>>p[i].sc;
        }
        double ans=2.0*acos(-1.0)*(1.0*d);;
        if(n<3){
            if(n==2) ans+=2.0*dist(p[0],p[1]);
            cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<ans<<endl;
            continue;
        }
        vector<pii>hull;
        hull=monotone(p);
        int sz=hull.size();
        for(int i=0;i<sz;i++)
        {
            if(i){
                ans+=dist(hull[i],hull[i-1]);
            }
            else{
                ans+=dist(hull[0],hull[sz-1]);
            }
        }
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }


    return 0;
}


