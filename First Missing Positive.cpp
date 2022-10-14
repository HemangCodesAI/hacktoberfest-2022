/**  First Missing Positive
     Given an unsorted integer array nums, return the smallest missing positive integer in O(n) time and uses constant extra space .
**/
#include <iostream>
using namespace std;
    
    // swap function
    static void swap(int arr[],int i,int correct) {
        int temp=arr[i];
        arr[i]=arr[correct];
        arr[correct]=temp;
    } 
    
	static int firstMissingPositive(int nums[],int length) {
        int i=0;
        while(i<length){
            int correct=nums[i]-1;
            if(nums[i] > 0 && nums[i]<length && nums[i]!=nums[correct])
                swap(nums,i,correct);
            else
                i++;
        }
        for(int j=0;j<length;j++){
            if(nums[j]!=j+1)
                return j+1; // missing positive number
        }        
        return length+1; // edge case: when last number is missing
    }
    
    int main() {
		int nums[]={3,4,-1,1};
		int len=sizeof(nums)/sizeof(nums[0]);
		cout<<(firstMissingPositive(nums,len));
	}
	
// Time Complexity: O(n)
// Space Complexity: O(1)