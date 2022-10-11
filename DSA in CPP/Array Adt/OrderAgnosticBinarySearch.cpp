#include<iostream>
using namespace std;
// iterative binary search function
static int bsearch(int arr[],int key,int length){
        int start=0;
        int end=length-1;
        bool isasscending;
        // check the sorted order of given array
        if(arr[start]<arr[end])
            isasscending=true; // sorted in ascending order
        else
            isasscending=false; // sorted in descending order
        
        while(start <= end){
            int mid= start+(end-start)/2; // find the middle element
            if(arr[mid]==key) // check if key is present at middle
                return mid;
            // if array is sorted in ascending order
            if(isasscending){
                if(key<arr[mid]) // if key is smaller, ignore right half
                    end=mid-1;
                else // if key is greater, ignore left half
                    start=mid+1;
            }
            // if array is sorted in descending order
            else{
                if(key > arr[mid]) // if key is smaller, ignore right half
                    end=mid-1;
                else // if key is smaller, ignore left half
                    start=mid+1;
            }
        }
        // Key is not present
        return -1;
}
//Main function
int main(){
        int arr[]={1926,2756,3581,4386,5145};
        int key=4386;
        int len=sizeof(arr)/sizeof(arr[0]);
        cout<<bsearch(arr,key,len);
}
