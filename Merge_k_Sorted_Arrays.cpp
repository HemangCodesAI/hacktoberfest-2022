// Problem Statement: You are given an array of k linked-lists lists, each linked list is sorted in ascending order. You need to merge all the linked list into a single linked list and return it.

// Example:

// Example 1:
// Input: [[1, 4, 5], [1, 3, 4], [2, 6]]
// Output: [1, 1, 2, 3, 4, 4, 5, 6]
// Explanation: The linked-lists are:
// [
// 1 ⇾ 4 ⇾ 5,
// 1 ⇾ 3 ⇾ 4,
// 2 ⇾ 6
// ] 
 
// Merged Linked list will be
// 1  ⇾ 1 ⇾ 2  ⇾ 3  ⇾ 4  ⇾ 4  ⇾ 5  ⇾ 6

// Example 2: 
// Input: [[1, 2, 3], [4, 5, 6], [7 ,8, 9]]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
// Explanation: The linked-lists are:
// [
// 1 ⇾ 2  ⇾ 3,
// 4  ⇾ 5  ⇾ 6,
// 7  ⇾ 8  ⇾ 9
// ]
// Merged Linked list will be
// 1  ⇾ 2  ⇾ 3  ⇾ 4  ⇾ 5  ⇾ 6  ⇾ 7  ⇾ 8  ⇾ 9


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {

        // initialising result node
        ListNode* res = new ListNode(0);
        ListNode* tail = res;

        // if you had solved previous merge two sorted linked list
        // then this is easy to understand

        // here loop will execute until any of the list is not empty
        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            // tail has to be incremented after every iteration
            // that's why it is kept outside of the if else statement
            tail = tail->next;
        }

        // if any of list becomes empty then append that list to the tail of the resultant list

        if (list1 == NULL)
            tail->next = list2;
        else
            tail->next = list1;

        return res->next;
    }

    ListNode* mergeKLists(vector<ListNode*> &lists) {

        // initialising result node

        // creating the dummy node is the common technique
        // to avoid any edge cases
        ListNode* res = new ListNode(0);

        for (ListNode* list: lists) {
            res->next = merge(res->next, list);
        }

        return res->next;
    }

 
};
