// Problem Statement: Given an array of numbers, you need to return the count of reverse pairs. 
// Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
  
// Example 1:

// Input: N = 5, array[] = {1,3,2,3,1)

// Output: 2 

// Explanation: The pairs are (3, 1) and (3, 1) as from both the pairs the condition arr[i] > 2*arr[j] is satisfied.

// Example 2:

// Input: N = 4, array[] = {3,2,1,4}

// Output: 1

// Explaination: There is only 1 pair  ( 3 , 1 ) that satisfy the condition arr[i] > 2*arr[j]
  
  #include<bits/stdc++.h>
using namespace std;
 int reversePairs(vector < int > & arr) {
      int Pairs = 0;
      for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
          if (arr[i] > 2 * arr[j]) Pairs++;
        }
      }
      return Pairs;
    }


int main()
{
    vector<int> arr{1,3,2,3,1};
    cout<<"The Total Reverse Pairs are "<<reversePairs(arr);
}
