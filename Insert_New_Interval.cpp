// Problem Statement: You are given an array of non-overlapping intervals where intervals[i] = [start, end] represent the start and the end of the ith interval, and intervals is sorted in ascending order by start. You are also given an interval newInterval = [start, end] that represents the start and end of another interval. 

// Insert newInterval into intervals such that intervals are still sorted in ascending order by start and intervals still do not have any overlapping intervals (merge overlapping intervals if necessary). Return intervals after the insertion. 

// Examples:

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5] 
// Output: [[1,5],[6,9]] 
// Explanation: Intervals 1,3 and 2,5 can be merged to make 1,5. 

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8] 
// Output: [[1,2],[3,10],[12,16]] 
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& ni) {
int n = a.size();
vector<vector<int>> ans;
for(int i = 0;i<n;i++)
{
if(ni[1]<a[i][0]) //if interval to be merged is less than interval in array
{
ans.push_back(ni);
for(;i<n;i++)
{
ans.push_back(a[i]);
}
return ans;
}
else if(a[i][1] < ni[0]) //If current interval is before newInterval
ans.push_back(a[i]);
else
{
ni[0] = min(ni[0],a[i][0]);
ni[1] = max(ni[1],a[i][1]);
}
}
ans.push_back(ni);
return ans;
}

int main(){
vector<vector<int>>intervals;
intervals.push_back({1,3});
intervals.push_back({6,9});
vector<int>newInterval;
newInterval.push_back(2);
newInterval.push_back(5);
intervals = insert(intervals,newInterval);
for(int i=0;i<intervals.size();i++){
cout<<"["<<intervals[i][0]<<","<<intervals[i][1]<<"]"<<" ";
}
return 0;
}
