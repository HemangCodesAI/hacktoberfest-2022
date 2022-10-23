// Problem Statement - Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// Explanation
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2

// C++ program to find the median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;

int Solution(int arr[], int n)
{

	// If length of array is even
	if (n % 2 == 0)
	{
	int z = n / 2;
	int e = arr[z];
	int q = arr[z - 1];
	int ans = (e + q) / 2;
	return ans;
	}
	
	// If length if array is odd
	else
	{
	int z = round(n / 2);
	return arr[z];
	}
}

// Driver Code
int main() {
	
		// TODO Auto-generated method stub
		int arr1[] = { -5, 3, 6, 12, 15 };
		int arr2[] = { -12, -10, -6, -3, 4, 10 };

		int i = sizeof(arr1) / sizeof(arr1[0]);
		int j = sizeof(arr2) / sizeof(arr2[0]);

		int arr3[i+j];
		int l = i+j;
		
    // Merge two array into one array
		for(int k=0;k<i;k++)
		{
			arr3[k]=arr1[k];
		}
		
		int a=0;
		for(int k=i;k<l;k++)
		{
			arr3[k]=arr2[a++];
		}

		// Sort the merged array
		sort(arr3,arr3+l);

		// calling the method
		cout<<"Median = " << Solution(arr3, l);
}
