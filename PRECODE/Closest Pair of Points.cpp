#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>

#define ll long long
#define llu unsigned long long

#define fs first
#define sc second

///ios_base::sync_with_stdio(false)

using namespace std;

struct ClosestPairOfPoint
{
    ///points taken as double
    ///considered all distances ans the square of distances within double
    double inf=numeric_limits<double>::max();
    vector< pair<double,double> > pointsx,pointsy;
    ClosestPairOfPoint() {}
    void addpoint(double x,double y)
    {
        pointsx.push_back({x,y});;
    }
    void Clr()
    {
        pointsx.clear();
        pointsy.clear();
    }
    double dist(pair<double,double>a, pair<double,double>b)
    {
        double d=(a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
        return sqrt(d);
    }
    static bool compx(pair<double,double>a , pair<double,double>b)
    {
        return a.first<b.first;
    }
    static bool compy(pair<double,double>a , pair<double,double>b)
    {
        return a.second<b.second;
    }
    double bruteforce(int b,int e)
    {
        double mn=inf;
        for(int i=b;i<=e;i++)
        {
            for(int j=i+1;j<=e;j++)
            {
                mn=min(mn,dist(pointsx[i],pointsx[j]));
            }
        }
        return mn;
    }
    double stripClosest(vector<pair<double,double> >strip , double d)
    {
        for(int i=0;i<strip.size();i++)
        {
            for(int j=i+1;j<strip.size() && strip[j].second-strip[i].second<=d ; j++)
            {
                d=min(d,dist(strip[i],strip[j]));
            }
        }
        return d;
    }
    double ClosestPoint( int b,int e, vector< pair<double,double> >& py )
    {
        if(e-b+1<=3) return bruteforce(b,e);
        int mid=(b+e)/2;
        int midx=pointsx[mid].first;
        vector< pair<double,double> >yl,yr;
        for(int i=0;i<py.size();i++)
        {
            if(py[i].first<=midx) yl.push_back(py[i]);
            else yr.push_back(py[i]);
        }
        double dl=ClosestPoint(b,mid,yl);
        double dr=ClosestPoint(mid+1,e,yr);
        double d=min(dl,dr);
        vector< pair<double,double> > strip;
        for(int i=0;i<py.size();i++)
        {
            if(abs(midx-py[i].first)<=d) strip.push_back(py[i]);
        }
        d=min(d,stripClosest(strip,d));
        return d;
    }
    double run()
    {
        pointsy=pointsx;
        sort(pointsx.begin(),pointsx.end(),compx);
        sort(pointsy.begin(),pointsy.end(),compy);
        int n=pointsx.size()-1;
        return ClosestPoint(0, n, pointsy );
    }
};

int main()
{

    return 0;
}

