If n > m there will always be a subset with sum divisible by m (which is easy to prove with pigeonhole principle). So we need to handle only cases of n <= m .

For n <= m we create a boolean DP table which will store the status of each value from 0 to m-1 which are possible subset sum (modulo m) which have been encountered so far.

Now we loop through each element of given array arr[], and we add (modulo m) j which have DP[j] = true and store all the such (j+arr[i])%m possible subset sum in a boolean array temp, and at the end of iteration over j, we update DP table with temp. Also we add arr[i] to DP ie.. DP[arr[i]%m] = true.

In the end if DP[0] is true then it means YES there exist a subset with sum which is divisible by m, else NO.

// C++ program to check if there is a subset
// with sum divisible by m.
#include <bits/stdc++.h>
using namespace std;

// Returns true if there is a subset
// of arr[] with sum divisible by m
bool modularSum(int arr[], int n, int m)
{
    if (n > m)
        return true;

    // This array will keep track of all
    // the possible sum (after modulo m)
    // which can be made using subsets of arr[]
    // initialising boolean array with all false
    bool DP[m];
    memset(DP, false, m);

    // we'll loop through all the elements of arr[]
    for (int i=0; i<n; i++)
    {
        // anytime we encounter a sum divisible
        // by m, we are done
        if (DP[0])
            return true;

        // To store all the new encountered sum (after
        // modulo). It is used to make sure that arr[i]
        // is added only to those entries for which DP[j]
        // was true before current iteration.
        bool temp[m];
        memset(temp,false,m);

        // For each element of arr[], we loop through
        // all elements of DP table from 1 to m and
        // we add current element i. e., arr[i] to
        // all those elements which are true in DP
        // table
        for (int j=0; j<m; j++)
        {
            // if an element is true in DP table
            if (DP[j] == true)
            {
                if (DP[(j+arr[i]) % m] == false)

                    // We update it in temp and update
                    // to DP once loop of j is over
                    temp[(j+arr[i]) % m] = true;
            }
        }

        // Updating all the elements of temp
        // to DP table since iteration over
        // j is over
        for (int j=0; j<m; j++)
            if (temp[j])
                DP[j] = true;


        // Also since arr[i] is a single element
        // subset, arr[i]%m is one of the possible
        // sum
        DP[arr[i]%m] = true;
    }

    return DP[0];
}

// Driver code
int main()
{
    int arr[] = {1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m = 5;

    modularSum(arr, n, m) ?  cout << "YESn" :
                             cout << "NOn";

    return 0;
}
