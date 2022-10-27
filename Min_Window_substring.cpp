// Problem Statement: Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string. 

// Examples:

// Example 1:
// Input: s = "ADOBECODEBANC", t = "ABC" 
// Output: 4  
// Explanation: BANC has all required characters 

// Example 2:
// Input: s = "ABBXC", t = "BXC" 
// Output: 3 
// Explanation: BXC has all required characters 


#include<bits/stdc++.h>

#include<iostream>

using namespace std;
bool check(map < char, int > mpt, map < char, int > mps) {
  for (auto i: mpt) {
    if (mps.find(i.first) == mps.end()) return false;
    if (mps[i.first] < i.second) return false;
  }
  return true;
}
string makeString(int i, int j, string s) {
  string str = "";
  while (i <= j) {
    str += s[i];
    i++;
  }
  return str;
}
string minWindow(string s, string t) {
  map < char, int > mpt;
  map < char, int > mps;
  for (int i = 0; i < t.length(); i++) {
    mpt[t[i]]++;
  }
  int i = 0, j = 0;
  int ans = INT_MAX;
  string str = "";
  while (j < s.length()) {
    if (mpt.find(s[j]) != mpt.end()) {
      if (mps.size() == 0) i = j;
      mps[s[j]]++;
    }
    if (j - i + 1 >= t.length()) {
      bool f = check(mpt, mps);
      if (f) {
        mps.clear();
        if (ans > j - i + 1) {
          str = makeString(i, j, s);
          ans = j - i + 1;
        }
        j = i + 1;
        i = j;
        continue;
      }
    }
    j++;
  }
  return str;
}
int main() {
  string s = "adobecodebanc", t = "abc";
  cout << "The minimum window is: " << minWindow(s, t);
  return 0;
}
