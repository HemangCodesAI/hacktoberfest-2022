// Problem Statement: Given a string, find the leftmost repeating character of the string. i.e The first character that appeared again in the further string.

// Examples:

// Example 1:
// Input: takeUforward
// Output: a
// Explanation: Character ‘a’ is the left-most repeating character or the first repeating character.

// Example 2:

// Input: programming
// Output: r
// Explanation: Character ‘r’ is the left-most repeating character or the first repeating character.

#include <bits/stdc++.h>

using namespace std;
int main() {
  string str = "takeUforward";
  int flag = 0;
  for (int i = 0; i < str.size(); i++) {
    for (int j = i + 1; j < str.size(); j++) {
      if (str[i] == str[j]) {
        cout << "The left-most repeating character is :" << " " << str[i];
        flag = 1;
        break;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  return 0;
}
