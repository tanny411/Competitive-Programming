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
    int in=1;
    while(in<n && p[in]==p[in-1]) in++;
    if(in==n) return hull;
    hull.pb(p[in++]);
    if(in==n) return hull;
    int hullsize=2;
    ///lower hull
    for(int i=in;i<n;i++)
    {
        if(p[i]==p[i-1]) continue;
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
        if(p[i]==p[i+1]) continue;
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
double angle(pii o,pii a,pii b) ///oa.ob
{
    a.fs-=o.fs;
    b.fs-=o.fs;
    a.sc-=o.sc;
    b.sc-=o.sc;
    double dot=a.fs*b.fs+a.sc*b.sc;
    double dis=a.fs*a.fs+a.sc*a.sc;
    dis=sqrt(dis);
    double dis1=b.fs*b.fs+b.sc*b.sc;
    dis*=sqrt(dis1);
    return acos(dot/dis);
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
        vector<pii>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i].fs>>p[i].sc;
        }
        vector<pii>hull;
        hull=monotone(p);
        int sz=hull.size();
        if(sz<3){
            cout<<"Case "<<test++<<": "<<0<<endl;
            continue;
        }
        double ans=1e20;
        for(int i=0;i<sz;i++)
        {
            int j=(i+1)%sz;
            int k=(j+1)%sz;
            ans=min(ans,angle(hull[j],hull[i],hull[k]));
        }
        ans=ans*180.0/acos(-1.0);
        cout<<"Case "<<test++<<": "<<fixed<<setprecision(10)<<ans<<endl;
    }
    return 0;
}


