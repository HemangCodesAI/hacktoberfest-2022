// Problem Statement: You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’ of sizes N and M respectively. Find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from ‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation. Maximum XOR of Two Numbers in an Array.
  
//  Example 1:

// Input: N=2, M=3
//        arr1 = [6, 8] 
//        arr2 = [7, 8, 2]

// Output: 15

// Explanation: Possible pairs are (6, 7), (6, 8), (6, 2), (8, 7), (8, 8), (6, 2). And 8 xor 7 will give the maximum result i.e. 15

// Example 2:

// Input: N=2, M=2
//        arr1 = [1, 2
// ]
//        arr2 = [1, 1]

// Output: 3

// Explanation: 3 is the maximum possible xor among all possible pairs.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
int maxXOR(int n, int m, vector < int > & arr1, vector < int > & arr2) {
  Trie trie;
  for (int i = 0; i < n; i++) {
    trie.insert(arr1[i]);
  }
  int maxi = 0;
  for (int i = 0; i < m; i++) {
    maxi = max(maxi, trie.findMax(arr2[i]));
  }
  return maxi;
}
int main() {
  vector < int > arr1 = {6, 8};
  vector < int > arr2 = {7, 8, 2};
  int n = 2, m = 3;
  cout << maxXOR(n, m, arr1, arr2) << endl;
  return 0;
}
