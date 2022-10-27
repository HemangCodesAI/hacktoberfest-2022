// Given a postfix expression Containing only operators [+, – , *, / ]  and numbers. Postfix expression is given the form of a vector of strings. Each element is either operator or operand in postfix expression. Concatenating these strings gives the postfix expression. Evaluate the postfix expression and return the corresponding value of the expression.

// NOTE:  Division between two integers should truncate toward zero.

// Example:

// Example 1: 
// Input: [“ 1 ”, ” 3 ”,” - ”,” 4 ”, “ * ” ] 
// Output: -8
// Explanation: The Arthematic Expression Corresponding to postfix is (1-3)*4 which is equal to -8.

// Example 2: 
// Input: [“ 4 ”, ” 3 ”,” 15 ”,” / ”, “ - ” ] 
// Output: 4 
// Explanation: The Arthematic Expression Corresponding to postfix is( 4 + (3/15)) which is equal to 4.


#include <bits/stdc++.h>

using namespace std;

int EvalutePostfix(vector < string > & postfix) {
  stack < int > st;
  for (auto & token: postfix) {
    if (token == "+" || token == "-" || token == "*" || token == "/") {
      int first = st.top();
      st.pop();
      int second = st.top();
      st.pop();
      if (token == "+")
        st.push(first + second);
      else if (token == "-")
        st.push(second - first);
      else if (token == "*")
        st.push(first * second);
      else
        st.push(second / first);
    } else
      st.push(stoi(token));
  }
  return st.top();
}

int main() {
  vector < string > postfix = {"1","3","-","4","*"};
  int value = EvalutePostfix(postfix);
  cout << value << endl;
}
