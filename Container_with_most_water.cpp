// Problem Statement:  Given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]). Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

// Examples:

// Input: nums = [1,4,2,3]
// Output: 6
// Explanation: At i = 1 and i=3 heights are 4 and 3, therefore the maximum amount of water can be stored there. To calculate any amount of water between 2 vertical lines it is the horizontal distance between them multiplied by the minimum of those 2 lines. So in the best case, the max distance between i=1 and i=3 is 2, and the minimum of 4 and 3 is 3, so total water is 2*3=6.

// Example 2:
// Input: nums = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Here maximum water can be contained between i=1 and i=8

#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &nums)
{
    int mx = INT_MIN;
	for(int i = 0; i < nums.size(); i++){
		for(int j = i + 1; j < nums.size(); j++){
			int water = (j-i)*min(nums[i], nums[j]);
			mx = max(mx,water);
		}
	}
    return mx;
}

int main() {
    vector<int> nums {1, 4, 2, 3};
  
    cout << "Maximum amount of water is: " << maxArea(nums);
  
    return 0;
}
