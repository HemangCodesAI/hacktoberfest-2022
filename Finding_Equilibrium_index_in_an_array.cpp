// Problem Statement: Finding Equilibrium index in an array

// Given a 0-indexed integer array nums, find the leftmost equilibrium Index.

// An equilibrium Index is an index at which sum of elements on its left is equal to the sum of element on its right. That is, nums[0] + nums[1] + … + nums[equilibriumIndex-1] == nums[equilibriumIndex+1] + nums[equilibriumIndex+2] + … + nums[nums.length-1]. If equilibriumIndex == 0, the left side sum is considered to be 0. Similarly, if equilibriumIndex == nums.length – 1, the right side sum is considered to be 0.

// Return the leftmost equilibrium Index that satisfies the condition, or -1 if there is no such index.

// Examples:

// Example 1:
// Input: nums = [2,3,-1,8,4]
// Output: 3
// Explanation: The sum of the numbers before index 3 is: 2 + 3 + -1 = 4
// The sum of the numbers after index 3 is: 4 = 4

// Example 2:
// Input: nums = [1,-1,4]
// Output: 2
// Explanation: The sum of the numbers before index 2 is: 1 + -1 = 0
// The sum of the numbers after index 2 is: 0

#include <iostream>
using namespace std;
int findEquilibriumIdx(int nums[], int n) {
  int leftSum, rightSum;
 
  for (int i = 0; i < n; i++) {
    leftSum = 0;
    for (int j = 0; j < i; j++) {
      leftSum += nums[j];
    }
    rightSum = 0;
    for (int j = i + 1; j < n; j++) {
      rightSum += nums[j];
    }
    if (leftSum == rightSum) {
      return i;
    }
  }
  return -1;
}
int main() {
  int n = 5;
  int arr[] = { 2, 3, -1, 8, 4 };
  int equilibriumidx = findEquilibriumIdx(arr, n);
  cout << equilibriumidx << endl;
  return 0;
}
