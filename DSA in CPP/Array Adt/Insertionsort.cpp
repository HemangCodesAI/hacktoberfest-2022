#include<iostream>
using namespace std;

void Insertionsort( int arr[] , int n )
{
    for(int i=1 ; i<n ; i++){
        int temp = arr[i];
        int j =i-1;
        for(; j>=0 ; j--){
            if(arr[j]>temp){
                //shift
                arr[j+1] = arr[j];
            }
            else {
                break ; 
            }

        }
        arr[j+1] = temp;
    }
}
void printArray( int arr[] , int n){
    for(int i =0 ; i <n; i++)
    {cout<<arr[i]<<" ";
    }
}
int main (){
    int arr[] = {3,7,2,44,89,23,90,43};
    int n = sizeof(arr)/sizeof(arr[0]);
    Insertionsort(arr , n);
    cout <<"Sorted array: \n";
	printArray(arr, n);
	return 0;
}
