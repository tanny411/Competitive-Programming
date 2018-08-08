#include<bits/stdc++.h>
#define pb push_back
#define Pb pop_back
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define fs first
#define sc second

///ios_base::sync_with_stdio(false);

using namespace std;

int n,fx=1<<30,fy=1<<30,in;///first points
vector<pii>p,Hull;

int cw_ccw(pii o,pii a,pii b)
{
    ///is OB cw or ccw wrt OA?
    ///OA x OB >0 ccw , <0 cw , =0 collinear
    int x=(a.fs-o.fs)*(b.sc-o.sc)-(b.fs-o.fs)*(a.sc-o.sc);
    return x;
}
ll dist(pii a,pii b)
{
    return (a.fs-b.fs)*(a.fs-b.fs)+(a.sc-b.sc)*(a.sc-b.sc);
}

bool comp (pii a, pii b)
{
    int x=cw_ccw(pii(fx,fy),a,b);
    if(x<0) return false;
    else if(x>0) return true;
    else if(dist(pii(fx,fy),a)>dist(pii(fx,fy),b)) return false;
    else return true;
}

void find_first_point()
{
    for(int i=0; i<n; i++)
    {
        if(p[i].sc<fy)
        {
            in=i;
            fy=p[i].sc;
            fx=p[i].fs;
        }
        else if(p[i].sc==fy && p[i].fs<fx)
        {
            in=i;
            fx=p[i].fs;
        }
    }
}

void MakeHull()
{
    find_first_point();
    p.erase(p.begin()+in);
    sort(p.begin(),p.end(),comp);
    p.insert(p.begin(),pii(fx,fy));
    for(int i=1; i<p.size()-1; i++)
    {
        if(cw_ccw(pii(fx,fy),p[i],p[i+1])==0)
        {
            p.erase(p.begin()+i);
            i--;
        }
    }
    if(p.size()<3) return;
    Hull.pb(p[0]);
    Hull.pb(p[1]);
    Hull.pb(p[2]);
    int hullsize=2;
    for(int i=3; i<p.size(); i++)
    {
        while(cw_ccw(Hull[hullsize-1],Hull[hullsize],p[i])<=0)
        {
            Hull.pop_back();
            hullsize--;
        }
        Hull.pb(p[i]);
        hullsize++;
    }
}

void prntHull()
{
    cout<<"Vertices of Convex Hull : "<<endl;
    for(int i=0; i<Hull.size(); i++)
    {
        cout<<Hull[i].fs<<" "<<Hull[i].sc<<endl;
    }
}

int main()
{

    return 0;
}

