// Problem Statement: You need to try implementing 2 stacks in a single array.

// Example:

// push1(10): Insert 10 in stack1
// push2(21): Insert 21 in stack2
// pop2(): Pop top element from stack2
// Approaches

// To solve this problem, we can use 2 approaches. One is space efficient and one is not.

// Approach 1: Divide the array into two equal halves

// In this approach, we’ll divide the array into two equal halves. 

// One half would be assigned to stack1 and one half would be assigned to stack 2.

// The following diagram explains the above approach

#include <iostream>
using namespace std;

class twoStack {
  int * arr;
  int size;
  int top1;
  int top2;
  public:
    twoStack(int n) {
      arr = new int[n];
      size = n;
      top1 = n / 2 + 1;
      top2 = n / 2;
    }
  void pushStack1(int data) {
    if (top1 > 0) {
      top1--;
      arr[top1] = data;
      cout << "Element pushed" << "\n";
    } else {
      cout << "Stack Overflow" << "\n";
    }
  }
  void pushStack2(int data) {
    if (top2 < size - 1) {
      top2++;
      arr[top2] = data;
      cout << "Element pushed" << "\n";
    } else {
      cout << "Stack Overflow" << "\n";
    }
  }
  void popStack1() {
    if (top1 <= size / 2) {
      top1++;
      cout << "top element popped" << "\n";
    } else {
      cout << "Stack Underflow" << "\n";
    }
  }
  void popStack2() {
    if (top2 >= size / 2 + 1) {
      top2--;
      cout << "top element popped" << "\n";
    } else {
      cout << "Stack underflow" << "\n";
    }
  }
};
int main() {
  twoStack ts(5);
  ts.pushStack1(10);
  ts.pushStack1(22);
  ts.popStack1();
  ts.popStack2();
  ts.popStack1();
}
