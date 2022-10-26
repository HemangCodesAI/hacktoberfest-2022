// Problem Statement: Given an array of intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Examples:

// Example 1:
// Input: intervals = [[1,2],[2,3],[3,4],[1,3]] 
// Output: 1 
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping. 

// Example 2:
// Input: intervals = [[1,2],[1,2],[1,2]] 
// Output: 2 
// Explanation: remove two [1,2] to make the rest of the intervals non-overlapping. 

#include<iostream> 
#include<bits/stdc++.h> 
using namespace std; 
//comparator function for sorting based on endpoints 
bool cmp(vector<int>& a, vector<int>& b) {return a[1] < b[1];} 
 
int eraseOverlapIntervals(vector<vector<int>>& intervals) { 
 sort(intervals.begin(), intervals.end(),cmp); 
  
 int ans=0; 
 int start=intervals[0][0],end = intervals[0][1]; 
 for(int i=1;i<intervals.size();i++){ 
 if(intervals[i][0] < end){ 
 ans++; 
 } 
 else if(intervals[i][0] >= end){  
 start=intervals[i][0]; 
 end=intervals[i][1]; 
 } 
 } 
 return ans; 
 } 
int main(){ 
vector<vector<int>>intervals; 
intervals.push_back({1,100}); 
intervals.push_back({1,11}); 
intervals.push_back({11,22}); 
intervals.push_back({2,12}); 
cout<<eraseOverlapIntervals(intervals); 
return 0; 
} 
