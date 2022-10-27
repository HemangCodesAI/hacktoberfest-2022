// Problem Statement: 

// Remove brackets from an algebraic expression

// Write a program to remove brackets from an algebraic expression

// Given an algebraic expression, we need to simplify the expression and remove the brackets.

// Examples:

// Example 1:
// Input: “a+((b-c)+d)”
// Output: “a+b-c+d”
// Explanation: Removed all the brackets in the algebric expression.

// Example 2:
// Input: “(((a-b))+c)”
// Output: “a-b+c”
// Explanation: Removed all the brackets in the algebric expression.


#include <bits/stdc++.h>

using namespace std;


string solve(string input){
    string answer;
    for(int i=0;i<input.size();i++){
        if(input[i] != '(' && input[i] != ')')
            answer.push_back(input[i]);
    }
    return answer;
}


int main() {

  string input1 = "a+((b-c)+d)";
  string input2 = "(((a-b))+c)";
  
  
  cout<<"Original String: "<<input1<<endl;
  cout<<"After removing brackets: "<<solve(input1)<<endl;
  cout<<"Original String: "<<input2<<endl;
  cout<<"After removing brackets: "<<solve(input2)<<endl;
}
