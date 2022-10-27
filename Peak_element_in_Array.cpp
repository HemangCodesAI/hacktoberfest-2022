// Problem Statement: Given an array, find a peak element(print anyone, if many are found). A peak element is one such that it is either greater than or equal to its neighbours. For the first and last element, it is enough to look at its only one neighbour.

// Examples:

// Example 1:
// Input:
//  arr = {3, 5, 4, 1, 1}

// Output: Peak Element is 5
// Explanation:
//  3 and 4 are lesser than 5, therefore 5 is a peak element (1 is also a peak element).

// Example 2:
// Input: arr = {2,6,3,7,8,9}
// Output: Peak element is 6
// Explanation: 2 and 3 are lesser than 6, therefore 6 is a peak element (9 is also a peak element)

#include<iostream>

using namespace std;

int peakEleBruteForce(int arr[], int n) {
  if (arr[0] >= arr[1])
    return arr[0];

  for (int i = 1; i < n - 1; i++)
    if (arr[i] >= arr[i - 1] && arr[i] >= arr[i + 1])
      return arr[i];

  return arr[n - 1];
}

int main() {

  int arr[] = {3, 5, 4, 1, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  cout << "Peak Element is " << peakEleBruteForce(arr, n);

  return 0;
}
