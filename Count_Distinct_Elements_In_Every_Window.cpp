// Problem Statement:

// “Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.”

// Examples:

// Example 1:
// Input: 
// K=4,
// array[] = {1,2,1,3,4,2,3}
// Output: 3  4  3  3
// Explanation:
// First window is {1, 2, 1, 3}, count of distinct numbers is 3
// Second window is {2, 1, 3, 4} count of distinct numbers is 4
// Third window is {1, 3, 4, 2} count of distinct numbers is 4
// Fourth window is {3, 4, 2, 3} count of distinct numbers is 3


// Example 2:
// Input: 
// K=3
// array[]={2,3,1,4,2}
// Output:  3 3 3
// Explanation:
// First window is {2,3,1}, count of distinct numbers is 3
// Second window is {3,1,4} count of distinct numbers is 3
// Third window is {1,4,2} count of distinct numbers is 3


#include <bits/stdc++.h>
using namespace std;


int windows(int arr[], int k)
{
    int count = 0;

    for (int i = 0; i < k; i++) {
       
        int j;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;
        if (j == i)
            count++;
    }
    return count;
}


void countDistinct(int arr[], int n, int k)
{
   
    for (int i = 0; i <= n - k; i++)
        cout << windows(arr + i, k) << " ";
}


int main()
{
    int arr[] = { 1, 2, 1, 3, 4, 2, 3 }, k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    countDistinct(arr, n, k);
    return 0;
}
