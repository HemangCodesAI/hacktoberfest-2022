Question Statement-

You are given two 0-indexed arrays, nums1 and nums2, consisting of non-negative integers. There exists another array, nums3, 
which contains the bitwise XOR of all pairings of integers between nums1 and nums2 (every integer in nums1 is paired with every integer in nums2 exactly once).
Return the bitwise XOR of all integers in nums3.

Example 1:

Input: nums1 = [2,1,3], nums2 = [10,2,5,0]
Output: 13
Explanation:
A possible nums3 array is [8,0,7,2,11,3,4,1,9,1,6,3].
The bitwise XOR of all these numbers is 13, so we return 13.



Code:

#include<bits/stdc++.h>
 using namespace std;
  int xorAllNums(vector<int> &nums1, vector<int> &nums2)
        {
            int m=nums1.size();
            int n=nums2.size();
            int ans=0;
            int a=0;
                for(int i=0;i<m;i++)   
                   a^=nums1[i]  ;
                
            
            int b=0;
             for(int i=0;i<n;i++)
                 b^=nums2[i];
          
            
            ans=(m%2)*b xor (n%2)*a;
            
            cout<< ans;
          return 0;
        }
   int main()
 {
    int m,n;
    cin>>m>>n;
    vector<int>nums1(m);
    vector<int>nums2(n);
    
    for(int i=0;i<m;i++)
    {
        cin>>nums1[i];
    }
      for(int i=0;i<n;i++)
    {
        cin>>nums2[i];
    }
 
   xorAllNums(nums1,nums2);
  return 0;
  
 
   
 }
