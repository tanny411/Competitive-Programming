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

///probably works either way, first wrt to x coordinate or y coordinate(wiki)
bool cmp(pii a,pii b)
{
    if(a.sc==b.sc) return a.fs<b.fs;
    else return a.sc<b.sc;
}

int monotone (vector<pii>p)
{
    int n=p.size();
    if(n==0) return 0;
    if(n<3) return INT_MIN;
    vector<int>hull,ase(n);
    vector<pii>ret;///will have indices
    hull.pb(0);
    hull.pb(1);
    int hullsize=2;
    ///lower hull
    for(int i=2;i<n;i++)
    {
        while(hullsize>=2 && ccw(p[hull[hullsize-2]],p[hull[hullsize-1]],p[i])<0)
        {
            hull.pop_back();
            hullsize--;
        }
        hull.pb(i);
        hullsize++;
    }
    int t=hullsize;
    ///upper hull
    for(int i=n-2;i>-1;i--)
    {
        ///at least 2 points in upper hull
        while(hullsize>t && ccw(p[hull[hullsize-2]],p[hull[hullsize-1]],p[i])<0)
        {
            hull.pop_back();
            hullsize--;
        }
        hull.pb(i);
        hullsize++;
    }
    hull.pop_back();
    hullsize--;
    for(int i=0;i<hullsize;i++)
    {
        ase[hull[i]]=1;
    }

    for(int i=0;i<n;i++)
    {
        if(!ase[i]) ret.pb(p[i]);
    }
    //cout<<"Size of Hull "<<hullsize<<endl;
    return 1+monotone(ret);
}

int main()
{
    int n;
    while(cin>>n && n)
    {
        vector<pii>p(n);
        for(int i=0;i<n;i++)
        {
            cin>>p[i].fs>>p[i].sc;
        }
        sort(p.begin(),p.end(),cmp);
        int rings=monotone(p);
        //cout<<"# of hulls "<<rings<<endl;
        if(rings<0) rings=0;
        if(rings&1) cout<<"Take this onion to the lab!"<<endl;
        else cout<<"Do not take this onion to the lab!"<<endl;
    }
    return 0;
}
/**
7
0 0
0 8
1 6
3 1
6 6
8 0
8 8

11
2 6
3 2
6 6
0 0
0 11
1 1
1 9
7 1
7 9
8 10
8 0

0
*/
