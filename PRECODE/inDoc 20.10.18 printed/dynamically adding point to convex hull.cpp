// C++ program to add given a point p to a given
// convext hull. The program assumes that the
// point of given convext hull are in anti-clockwise
// order.
#include<bits/stdc++.h>
using namespace std;

// checks whether the point crosses the convex hull
// or not
int orientation(pair<int, int> a, pair<int, int> b,
                pair<int, int> c)
{
    int res = (b.second-a.second)*(c.first-b.first) -
              (c.second-b.second)*(b.first-a.first);

    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

// Returns the square of distance between two input points
int sqDist(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first-p2.first)*(p1.first-p2.first) +
           (p1.second-p2.second)*(p1.second-p2.second);
}

// Checks whether the point is inside the convex hull or not
bool inside(vector<pair<int, int>> a, pair<int, int> p)
{
    // Initialize the centroid of the convex hull
    pair<int, int> mid = {0, 0};

    int n = a.size();

    // Multiplying with n to avoid floating point
    // arithmetic.
    p.first *= n;
    p.second *= n;
    for (int i=0; i<n; i++)
    {
        mid.first += a[i].first;
        mid.second += a[i].second;
        a[i].first *= n;
        a[i].second *= n;
    }

    // if the mid and the given point lies always
    // on the same side w.r.t every edge of the
    // convex hull, then the point lies inside
    // the convex hull
    for (int i=0, j; i<n; i++)
    {
        j = (i+1)%n;
        int x1 = a[i].first, x2 = a[j].first,
        int y1 = a[i].second, y2 = a[j].second;
        int a1 = y1-y2;
        int b1 = x2-x1;
        int c1 = x1*y2-y1*x2;
        int for_mid = a1*mid.first+b1*mid.second+c1;
        int for_p = a1*p.first+b1*p.second+c1;
        if (for_mid*for_p < 0)
            return false;
    }

    return true;
}

// Adds a point p to given convex hull a[]
void addPoint(vector<pair<int, int>> &a, pair<int, int> p)
{
    // If point is inside p
    if (inside(a, p))
        return;

    // point having minimum distance from the point p
    int ind = 0;
    int n = a.size();
    for (int i=1; i<n; i++)
        if (sqDist(p, a[i]) < sqDist(p, a[ind]))
            ind = i;

    // Find the upper tangent
    int up = ind;
    while (orientation(p, a[up], a[(up+1)%n])>=0)
        up = (up + 1) % n;

    // Find the lower tangent
    int low = ind;
    while (orientation(p, a[low], a[(n+low-1)%n])<=0)
        low = (n+low - 1) % n;

    // Initialize result
    vector<pair<int, int>>ret;

    // making the final hull by traversing points
    // from up to low of given convex hull.
    int curr = up;
    ret.push_back(a[curr]);
    while (curr != low)
    {
        curr = (curr+1)%n;
        ret.push_back(a[curr]);
    }

    // Modify the original vector
    ret.push_back(p);
    a.clear();
    for (int i=0; i<ret.size(); i++)
        a.push_back(ret[i]);
}

// Driver code
int main()
{
    // the set of points in the convex hull in anticlockwise direction
    vector<pair<int, int> > a;
    a.push_back({0, 0});
    a.push_back({3, -1});
    a.push_back({4, 5});
    a.push_back({-1, 4});
    int n = a.size();

    pair<int, int> p = {100, 100};
    addPoint(a, p);

    // Print the modified Convex Hull
    for (auto e : a)
        cout << "(" << e.first << ", "
              << e.second << ") ";

    return 0;
}
