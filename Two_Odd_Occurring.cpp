// Problem Statement: Find the two numbers which occur an odd number of times in the given unsorted array.

// Examples:

// Example 1:
// Input: N = 8, array[] = {5 , 5 , 2 , 8 , 1 , 8, 1 , 1}
// Output: 2 , 1
// Explanation: The two numbers 2 and 1 only occur an odd number of times. Rest of the number occurs even number of times.

// Example 2:
// Input: N = 5, array[] = {10 , 7 , 6 , 6 , 6 , 6, 7 , 4}
// Output: 4 , 10
// Explanation: The two numbers 10 and 4 only occur an odd number of times. Rest of the number occurs even number of times.

#include "bits/stdc++.h"

using namespace std;
vector < int > two_odd(int nums[], int n) {
  unordered_map < int, int > mp;
  for (int i = 0; i < n; ++i) {
    ++mp[nums[i]];
  }
  cout << "Two numbers with odd occurrences are: ";
  vector < int > ans;
  for (auto & x: mp) {
    if (x.second % 2 == 1) {
      ans.push_back(x.first);
    }
  }
  return ans;
}
int main() {
  int nums[] = {5,5,2,8,1,8,1,1};

  int n = sizeof(nums) / sizeof(nums[0]);
  vector < int > ans = two_odd(nums, n);
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i] << ", ";
  }
  return 0;
}
