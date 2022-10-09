#include<iostream>
using namespace std;

static int bsearch(int arr[],int key,int length){
        int start=0;
        int end = length-1;
        // int end=arr.length-1;
        bool isasscending;
        if(arr[start]<arr[end])
            isasscending=true;
        else
            isasscending=false;
        
        while(start <= end){
            int mid= start+(end-start)/2;
            if(arr[mid]==key)
                return mid;
            if(isasscending){
                if(key<arr[mid])
                    end=mid-1;
                else
                    start=mid+1;
            }
            else{
                if(key > arr[mid])
                    end=mid-1;
                else
                    start=mid+1;
            }
        }
        return -1;
}
int main(){
        int arr[]={1926,2756,3581,4386,5145};
        int key=4386;
        int len=sizeof(arr)/sizeof(arr[0]);
        cout<<bsearch(arr,key,len);
}
