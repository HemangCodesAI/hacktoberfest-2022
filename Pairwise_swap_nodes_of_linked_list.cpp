// Problem Statement: Given a singly linked list. Your task is to swap all the elements pairwise.

// Examples:

// Example 1:
// Input: Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL 

// Output: 2->1->4->3->6->5->NULL

// Explanation: While traversing the linked list every time 
// we encounter a pair we have to swap them. i.e pair(1,2) 
// is swapped with (2,1), pair(3,4) is swapped with (4,3), 
// and so on.

// Example 2:
// Input: Linked list: 1->2->3->4->5->NULL 

// Output: 2->1->4->3->5->NULL

// Explanation: While traversing the linked list every time 
// we encounter a pair we have to swap them. Here the last 
// element 5 at the end of the list does not have any pair 
// to swap it with, so it remains unchanged.

#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    int data;
  Node * next;
};

/* Function to pairwise swap elements */
void pairWiseSwap(Node * head) {
  Node * temp = head;

  /* Traverse further only if
  there are at-least two nodes left */
  while (temp != NULL && temp -> next != NULL) {
    /* Swap data of node with
       its next node's data */
    swap(temp -> data,
      temp -> next -> data);

    /* Move temp by 2 for the next pair */
    temp = temp -> next -> next;
  }
}

void push(Node ** head_ref, int new_data) {
  
  Node * new_node = new Node();
  
new_node -> data = new_data;

  new_node -> next = ( * head_ref);

  ( * head_ref) = new_node;
}

void printList(Node * node) {
  while (node != NULL) {
    cout << node -> data << " ";
    node = node -> next;
  }
}

int main() {
  Node * start = NULL;

  push( & start, 5);
  push( & start, 4);
  push( & start, 3);
  push( & start, 2);
  push( & start, 1);

  cout << "Linked list " << "before calling pairWiseSwap()\n";
  printList(start);

  pairWiseSwap(start);

  cout << "\nLinked list " <<
 "after calling pairWiseSwap()\n";
  printList(start);

  return 0;
}
