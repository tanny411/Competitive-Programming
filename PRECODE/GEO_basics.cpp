//#include<bits/stdc++.h>

#define pb push_back
#define Pb pop_back

#define sf1(x) scanf("%d", &x)
#define sf2(x,y) scanf("%d %d", &x, &y)
#define sf3(x,y,z) scanf("%d %d %d", &x, &y, &z)

#define pf1(x) printf("%d\n", x)

#define PI acos(-1.00)
#define pii pair<int,int>
#define ppi pair<pii,int>
#define INTMAX 1<<30
#define MOD 1000000007

#define ll long long
#define llu unsigned long long

#include<limits.h>
#include <cstdio>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <iterator>

#define clr( a, b )     memset((a),b,sizeof(a))
#define max3(a,b,c)     max(a,max(b,c))
#define min3(a,b,c)     min(a,min(b,c))


#define fs first
#define sc second

///ios_base::sync_with_stdio(false)

using namespace std;

struct point
{
    int x,y;///integer points
    ///double x,y; double points
    point() {}
    point (int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};

struct GEO
{
    double crossProduct(point o,point a,point b)
    {
        /// oa X ob = |oa||ob|sin(oa^ob)
        return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
    }
    double dotProduct(point o,point a,point b, int f=1)
    {
        /// oa.ob = |oa||ob|cos(oa^ob)
        if(f) return (a.x-o.x)*(b.x-o.x)+(a.y-o.y)*(b.y-o.y);
        ///if told to find ao.ob :
        ///ao=o-a; ob=b-o; (subtracting corresponding coordinates)
        ///then return sum of products
        else if(f==0) return (o.x-a.x)*(b.x-o.x)+(o.y-a.y)*(b.y-o.y);
    }
    double area_of_parallelogram(point o,point a,point b)
    {
        return abs(crossProduct(point o,point a,point b));
    }
    double area_of_triangle(point o,point a,point b)
    {
        return area_of_parallelogram(point o,point a,point b)*1.0/2;
        ///returned double
    }
    double dist(point a,point b)
    {
        return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
    }
    double perpDist(point d,point a,point b)
    {
        ///perpendicular distance from the point d, to the line cointaing the points a and b
        return area_of_parallelogram(point a,point d,point b)/dist(point a,point b);
        ///because 1/2*base*height=1/2*area of parallelogram
        ///so, height=area/base;
    }
    double nearestDistToSegement(point d,point a,point b)
    {
        ///nearest distance from point d to line segment ab
        if(dotProduct(point b,point a,point d, 0)>0)
        {
            ///if ab.bd>0 that means d is beyond the point b. so the
            ///nearest point of the segment to the point d is b
            return dist(point b, point d);
        }
        else if(dotProduct(point a,point b,point d, 0)>0)
        {
            ///if ba.ad>0 d is beyond a
            return dist(point d,point a);
        }
        else
        {
            ///d's perpendicular lies on the segment, so thats the shortest distance
            perpDist(point d,point a,point b);
        }
    }
};

struct PolygonArea
{

};

int main()
{
    return 0;
}

