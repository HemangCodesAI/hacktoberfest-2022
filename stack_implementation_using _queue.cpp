#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
// queue datastructure (stl) used to represent as a stack
  queue<int> q;

public:
  void push(int data);
  void pop();
  int top();
  bool isEmpty();
};

// push operation inserts a new element to the top of the stack (which is front of queue in this case)
void Stack :: push(int data){
  int n = q.size();
  q.push(data);
  for(int i = 0; i < n; i++)
  {
    q.push(q.front());
    q.pop();
  }
}


// pop operation removes the element that is at the front of the queue
void Stack :: pop(){
  if(isEmpty()) cout << "Stack is empty" << endl;
  else q.pop();
}

// top function return the element that is present at the the top of the stack (at the front of the queue) and returns -1 in case the stack is empty
int Stack :: top(){
  if(isEmpty()) return -1;
  return q.front();
}

// boolean function that returns whether the stack is empty or not
bool Stack :: isEmpty(){
  if(q.size() == 0) return true;
  return false;
}

int main(){
  Stack st;
  cout << st.isEmpty() << endl;
  st.pop();
  cout << st.top() << endl;
  st.push(2);
  st.push(3);
  st.push(6);
  st.push(1);
  st.push(4);
  st.pop();
  cout << st.top() << endl;
  return 0;
}
