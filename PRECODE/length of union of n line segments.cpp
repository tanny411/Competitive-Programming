// C++ program to implement Klee's algorithm
#include<bits/stdc++.h>
using namespace std;

// Returns sum of lengths covered by union of given
// segments
int segmentUnionLength(const vector <pair <int,int> > &seg)
{
    int n = seg.size();

    // Create a vector to store starting and ending
    // points
    vector <pair <int, bool> > points(n * 2);
    for (int i = 0; i < n; i++)
    {
        points[i*2]     = make_pair(seg[i].first, false);
        points[i*2 + 1] = make_pair(seg[i].second, true);
    }

    // Sorting all points by point value
    sort(points.begin(), points.end());

    int result = 0; // Initialize result

    // To keep track of counts of current open segments
    // (Starting point is processed, but ending point
    // is not)
    int Counter = 0;

    // Trvaerse through all points
    for (unsigned i=0; i<n*2; i++)
    {
        // If there are open points, then we add the
        // difference between previous and current point.
        // This is interesting as we don't check whether
        // current point is opening or closing,
        if (Counter)
            result += (points[i].first - points[i-1].first);

        // If this is an ending point, reduce, count of
        // open points.
        (points[i].second)? Counter-- : Counter++;
    }
    return result;
}

// Driver program for the above code
int main()
{
    vector< pair <int,int> > segments;
    segments.push_back(make_pair(3, 15));
    segments.push_back(make_pair(2, 5));
    segments.push_back(make_pair(4, 8));
    segments.push_back(make_pair(9, 12));
    cout << "Length of Union of All segments = ";
    cout << segmentUnionLength(segments) << endl;
    return 0;
}
