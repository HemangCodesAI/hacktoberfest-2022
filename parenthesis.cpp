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
