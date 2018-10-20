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
    point operator+(const point& a)
    {
        return point(x+a.x,y+a.y);
    }
    point operator-(const point& a)
    {
        return point(x-a.x,y-a.y);
    }
    int operator*(const point& a)///dot product
    {
        return x*a.x+y*a.y;
    }
    int operator^(const point& a)///cross product
    {
        return x*a.y-y*a.x;
    }
};
struct line{
    int a,b,c;///ax+by=c;
    line() {}
    line(int x,int y,int z)
    {
        a=x;
        b=y;
        c=z;
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
        return abs(crossProduct(o,a,b));
    }
    double area_of_triangle(point o,point a,point b)
    {
        return area_of_parallelogram(o,a,b)*1.0/2;
        ///returned double
    }
    double dist(point a,point b)
    {
        return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
    }
    double perpDist(point d,point a,point b)
    {
        ///perpendicular distance from the point d, to the line cointaing the points a and b
        return area_of_parallelogram(a,d,b)/dist(a,b);
        ///because 1/2*base*height=1/2*area of parallelogram
        ///so, height=area/base;
    }
    double nearestDistToSegement(point d,point a,point b)
    {
        ///nearest distance from point d to line segment ab
        if(dotProduct(b, a, d, 0)>0)
        {
            ///if ab.bd>0 that means d is beyond the point b. so the
            ///nearest point of the segment to the point d is b
            return dist( b,  d);
        }
        else if(dotProduct( a, b, d, 0)>0)
        {
            ///if ba.ad>0 d is beyond a
            return dist( d, a);
        }
        else
        {
            ///d's perpendicular lies on the segment, so thats the shortest distance
            perpDist( d, a, b);
        }
    }
    int IntegerPointsOnPolygonBoundary(vector<point>&p)
    {
        int ret=0;
        int n=p.size();
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            ret+=__gcd( abs(p[i].x-p[j].x) , abs(p[i].y-p[j].y) );
        }
        return ret;
    }
    double polyArea(vector<point>&p)///atleast 3 points
    {
        int n=p.size();
        double area=0.0;
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            area+=crossProduct(point(0,0),p[i],p[j]);
        }
        return fabs(area)/2.0;
    }
    line lineFromPoints(point a,point b){///ax+by=c from two points
        int A=b.y-a.y;
        int B=a.x-b.x;
        return line(A,B,A*a.x+B*a.y);
    }
    point lineLineIntersection(line line1,line line2)
    {
        ///for two lines, NOT line segments
        double det = line1.a*line2.b - line2.a*line1.b,x,y;
        if(det == 0){
            //Lines are parallel
        }else{
            x = (line2.b*line1.c - line1.b*line2.c)/det;
            y = (line1.a*line2.c - line2.a*line1.c)/det;
        }
        return point(x,y);
        //Line segment intersection, do the above thing, and then check the point
        //by "isPointOnLineSegment" function
        // You must be careful about double precision issues though.
        //If your point is right on the edge of the segment, or if the segment is
        //horizontal or vertical, a simple comparison might be problematic.
        //In these cases, you can either do your comparisons with some tolerance,
        // or else use a fraction class.
    }
    bool isPointOnLineSegment(point startLine,point endLine, point x)
    {
        ///considering the point is already on the LINE
        return (x.x>=min(startLine.x,endLine.x) && x.x<=max(startLine.x,endLine.x)
            && x.y>=min(startLine.y,endLine.y) && x.y<=max(startLine.y,endLine.y));
    }
    line perpendicular(line X,point x)
    {
        //returns a line perpendicular to the given line through x
        int D=-X.b*x.x+X.a*x.y;
        return line(-X.b,X.a,D);
    }
    point midPoint(point A,point B)
    {
        return point((A.x+B.x)/2.0,(A.y+B.y)/2.0);
        //doesnt make sense to use it in 'int' (change accordingly)
    }
    pair<point,int> circleFromPoints(point X,point Y,point Z)
    {
        ///Points must be non-collinear
        //These points uniquely define a circle.
        //Returns Center and radius of the circle
        //We want to find the perpendicular bisectors of XY and YZ,
        //and then find the intersection of those two bisectors.
        //This gives us the center of the circle.
        line perpXY=perpendicular(lineFromPoints(X,Y),midPoint(X,Y));
        line perpYZ=perpendicular(lineFromPoints(Y,Z),midPoint(Y,Z));
        point center=lineLineIntersection(perpXY,perpYZ);
        int radius=dist(center,X);
        return pair<point,int>(center,radius);
    }
    point reflect(line l,point x)
    {
        //reflect x against a line l
        //1.xx' and l are perpendicular, and at equal distance
        line perp=perpendicular(l,x);
        point y=lineLineIntersection(l,perp);
        point xPrime=y-(x-y);
        return xPrime;
        //another way to find the reflected point is to rotate the original point 180 degrees about line l.
    }
    point Rotate(point a,double angle)
    {
        //angle must be in radians
        //counter clock-wise rotation about the origin
        ///if rotating about y, do x-y and after rotation do x+y
        double x=a.x*cos(angle)-a.y*sin(angle);
        double y=a.x*sin(angle)+a.y*cos(angle);
        return point(x,y);
    }
};

int main()
{
    return 0;
}

