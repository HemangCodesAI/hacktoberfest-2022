// Problem Statement: Given a string consisting of alphabetic characters. Print the length of the longest substring containing distinct elements.

// Examples:

// Example 1:
// Input: s = "wewr"
// Output:
//  Length of the longest substring : 3
// Explanation: The longest substring is “ewr” (length : 3).

// Example 2:
// Input: s = "abcd"
// Output: Length of the longest substring : 4
// Explanation: The longest substring is “abcd” (length : 4).

#include<bits/stdc++.h>

using namespace std;

int longestSubstrWithoutDupliBF(string s, int n) {

  int start = 0, end = -1, maxLen = 0;
  for (int i = 0; i < n; i++) {
    int j = start;
    for (; j <= end && s[j] != s[i]; j++);

    if (j <= end)
      start = j + 1;

    end++;
    maxLen = max(maxLen, end - start + 1);
  }
  return maxLen;
}

int main() {

  string s = "wewr";
  int n = s.length();

  cout << "Length of the longest substring : " << longestSubstrWithoutDupliBF(s, n);

  return 0;
}
