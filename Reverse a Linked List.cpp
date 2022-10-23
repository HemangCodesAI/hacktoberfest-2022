// Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.
  
//   Input Format: 
// head = [3,6,8,10]
// This means the given linked list is 3->6->8->10 with head pointer at node 3.

// Result:
// Output = [10,6,8,3]
// This means, after reversal, the list should be 10->6->8->3 with the head pointer at node 10.

class Solution {
public:

    ListNode* reverseList(ListNode* head) {

       //step 1
        ListNode* prev_p = NULL;
        ListNode* current_p = head;
        ListNode* next_p;
       
       //step 2
        while(current_p) {

            next_p = current_p->next;
            current_p->next = prev_p;
            
            prev_p = current_p;
            current_p = next_p;
        }

        head = prev_p; //step 3
        return head;
    }
};
