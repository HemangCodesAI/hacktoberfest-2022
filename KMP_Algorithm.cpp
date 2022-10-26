// Problem Statement: Implement the Knuth-Morris-Pratt KMP string matching algorithm.

// Examples:

// Example 1:
// Input: String = ”aaaaaaaamaaaaaab”  and Pattern = “aaaaaab”
// Output: 9
// Explanation: The underlined string is the pattern string 
// successfully matched. The first index where the pattern has 
// matched is 9. So result is 9.

// Example 2:
// Input: String = ”Manav” and pattern=”nav”
// Output: 2
// Explanation: The underlined string is the pattern string 
// successfully matched. The first index where the pattern 
// has matched is 2. So result is 2.

#include<bits/stdc++.h>
 
using namespace std;
int kmpBrute(string String, string pattern) {
  int n = String.size(), m = pattern.size();
  for (int i = 0; i < n + 1 - m; i++) {
    int j = 0;
    while (j < m && String[i + j] == pattern[j])
      j++;
    if (j == m) return i;
  }
  return -1;
}
int main() {
  string pattern="aaaaaab", String="aaaaaaaamaaaaaab";

  int index = kmpBrute(String, pattern);
  if (index == -1) cout << "The pattern is not found";
  else cout << "The pattern " << pattern << " is found in the given string " 
  << String << " at " << index;
  return 0;
}
