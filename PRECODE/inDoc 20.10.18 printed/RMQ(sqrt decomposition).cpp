// C++ program to demonstrate working of Square Root
// Decomposition.
#include "iostream"
#include "math.h"
using namespace std;

#define MAXN 10000
#define SQRSIZE  100

int arr[MAXN];               // original array
int block[SQRSIZE];          // decomposed array
int blk_sz;                      // block size

// Time Complexity : O(1)
void update(int idx, int val)
{
    int blockNumber = idx / blk_sz;
    block[blockNumber] += val - arr[idx];
    arr[idx] = val;
}

// Time Complexity : O(sqrt(n))
int query(int l, int r)
{
    int sum = 0;
    while (l<r and l%blk_sz!=0 and l!=0)
    {
        // traversing first block in range
        sum += arr[l];
        l++;
    }
    while (l+blk_sz <= r)
    {
        // traversing completely overlapped blocks in range
        sum += block[l/blk_sz];
        l += blk_sz;
    }
    while (l<=r)
    {
        // traversing last block in range
        sum += arr[l];
        l++;
    }
    return sum;
    /**this way is little faster as has less number of division operations
    int sum = 0;
    int len=blk_siz;
    int c_l = l / len,   c_r = r / len;
    if (c_l == c_r)
    for (int i=l; i<=r; ++i)
        sum += a[i];
    else {
    for (int i=l, end=(c_l+1)*len; i<end; ++i)
        sum += a[i];
    for (int i=c_l+1; i<=c_r-1; ++i)
        sum += b[i];
    for (int i=c_r*len; i<=r; ++i)
        sum += a[i];
    }
    */
}

// Fills values in input[]
void preprocess(int input[], int n)
{
    // initiating block pointer
    int blk_idx = -1;

    // calculating size of block
    blk_sz = sqrt(n);

    // building the decomposed array
    for (int i=0; i<n; i++)
    {
        arr[i] = input[i];
        if (i%blk_sz == 0)
        {
            // entering next block
            // incementing block pointer
            blk_idx++;
        }
        block[blk_idx] += arr[i];
    }
}

// Driver code
int main()
{
    // We have used separate array for input because
    // the purpose of this code is to explain SQRT
    // decomposition in competitive programming where
    // we have multiple inputs.
    int input[] = {1, 5, 2, 4, 6, 1, 3, 5, 7, 10};
    int n = sizeof(input)/sizeof(input[0]);

    preprocess(input, n);

    cout << "query(3,8) : " << query(3, 8) << endl;
    cout << "query(1,6) : " << query(1, 6) << endl;
    update(8, 0);
    cout << "query(8,8) : " << query(8, 8) << endl;
    /**
    --inorder to do range update in this, keep a separate list, suppose c, just as block but initialized as 0;
    then when says add x to [i,j], to those blocks who completely fall in it, just c[that_block]+=ans; and
    partial blocks in the beginning and end will have to be manually updated;
    --when asks what is ara[i], put out ara[i]+c[i/blk_siz];
    **/
    return 0;
}
