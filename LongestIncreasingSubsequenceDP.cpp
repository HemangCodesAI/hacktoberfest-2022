// Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.

// Input Format
// The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.

// Output Format
// The first and only line of output contains the length of longest subsequence.

// Input :
// 6
// 5 4 11 1 16 8

// Output :
// 3

// Output Explanation
// Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

#include <iostream>
using namespace std;

int longestIncreasingSubsequence(int* input, int n) {
    if(n == 0 || n == 1)
    {
        return n;
    }
    int *output = new int[n];
    output[0] = 1;
    
    for(int i=1; i<n; i++)
    {
        output[i] = 1;
         for(int j=i - 1; j>=0; j--)
        {
            if(input[i] > input[j] && output[i] < output[j] + 1)
            {
                output[i] = output[j] + 1;
            }
        }
    }
    int best = 0;
    for(int i=0; i<n; i++)
    {
        best = max(best, output[i]);
    }
    return best;
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << longestIncreasingSubsequence(arr, n);
}