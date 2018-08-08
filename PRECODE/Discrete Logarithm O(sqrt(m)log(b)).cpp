// C++ program to calculate discrete logarithm
#include<bits/stdc++.h>
using namespace std;

/* Iterative Function to calculate (x ^ y)%p in
   O(log y) */
int powmod(int x, int y, int p)
{
    int res = 1;  // Initialize result

    x = x % p;  // Update x if it is more than or
                // equal to p

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

// Function to calculate k for given a, b, m
int discreteLogarithm(int a, int b, int m) {

    int n = (int) sqrt (m) + 1;

    unordered_map<int, int> value;

    // Store all values of a^(n*i) of LHS
    for (int i = n; i >= 1; --i)
        value[ powmod (a, i * n, m) ] = i;

    for (int j = 0; j < n; ++j)
    {
        // Calculate (a ^ j) * b and check
        // for collision
        int cur = (powmod (a, j, m) * b) % m;

        // If collision occurs i.e., LHS = RHS
        if (value[cur])
        {
            int ans = value[cur] * n - j;
            // Check whether ans lies below m or not
            if (ans < m)
                return ans;
        }
    }
    return -1;
}

// Driver code
int main()
{
    int a = 2, b = 3, m = 5;
    cout << discreteLogarithm(a, b, m) << endl;

    a = 3, b = 7, m = 11;
    cout << discreteLogarithm(a, b, m);
}
