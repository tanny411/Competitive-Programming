#include <bits/stdc++.h>
using namespace std;
#define INF 30000
struct Point {
    int x;
    int y;
};

bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

int doIntersect(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return 2;
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    return false; // Doesn't fall in any of the above cases
}

// Returns true if the point p lies inside the polygon[] with n vertices
bool isInside(Point polygon[], int n, Point p) {
    if (n < 3)  return false;
    // Create a point for line segment from p to infinite
    Point extreme;
    extreme.x = p.x + INF; extreme.y = p.y; //+ INF+1
    // Count intersections of the above line with sides of polygon
    int count = 0, i = 0;
    do {
        int next = (i+1)%n;
        if (int a = doIntersect(polygon[i], polygon[next], p, extreme)) {
           if (a == 2) return 1;
            if (orientation(polygon[i], p, polygon[next]) == 0)
               return onSegment(polygon[i], p, polygon[next]);
            count++;
        }
        i = next;
    } while (i != 0);

    // Return true if count is odd, false otherwise
    return count&1;  // Same as (count%2 == 1)
}
int main()
{
   int tc, cs = 0, n, q;
   //freopen ("in.txt", "r", stdin);
   cin >> tc;
   while (tc--) {
      cin >> n;
      Point polygon1[n];
      for (int i = 0; i < n; i++)
         cin >> polygon1[i].x >> polygon1[i].y;
      cin >> q;
      printf ("Case %d:\n", ++cs);
      while (q--) {
         Point pp;
         cin >> pp.x >> pp.y;
         isInside(polygon1, n, pp) ? cout << "Yes\n" : cout << "No\n";
      }
   }
    return 0;
}
