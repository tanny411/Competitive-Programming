#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int,int>
#define fs first
#define sc second
using namespace std;

int ccw(pii a,pii b,pii c)
{
    ///ab X ac
    return (b.fs-a.fs)*(c.sc-a.sc)-(b.sc-a.sc)*(c.fs-a.fs);
}

///probably works either way, first wrt to x coordinate or y coordinate
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

int main()
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
    cout<<"HUll :"<<endl;
    for(int i=0;i<hull.size();i++)
    {
        cout<<hull[i].fs<<" "<<hull[i].sc<<endl;
    }
    return 0;
}

