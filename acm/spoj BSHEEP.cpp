#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define ppi pair<pii,int>
#define fs first
#define sc second
using namespace std;

int ccw(pii a,pii b,pii c)
{
    ///ab X ac
    return (b.fs-a.fs)*(c.sc-a.sc)-(b.sc-a.sc)*(c.fs-a.fs);
}

///probably works either way, first wrt to x coordinate or y coordinate(wiki)
bool cmp(ppi a,ppi b)
{
    if(a.fs.sc==b.fs.sc) return a.fs.fs<b.fs.fs;
    else return a.fs.sc<b.fs.sc;
}

int monotone (vector<ppi>&p, vector<ppi>&hull)
{
    int n=p.size();
    sort(p.begin(),p.end(),cmp);
    hull.pb(p[0]);
    int in=1;
    while(in<n && p[in].fs==p[in-1].fs) in++;
    if(in==n) return 1;
    hull.pb(p[in++]);
    if(in==n) return 2;
    int hullsize=2;
    ///lower hull
    for(int i=in;i<n;i++)
    {
        if(p[i].fs==p[i-1].fs) continue;
        while(hullsize>=2 && ccw(hull[hullsize-2].fs,hull[hullsize-1].fs,p[i].fs)<=0)
        {
            hull.pop_back();
            hullsize--;
        }
        hull.pb(p[i]);
        hullsize++;
    }
    int t=hullsize;
    ///upper hull
    for(int i=n-2;i>=0;i--)
    {
        if(p[i].fs==p[i+1].fs) continue;
        ///at least 2 points in upper hull
        while(hullsize>t && ccw(hull[hullsize-2].fs,hull[hullsize-1].fs,p[i].fs)<=0)
        {
            hull.pop_back();
            hullsize--;
        }
        hull.pb(p[i]);
        hullsize++;
    }
    hull.pop_back();
    hullsize--;
    return hullsize;
}
double dist(pii a,pii b)
{
    double ans=(a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc);
    ans=sqrt(ans);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<ppi>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i].fs.fs>>p[i].fs.sc;
            p[i].sc=i+1;
        }
        vector<ppi>hull;
        int siz=monotone(p,hull);
        double dis=0.0;
        for(int i=0;i<siz;i++)
        {
            if(i==0) dis+=dist(hull[0].fs,hull[siz-1].fs);
            else dis+=dist(hull[i].fs,hull[i-1].fs);
        }
        cout<<fixed<<setprecision(2)<<dis<<endl;
        for(int i=0;i<siz;i++){
            if(i) cout<<" ";
            cout<<hull[i].sc;
        }
        cout<<endl;
    }
    return 0;
}

