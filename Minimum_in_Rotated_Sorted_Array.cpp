// Problem Statement: Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums[] = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// Examples:

// Example 1:
// Input: nums=[3,4,5,1,2]
// Output: 1
// Explanation: Original Array was rotated 3 times

// Example 2:
// Input: nums=[4,5,6,7,0,1,2]
// Output:0
// Explanation: Original Array was rotated 4 times

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
	int ar[5]={4,5,1,2,3};
	int minVal=INT_MAX,i;
	for(i=0;i<5;i++){
		minVal=min(minVal,ar[i]);
	}
	cout<<"Minimum Value is "<<minVal<<endl;
	return 0;
}
