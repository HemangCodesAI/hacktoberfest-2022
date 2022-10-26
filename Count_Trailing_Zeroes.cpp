// Problem Statement: “Given an integer n, return the number of trailing zeroes in n!.

// Note that n! = n * (n – 1) * (n – 2) * … * 3 * 2 * 1.”

// Examples:

// Example 1:
// Input: n = 3
// Output: 0
// Explanation: 3! = 6, no trailing zero.

// Example 2:

// Input: n = 5
// Output: 1
// Explanation: 5! = 120, one trailing zero.


#include<bits/stdc++.h>
 
using namespace std;
int factorial(int num) {
  if (num == 0) {
    return 1;
  }
  return num * factorial(num - 1);
}
int main() {
  int n = 10;
  int fact = factorial(n);
  int cnt = 0;
  while (fact % 10 == 0) {
    cnt++;
    fact /= 10;
  }
  cout <<"The trailing zeros are: "<< cnt << endl;
  return 0;
}
