// Given a string s, return the number of palindromic substrings in it. 
// A string is a palindrome when it reads the same backward as forward.
// A substring is a contiguous sequence of characters within the string.
// Example 1:
// Input: abc 
// Output: 3 
// Explanation: palindromic substrings are 'a', 'b' ,'c' 

// Example 2:
// Input: aaa 
// Output: 6 
// Explanation: palindromic substrings are 'a', 'a' ,'aa','aa','a','aaa'

#include<bits/stdc++.h>

using namespace std;
bool checkPal(int i, int j, string str) {

  while (i < j) {
    if (str[i] != str[j]) return false;
    i++;
    j--;
  }
  return true;
}

int countSubstrings(string s) {
  int n = s.length();
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int p = i; p < n; p++) {
      if (checkPal(i, p, s) == true) {
        sum++;
      }
    }
  }

  return sum;
}
int main() {
  string s = "aaa";
  cout << countSubstrings(s);
  return 0;
}
