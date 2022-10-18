// For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. The expression will only contain curly brackets.
// If the expression can't be balanced, return -1.

// Example:
// Expression: {{{{
// If we reverse the second and the fourth opening brackets, the whole expression will get balanced. Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

// Expression: {{{
// In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket and hence will not be able to make the expression balanced and the output will be -1.

// Input Format :
// The first and the only line of input contains a string expression, without any spaces in between.

// Output Format :
// The only line of output will print the number of reversals required to balance the whole expression. Prints -1, otherwise.

// Input:
// {{{{}}

// Output:
// 1

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string input) 
{
    if(input.size() % 2 != 0)
    {
        return -1;
    }
    stack<int> stk;
    
    for(int i=0; i<input.size(); i++)
    {
        if(input[i] == '{')
        {
            stk.push(input[i]);
        }
        else
        {
            if(!stk.empty() && stk.top() == '{')
            {
                stk.pop();
            }
            else
            {
                stk.push(input[i]);
            }
        }
    }
    
    int count = 0;
    while(!stk.empty())
    {
        char c1 = stk.top();
        stk.pop();
        char c2 = stk.top();
        stk.pop();
        
        if(c1 != c2)
        {
            count += 2;
        }
        else
        {
            count++;
        }
    }
    return count;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}