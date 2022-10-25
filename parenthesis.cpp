// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//An input string is valid if:

//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.

//Example 1:
//Input: s = "()[{}]"
//Output: true

//Example 3:

//Input: s = "(]"
//Output: false

//Solution

#include<iostream>
#include<stack>
using namespace std;

bool pmatching(string s){
    stack<char> st;
    bool ans=true;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='{'|| s[i]=='['|| s[i]=='('){
            st.push(s[i]);
        }else if(!st.empty()&&s[i]==')'){
            if(st.top()=='('){
                st.pop();
            }
        }else if(!st.empty()&&s[i]=='}'){
            if(st.top()=='{'){
                st.pop();
            }
        }else if(!st.empty()&&s[i]==']'){
            if(st.top()=='['){
                st.pop();
            }
        }else{
            ans=false;
            break;
        }
    }
    if(!st.empty()){
        return false;
    }else return ans;


}
int main(){
    cout<<pmatching("{([]})");
    return 0;
}
