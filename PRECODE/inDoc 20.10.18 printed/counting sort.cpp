// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255

// The main function that sort the given string arr[] in
// alphabatical order
void countSort(char arr[])
{
    // The output character array that will have sorted arr
    char output[strlen(arr)];

    // Create a count array to store count of inidividul
    // characters and initialize count array as 0
    int cnt[RANGE + 1], i;
    memset(cnt, 0, sizeof(cnt));

    // Store count of each character
    for(i = 0; arr[i]; ++i)
        ++cnt[arr[i]];

    // Change cnt[i] so that cnt[i] now contains actual
    // position of this character in output array
    for (i = 1; i <= RANGE; ++i)///cummulative
        cnt[i] += cnt[i-1];

    // Build the output character array
    for (i = 0; arr[i]; ++i)
    {
        output[cnt[arr[i]]-1] = arr[i];
        --cnt[arr[i]];
    }

    // Copy the output array to arr, so that arr now
    // contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

// Driver program to test above function
int main()
{
    char arr[] = "geeksforgeeks";//"applepp";

    countSort(arr);

    printf("Sorted character array is %s\n", arr);
    return 0;
}
