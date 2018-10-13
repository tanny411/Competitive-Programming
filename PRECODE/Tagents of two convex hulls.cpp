/**
For finding the upper tangent, we start by taking two points. The rightmost point of a and leftmost point of b. The line joining them is labelled as 1.
As this line passes through the polygon b (is not above polygon b) so we take the anti-clockwise next point on b, the line is labelled 2. Now the line
is above the polygon b, fine! But the line is crossing the polygon a, so we move to the clockwise next point, labelled as 3 in the picture. This again
crossing the polygon a so we move to line 4. This line is crossing b so we move to line 5. Now this line is crossing neither of the points. So this is
the upper tangent for the given polygons.
For finding the lower tangent we need to move inversely through the polygons i.e. if the line is crossing the polygon b we move to clockwise next and
to anti-clockwise next if the line is crossing the polygon a.

Only upper tangent shown in code, lower tangent can be found similarly(both present in dovex hull divide and conquer another way code)
*/
// C++ program to find upper tangent of two polygons.
#include<bits/stdc++.h>
using namespace std;

// stores the center of polygon (It is made
// global becuase it is used in compare function)
pair<int,int> mid;

// determines the quadrant of a point
// (used in compare())
int quad(pair<int,int> p)
{
    if (p.first >= 0 && p.second >= 0)
        return 1;
    if (p.first <= 0 && p.second >= 0)
        return 2;
    if (p.first <= 0 && p.second <= 0)
        return 3;
    return 4;
}

// Checks whether the line is crossing the polygon
int orientation(pair<int,int> a, pair<int,int> b,
                                 pair<int,int> c)
{
    int res = (b.second-a.second)*(c.first-b.first) -
              (c.second-b.second)*(b.first-a.first);

    if (res == 0)
        return 0;
    if (res > 0)
        return 1;
    return -1;
}

// compare function for sorting
bool compare(pair<int,int> p1, pair<int,int> q1)
{
    pair<int,int> p = make_pair(p1.first - mid.first,
                                p1.second - mid.second);
    pair<int,int> q = make_pair(q1.first - mid.first,
                                q1.second - mid.second);

    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p.second*q.first < q.second*p.first);
}

// Finds upper tangent of two polygons 'a' and 'b'
// represented as two vectors.
void findUpperTangent(vector<pair<int,int> > a,
                      vector<pair<int,int> > b)
{
    // n1 -> number of points in polygon a
    // n2 -> number of points in polygon b
    int n1 = a.size(), n2 = b.size();

    // To find a point inside the convex polygon(centroid),
    // we sum up all the coordinates and then divide  by
    // n(number of points). But this would be a floating-point
    // value. So to get rid of this we multiply points
    // initially with n1 and then find the centre and
    // then divided it by n1 again.
    // Similarly we do divide and multiply for n2 (i.e.,
    // elements of b)

    // maxa and minb are used to check if polygon a
    // is left of b.
    int maxa = INT_MIN;
    for (int i=0; i<n1; i++)
    {
        maxa = max(maxa, a[i].first);
        mid.first  += a[i].first;
        mid.second += a[i].second;
        a[i].first *= n1;
        a[i].second *= n1;
    }

    // sorting the points in counter clockwise order
    // for polygon a
    sort(a.begin(), a.end(), compare);

    for (int i=0; i<n1; i++)
    {
        a[i].first /= n1;
        a[i].second /= n1;
    }

    mid = {0, 0};

    int minb = INT_MAX;
    for (int i=0; i<n2; i++)
    {
        mid.first += b[i].first;
        mid.second += b[i].second;
        minb = min(minb, b[i].first);
        b[i].first *= n2;
        b[i].second *= n2;
    }

    // sorting the points in counter clockwise
    // order for polygon b
    sort(b.begin(), b.end(), compare);

    for (int i=0; i<n2; i++)
    {
        b[i].first/=n2;
        b[i].second/=n2;
    }

    // If a is to the right of b, swap a and b
    // This makes sure a is left of b.
    if (minb < maxa)
    {
        a.swap(b);
        n1 = a.size();
        n2 = b.size();
    }

    // ia -> rightmost point of a
    int ia = 0, ib = 0;
    for (int i=1; i<n1; i++)
        if (a[i].first > a[ia].first)
            ia = i;

    // ib -> leftmost point of b
    for (int i=1; i<n2; i++)
        if (b[i].first < b[ib].first)
            ib=i;

    // finding the upper tangent
    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(b[indb], a[inda], a[(inda+1)%n1]) > 0)
            inda = (inda + 1) % n1;

        while (orientation(a[inda], b[indb], b[(n2+indb-1)%n2]) < 0)
        {
            indb = (n2+indb-1)%n2;
            done = 0;
        }
    }

    cout << "upper tangent (" << a[inda].first << ","
        << a[inda].second << ") (" << b[indb].first
        << "," << b[indb].second << ")\n";
}

// Driver code
int main()
{
    vector<pair<int,int> > a;
    a.push_back({2, 2});
    a.push_back({3, 1});
    a.push_back({3, 3});
    a.push_back({5, 2});
    a.push_back({4, 0});

    vector<pair<int,int> > b;
    b.push_back({0, 1});
    b.push_back({1, 0});
    b.push_back({0, -2});
    b.push_back({-1, 0});

    findUpperTangent(a, b);

    return 0;
}
