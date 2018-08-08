// C++ program to calculate discrete logarithm
#include<bits/stdc++.h>
using namespace std;

int discreteLogarithm(int a, int b, int m)
{
    int n = (int) sqrt (m) + 1;

    // Calculate a ^ n
    int an = 1;
    for (int i = 0; i<n; ++i)
        an = (an * a) % m;

    unordered_map<int, int> value;

    // Store all values of a^(n*i) of LHS
    for (int i = 1, cur = an; i<= n; ++i)
    {
        if (! value[ cur ])
            value[ cur ] = i;
        cur = (cur * an) % m;
    }

    for (int i = 0, cur = b; i<= n; ++i)
    {
        // Calculate (a ^ j) * b and check
        // for collision
        if (value[cur])
        {
            int ans = value[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}

// Driver code
int main()
{
    int a = 10, b = 2, m = 19;
    cout << discreteLogarithm(a, b, m) << endl;

    a = 3, b = 7, m = 11;
    cout << discreteLogarithm(a, b, m);
}
